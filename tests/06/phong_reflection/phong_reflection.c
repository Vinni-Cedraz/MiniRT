#include "tester.h"

#define SQRT_2by2 -0.7071
#define negSQRT_2by2 -0.7071
// Scenario : A point light has a position and intensity
#define scenario1                                                                        \
    CYAN "\n"                                                                            \
         "Given intensity ← color(1, 1, 1)\n"                                          \
         "And position ← point(0, 0, 0)\n"                                             \
         "When light ← create_point_light(position, intensity)\n"                      \
         "Then light.position = position\n"                                              \
         "And light.intensity = intensity" RESET

Test(phong_reflection, t_point_light_exists, .description = scenario1) {
    const t_point_light light = {
        .intensity = {1, 1, 1, COLOR},
        .position = {0, 0, 0, POINT},
    };
    cr_expect_tuples_eq(light.position, (t_tuple){0, 0, 0, POINT});
    cr_expect_tuples_eq(light.intensity, (t_tuple){1, 1, 1, COLOR});
}

// Scenario : The default material
#define scenario2                                                                        \
    CYAN "\n"                                                                            \
         "Given m ← create_material()\n"                                                      \
         "Then m.color = color(1, 1, 1)\n"                                               \
         "And m.ambient = 0.1\n"                                                         \
         "And m.diffuse = 0.9\n"                                                         \
         "And m.specular = 0.9\n"                                                        \
         "And m.shininess = 200.0" RESET

Test(phong_reflection, the_default_material, .description = scenario2) {
    t_material m = create_material();
    cr_expect_eq(doubles_eq(m.diffuse, 0.9), TRUE);
    cr_expect_eq(doubles_eq(m.ambient, 0.1), TRUE);
    cr_expect_eq(doubles_eq(m.specular, 0.9), TRUE);
    cr_expect_eq(doubles_eq(m.shininess, 200.0), TRUE);
    cr_expect_tuples_eq(m.color, (t_tuple){1, 1, 1, COLOR});
}

// Scenario : A sphere has a default material
#define scenario3                                                                        \
    CYAN "\n"                                                                            \
         "Given s ← sphere()\n"                                                        \
         "When m ← s.material\n"                                                       \
         "Then m = material()" RESET
Test(phong_reflection, a_sphere_is_created_with_a_default_material_in_it,
     .description = scenario3) {
    const t_sphere s = create_sphere();
    const t_tuple default_color = {1, 1, 1, COLOR};
    cr_expect_eq(doubles_eq(s.material.ambient, 0.1), TRUE);
    cr_expect_eq(doubles_eq(s.material.diffuse, 0.9), TRUE);
    cr_expect_eq(doubles_eq(s.material.specular, 0.9), TRUE);
    cr_expect_eq(doubles_eq(s.material.shininess, 200.0), TRUE);
    cr_expect_tuples_eq(s.material.color, default_color);
}

// Scenario : Lighting with the eye between the light and the surface
#define scenario4                                                                        \
    CYAN "\n"                                                                            \
         "Given m ← material()\n"                                                      \
         "And position ← point(0, 0, 0)\n"                                             \
         "Given eye_vec ← vector(0, 0, -1)\n"                                          \
         "And normal_vec ← vector(0, 0, -1)\n"                                         \
         "And light ← point_light(point(0, 0, -10), color(1, 1, 1))\n"                 \
         "When result ← lighting(m, light, position, eye_vec, normal_vec)\n"           \
         "Then result = color(1.9, 1.9, 1.9)" RESET
Test(phong_reflection, lighting_with_eye_between_light_and_surface, .description = scenario4) {
	t_tuple				result;
    const t_tuple 		expected_result = {1.9, 1.9, 1.9, COLOR};
    const t_lighting 	lighting_obj = {
        .material = create_material(),
        .position = {0, 0, 0, POINT},
        .eye_vec = {0, 0, -1, VECTOR},
        .normal_vec = {0, 0, -1, VECTOR},
        .light =
		 (t_point_light) {
			.position = {0, 0, -10, POINT},
            .intensity = {1, 1, 1, COLOR}}
	};

    calculate_lighting(&lighting_obj, result);
    cr_expect_tuples_eq(result, expected_result);
}

// Scenario : Lighting with the eye between light and surface, eye offset 45°
#define scenario5 \
    CYAN "\n" \
		 "Given eye_vec ← vector(0, √2/2, -√2/2)\n"										\
         "And normal_vec ← vector(0, 0, -1)\n" \
         "And light ← point_light(point(0, 0, -10), color(1, 1, 1))\n" \
         "When result ← lighting(m, light, position, eye_vec, normal_vec)\n" \
		 "Then result = color(1.0, 1.0, 1.0)" RESET
