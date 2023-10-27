#include "tester.h"

// Scenario : Creating a world
#define scenario1 CYAN \
"\nGiven w ← world()\n" \
"Then w contains no objects\n"    \
"And w has no light source"RESET

// Scenario : The default world
#define scenario2 CYAN \
"\nGiven light ← point_light(point(-10, 10, -10), color(1, 1, 1))\n" \
"And s1 ← sphere() with:\n"                                          \
"material.color == (0.8, 1.0, 0.6)\n"                               \
"material.diffuse == 0.7\n"                                         \
"material.specular == 0.2\n"                                        \
"And s2 ← sphere() with:\n"                                          \
"transform <- scaling(0.5, 0.5, 0.5) |\n"                           \
"When w ← default_world()\n"                                         \
"Then w.light = light\n"                                         	 \
"And w contains s1\n"                                         		 \
"And w contains s2"RESET

// Scenario : Intersect a world with a ray
#define scenario3 CYAN \
"\nGiven w ← default_world()\n"                                      \
"And r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                    \
"When xs ← intersect_world(w, r)\n"                                  \
"Then xs.count = 4\n"                                        		 \
"And xs[0].t = 4\n"                                      			 \
"And xs[1].t = 4.5\n"                                      			 \
"And xs[2].t = 5.5\n"                                      			 \
"And xs[3].t = 6"RESET

// Scenario : Precomputing the state of an intersection
#define scenario4 CYAN\
"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                \
"And shape ← sphere()\n"                							 \
"And i ← intersection(4, shape)\n"                					 \
"When comps ← prepare_computations(i, r)\n"                			 \
"Then comps.t = i.t\n"                								 \
"And comps.object = i.object\n"                						 \
"And comps.point = point(0, 0, -1)\n"                				 \
"And comps.eyev = vector(0, 0, -1)\n"                				 \
"And comps.normalv = vector(0, 0, -1)"RESET

// Scenario : The hit, when an intersection occurs on the outside
#define scenario5 CYAN\
"\nGiven r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                \
"And shape ← sphere()\n"                							 \
"And i ← intersection(4, shape)\n"                					 \
"When comps ← prepare_computations(i, r)\n"                			 \
"Then comps.inside = false"RESET

// Scenario : The hit, when an intersection occurs on the inside
#define scenario6 CYAN\
"\nGiven r ← ray(point(0, 0, 0), vector(0, 0, 1))\n"                  \
"And shape ← sphere()\n"                  							  \
"And i ← intersection(1, shape)\n"                  				  \
"When comps ← prepare_computations(i, r)\n"                  		  \
"Then comps.point = point(0, 0, 1)\n"                  				  \
"And comps.eyev = vector(0, 0, -1)\n"                  				  \
"And comps.inside = true\n"                  						  \
"// normal would have been (0, 0, 1), but is inverted!\n"             \
"And comps.normalv = vector(0, 0, -1)"RESET

// Scenario : Shading an intersection
#define scenario7 CYAN\
"\nGiven w ← default_world()\n                                        \
"And r ← ray(point(0, 0, -5), vector(0, 0, 1))\n                      \
"And shape ← the first object in wAnd i ← intersection(4, shape)\n    \
"When comps ← prepare_computations(i, r)\n                            \
"And c ← shade_hit(w, comps)\n                                        \
"Then c = color(0.38066, 0.47583, 0.2855)"RESET

// Scenario : Shading an intersection from the inside
#define scenario8 CYAN\
"\nGiven w ← default_world()\n"                                       \
"And w.light ← point_light(point(0, 0.25, 0), color(1, 1, 1))\n"      \
"And r ← ray(point(0, 0, 0), vector(0, 0, 1))\n"                      \
"And shape ← the second object in w\n"                                \
"And i ← intersection(0.5, shape)\n"                                  \
"When comps ← prepare_computations(i, r)\n"                           \
"And c ← shade_hit(w, comps)\n"                                       \
"Then c = color(0.90498, 0.90498, 0.90498)"RESET

// Scenario : The color when a ray misses
#define scenario9 CYAN\
"\nGiven w ← default_world()\n"                                       \
"And r ← ray(point(0, 0, -5), vector(0, 1, 0))\n"                     \
"When c ← color_at(w, r)\n"                                       	  \
"Then c = color(0, 0, 0)"RESET

// Scenario : The color when a ray hits
#define scenario10 CYAN\
"\nGiven w ← default_world()\n"                                       \
"And r ← ray(point(0, 0, -5), vector(0, 0, 1))\n"                     \
"When c ← color_at(w, r)\n"                                       	  \
"Then c = color(0.38066, 0.47583, 0.2855"RESET

// Scenario : The color with an intersection behind the ray
#define scenario11 CYAN\
"\nGiven w ← default_world()\n"                                      \
"And outer ← the first object in w\n"                                \
"And outer.material.ambient ← 1\n"                                   \
"And inner ← the second object in w\n"                               \
"And inner.material.ambient ← 1\n"                                   \
"And r ← ray(point(0, 0, 0.75), vector(0, 0, -1))\n"                 \
"When c ← color_at(w, r)\n"                                           \
"Then c = inner.material.color"RESET
