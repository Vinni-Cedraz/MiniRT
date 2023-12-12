#include "tester.h"

// Scenario: Lighting with the surface in shadow
#define scenario1 CYAN \
"And position ← point(0, 0, 0)\n"                                                      \
"Given m ← material()\n"                                                     		   \
"Given eyev ← vector(0, 0, -1)\n"                                                      \
"And normalv ← vector(0, 0, -1)\n"                                                     \
"And light ← point_light(point(0, 0, -10), color(1, 1, 1))\n"                          \
"And in_shadow ← true\n"                                                      		   \
"When result ← lighting(m, light, position, eyev, normalv, in_shadow)\n"               \
"Then result = color(0.1, 0.1, 0.1)"RESET

Test(lighting, surface_in_shadow, .description = scenario1) {

}