Test(phong_reflection, lighting_with_eye_between_light_and_surface_offset_45, .description = scenario5) {
	t_tuple result;
	const t_tuple expected_result = {1.0, 1.0, 1.0, COLOR};
	const t_lighting lighting_obj = {
		.material = create_material(),
		.position = {0, 0, 0, POINT},
		.eye_vec = {0, SQRT_2by2, negSQRT_2by2, VECTOR},
		.normal_vec = {0, 0, -1, VECTOR},
		.light = (t_point_light) {
			.intensity = {1, 1, 1, COLOR},
			.position = {0, 0, -10, POINT}
	}};

	calculate_lighting(&lighting_obj, result);
	cr_expect_tuples_eq(result, expected_result);
}

// Scenario : Lighting with eye opposite surface, light offset 45°
#define scenario6 \
    CYAN "\n" \
         "Given eye_vec ← vector(0, 0, -1)\n" \
         "And normal_vec ← vector(0, 0, -1)\n" \
         "And light ← point_light(point(0, 10, -10), color(1, 1, 1))\n" \
         "When result ← lighting(m, light, position, eye_vec, normal_vec)\n" \
		 "Then result = color(0.7364, 0.7364, 0.7364)" RESET
Test(phong_reflection, lighting_with_eye_opposite_surface_light_offset_45, .description = scenario6) {
	t_tuple 			result;
	const t_tuple 		expected_result = {
		0.7364, 0.7364, 0.7364, COLOR
	};
	const t_lighting 	lighting_obj = {
		.material = create_material(),
		.position = {0, 0, 0, POINT},
		.eye_vec = {0, 0, -1, VECTOR},
		.normal_vec = {0, 0, -1, VECTOR},
		.light = (t_point_light){
			.position ={0, 10, -10, POINT},
			.intensity = {1, 1, 1, COLOR}
	}};

	calculate_lighting(&lighting_obj, result);
	cr_expect_tuples_eq(result, expected_result);
}

// Scenario : Lighting with eye in the path of the reflection vector
#define scenario7 \
    CYAN "\n" \
         "Given eye_vec ← vector(0, -√2/2, -√2/2)\n" \
         "And normal_vec ← vector(0, 0, -1)\n" \
         "And light ← point_light(point(0, 10, -10), color(1, 1, 1))\n" \
         "When result ← lighting(m, light, position, eye_vec, normal_vec)\n" \
		 "Then result = color(1.6364, 1.6364, 1.6364)" RESET
Test(phong_reflection, lighting_with_eye_in_the_path_of_reflection_vector, .description = scenario7) {
	t_tuple result;
	const t_tuple expected_result = {1.6346, 1.6346, 1.6346, COLOR};
	const t_lighting lighting_obj = {
		.material = create_material(),
		.position = {0, 0, 0, POINT},
		.eye_vec = {0, negSQRT_2by2, negSQRT_2by2, VECTOR},
		.normal_vec = {0, 0, -1, VECTOR},
		.light = (t_point_light){
			.position = {0, 10, -10, POINT},
			.intensity = {1, 1, 1, COLOR}
	}};

	calculate_lighting(&lighting_obj, result);
	print_tuple(result);
	cr_expect_tuples_eq(result, expected_result);
}

// Scenario : Lighting with the light behind the surface
#define scenario8 \
    CYAN "\n" \
         "Given eye_vec ← vector(0, 0, -1)\n" \
         "And normal_vec ← vector(0, 0, -1)\n" \
         "And light ← point_light(point(0, 0, 10), color(1, 1, 1))\n" \
         "When result ← lighting(m, light, position, eye_vec, normal_vec)\n" \
		 "Then result = color(0.1, 0.1, 0.1)" RESET
Test(phong_reflection, lighting_with_light_behind_surface, .description = scenario8) {
	t_tuple result;
	const t_tuple expected_result = {
		0.1, 0.1, 0.1, COLOR
	};
	t_lighting lighting_obj = {
		.material = create_material(),
		.position = {0, 0, 0, POINT},
		.eye_vec = {0, 0, -1, VECTOR},
		.normal_vec = {0, 0, -1, VECTOR},
		.light = (t_point_light) {
			.position = {0, 0, 10, POINT},
			.intensity = {1, 1, 1, COLOR}
	}};

	calculate_lighting(&lighting_obj, result);
	cr_expect_tuples_eq(result, expected_result);
}
