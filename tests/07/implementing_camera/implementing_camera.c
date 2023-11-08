#include "tester.h"

//Scenario : Constructing a camera
#define scenario1 CYAN \
"Given hsize ← 160 \\n"                            \
"And vsize ← 120\n"                                \
"And field_of_view ← π/2\n"                        \
"When c ← camera(hsize, vsize, field_of_view)\n"   \
"Then c.hsize = 160\n"                             \
"And c.vsize = 120\n"                              \
"And c.field_of_view = π/2\n"                      \
"And c.transform = identity_matrix\n"RESET

