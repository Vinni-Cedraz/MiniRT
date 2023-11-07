#include "tester.h"
// Scenario : The transformation matrix for the default orientation
#define scenario1 CYAN \
"Given from ← point(0, 0, 0) \n" \
"And to ← point(0, 0, -1) \n" \
"And up ← vector(0, 1, 0) \n" \
"When t ← view_transform(from, to, up) \n" \
"Then t = identity_matrix RESET\n"

// Scenario : A view transformation matrix looking in positive z direction
#define scenario2 CYAN \
"Given from ← point(0, 0, 0)\n"           \
"And to ← point(0, 0, 1)\n"               \
"And up ← vector(0, 1, 0)\n"              \
"When t ← view_transform(from, to, up)\n" \
"Then t = scaling(-1, 1, -1)\n"RESET

// Scenario : The view transformation moves the world
#define scenario3 CYAN \
"Given from ← point(0, 0, 8)\n"                \
"And to ← point(0, 0, 0)\n"                    \
"And up ← vector(0, 1, 0)\n"                   \
"When t ← view_transform(from, to, up)\n"      \
"Then t = translation(0, 0, -8)\n"RESET

// Scenario : An arbitrary view transformation
#define scenario4 CYAN \
"Given from ← point(1, 3, 2)\n"                              \
"And to ← point(4, -2, 8)\n"                                 \
"And up ← vector(1, 1, 0)\n"                                 \
"When t ← view_transform(from, to, up)\n"                    \
"Then t is the following 4x4 matrix:\n"                      \
"| -0.50709 | 0.50709 | 0.67612  | -2.36643 |\n"             \
"| 0.76772  | 0.60609 | 0.12122  | -2.82843 |\n"			 \
"| -0.35857 | 0.59761 | -0.71714 | 0.00000  |\n"    		 \
"| 0.00000  | 0.00000 | 0.00000  | 1.00000  |\n"RESET
