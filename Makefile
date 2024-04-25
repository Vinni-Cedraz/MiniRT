### CODAM BUILD
LIBMLX = libmlx42.a
MLXSRC = https://github.com/codam-coding-college/MLX42.git
BUILD_DIR_MLX = $(MLXDIR)/build
MLX_INCLUDE = ./MLX42/include/MLX42/
LIBMLX_TARGET = $(BUILD_DIR_MLX)/$(LIBMLX)
LIBX_FLAGS = -lmlx -lXext -lX11 -lm -lz
MLXDIR = ./MLX42
CODAM_LIB_FLAGS = -L./MLX42/build/ -lmlx42 -ldl -lglfw -pthread -lm


### LIBFT
LIBFT = ./libs/*.a
LIB_OBJS = $(wildcard libs/objs/*.o)
LIB_BOBJS = $(wildcard libs/objs_bonus/*.o)
LIB := minirt.a
BLIB := minirt_bonus.a


#### MANDATORY RULES ####

NAME = minirt

SRC = minirt.c \
	  basic_tuple_operations.c compare_floats.c \
	  complex_tuple_operations.c create_tuples.c mult_matrices.c comparison.c \
	  transpose_matrix.c determinants.c minors.c submatrices.c chain_transformations.c \
      invert_matrix.c create_matrix.c translation.c rotation.c scaling.c intersect_shape.c \
      get_hit.c create_and_transform_rays.c intersection_coordinates.c colors.c \
	  set_transform.c surface_normals.c reflect.c create_material.c calculate_lighting.c \
	  create_world.c intersect_world_with_ray.c prepare_computations.c shade_hit.c \
	  color_at.c view_transformation.c create_camera.c ray_for_pixel.c render.c intersect_sphere.c \
	  intersect_plane.c intersect_cylinder.c create_plane.c create_cylinder.c cylinder_setters.c \
	  shadows.c render_image.c endwith.c parse_ambient_and_light.c parse_camera.c parse_plane.c parse_utils.c \
	  parse_cylinder.c parse_sphere.c parse_functions_table.c parse_tokens_into_world.c caps.c \
	  check_type_identifiers.c file_validation.c open_file.c validate_line.c tokenizer.c create_sphere.c \
	  multiply_tuple_by_matrix.c

VPATH = ./src ./src/math/canvas/ ./src/math/tuples/ ./src/math/matrices \
		./src/math/matrix_transformations ./src/math/rays ./src/math/sphere \
		./src/math/rays/ ./src/math/light_and_shading/ ./src/math/making_scene/ \
		./src/math/camera/ ./src/math/cylinder/ ./src/math/plane/ ./src/math/create_intersection/ \
		./src/render ./src/input_validation ./src/parser ./src/tokenizer/ ./src/math/shape/

#### BONUS RULES ####
BNAME = minirt_bonus

BSRC = minirt_bonus.c basic_tuple_operations_bonus.c compare_floats_bonus.c \
		complex_tuple_operations_bonus.c create_tuples_bonus.c mult_matrices_bonus.c \
		comparison_bonus.c transpose_matrix_bonus.c determinants_bonus.c minors_bonus.c \
		submatrices_bonus.c chain_transformations_bonus.c invert_matrix_bonus.c \
		create_matrix_bonus.c translation_bonus.c rotation_bonus.c scaling_bonus.c \
		intersect_shape_bonus.c get_hit_bonus.c create_and_transform_rays_bonus.c \
		intersection_coordinates_bonus.c colors_bonus.c set_transform_bonus.c \
		surface_normals_bonus.c reflect_bonus.c create_material_bonus.c \
		calculate_lighting_bonus.c intersect_world_with_ray_bonus.c prepare_computations_bonus.c \
		shade_hit_bonus.c color_at_bonus.c view_transformation_bonus.c create_camera_bonus.c \
		ray_for_pixel_bonus.c render_bonus.c intersect_sphere_bonus.c \
		intersect_plane_bonus.c intersect_cylinder_bonus.c create_plane_bonus.c \
		create_cylinder_bonus.c cylinder_setters_bonus.c shadows_bonus.c \
		render_image_bonus.c endwith_bonus.c parse_ambient_and_light_bonus.c \
		parse_camera_bonus.c parse_plane_bonus.c parse_utils_bonus.c \
		parse_cylinder_bonus.c parse_sphere_bonus.c parse_functions_table_bonus.c \
		parse_tokens_into_world_bonus.c caps_bonus.c check_type_identifiers_bonus.c \
		file_validation_bonus.c open_file_bonus.c validate_line_bonus.c \
		tokenizer_bonus.c create_sphere_bonus.c multiply_tuple_by_matrix_bonus.c

VPATH += ./bsrc ./bsrc/math/canvas/ ./bsrc/math/tuples/ ./bsrc/math/matrices \
		./bsrc/math/matrix_transformations ./bsrc/math/rays ./bsrc/math/sphere \
		./bsrc/math/rays/ ./bsrc/math/light_and_shading/ \
		./bsrc/math/camera/ ./bsrc/math/cylinder/ ./bsrc/math/plane/ \
		./bsrc/math/create_intersection/ ./bsrc/render ./bsrc/input_validation \
		./bsrc/parser ./bsrc/tokenizer/ ./bsrc/math/shape/

BUILD_SRC = ./build/
INCLUDE = -I./include -I ./libs/
B_INCLUDE = -I./include_bonus -I./libs/
C_FLAGS = -Wall -Werror -Wextra -g
BUILD_DIR_RT= ./build/
B_BUILD_DIR_RT= ./build_bonus/
OBJS = $(addprefix $(BUILD_DIR_RT),$(SRC:.c=.o))
BOBJS = $(addprefix $(B_BUILD_DIR_RT),$(BSRC:.c=.o))

### RECIPES
all: $(NAME)

bonus: $(BNAME)

$(NAME): $(LIBMLX_TARGET) $(OBJS)
	@printf "$(GREEN)[ Build ]$(DEF_COLOR) $(RED) $@ $(GREEN)complete $(DEF_COLOR)"
	@$(CC) $(C_FLAGS) $(OBJS) $(INCLUDE) -I$(MLX_INCLUDE) $(CODAM_LIB_FLAGS) -L ./libs/ -lft -o $@
	@compiledb make as_lib --no-print-directory

$(BNAME): $(LIBMLX_TARGET) $(BOBJS)
	@printf "$(GREEN)[ Build ]$(DEF_COLOR) $(RED) $@ $(GREEN)complete $(DEF_COLOR)"
	@$(CC) $(C_FLAGS) $(BOBJS) $(B_INCLUDE) -I$(MLX_INCLUDE) $(CODAM_LIB_FLAGS) -L ./libs/ -lft -o $@
	@compiledb make as_lib_bonus --no-print-directory

$(BUILD_DIR_RT)%.o: %.c $(LIBFT)
	@test -d $(BUILD_DIR_RT) || mkdir $(BUILD_DIR_RT)
	$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $@

$(B_BUILD_DIR_RT)%.o: %.c $(LIBFT)
	@test -d $(B_BUILD_DIR_RT) || mkdir $(B_BUILD_DIR_RT)
	$(CC) $(C_FLAGS) $(B_INCLUDE) -c $< -o $@

$(LIBFT):
	make --no-print-directory -C ./libs && make bonus --no-print-directory -C ./libs

$(LIBMLX_TARGET): $(MLXDIR)
	cd $(MLXDIR) && cmake --build build -j4;

$(MLXDIR):
	git clone $(MLXSRC) $(MLXDIR);
	cd $(MLXDIR) && cmake -B build

mlxclean:
	@echo "Cleaning MLX42..."
	@rm -rf $(MLXDIR)

clean:
	@echo "Cleaning..."
	@make clean --no-print-directory -C libs/
	rm -rf $(BUILD_DIR_RT)
	rm -rf $(B_BUILD_DIR_RT)

fclean: clean
	@echo "Fully Cleaning..."
	@make fclean --no-print-directory -C ./libs/
	@make clean --no-print-directory -C ./tests
	@rm -rf MLX42/
	@rm -f $(BNAME) $(NAME) $(LIB) $(BLIB)

makelib:
	@make --no-print-directory -C libs/

$(LIB): $(OBJS) $(LIB_OBJS) $(LIB_BOBJS)
	@printf "\n$(YELLOW)[ linking ] $(DEF_COLOR)objects into library $(YELLOW)$@ $(DEF_COLOR)\n"
	@mv $(LIBMLX_TARGET) $(LIB)
	@ar rcs $(LIB) $^

$(BLIB): $(BOBJS) $(LIB_OBJS) $(LIB_BOBJS)
	@printf "\n$(YELLOW)[ linking ] $(DEF_COLOR)objects into library $(YELLOW)$@ $(DEF_COLOR)\n"
	@mv $(LIBMLX_TARGET) $(BLIB)
	@ar rcs $(BLIB) $^

as_lib: all makelib $(LIB)
as_lib_bonus: bonus makelib $(BLIB)
re: fclean all

# COLORS
GRAY = \033[0;37m
RED = \033[0;91m
BLUE = \033[0;94m
CYAN = \033[0;96m
GREEN = \033[0;92m
WHITE = \033[0;97m
YELLOW = \033[0;93m
MAGENTA = \033[0;95m
DEF_COLOR = \033[0;39m

.PHONY: all clean fclean re mlxclean
