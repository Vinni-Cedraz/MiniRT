#ifndef MINIRT_H
# ifndef USE_CODAM
#  define USE_CODAM 1
#  if USE_CODAM == 1
#  include "MLX42.h"
#  else
#  include "mlx.h"
#  endif
# endif
# include <stdio.h>
#endif
