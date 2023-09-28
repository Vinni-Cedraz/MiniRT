### CODAM BUILD
LIBMLX = libmlx42.a
MLXSRC = git@github.com:codam-coding-college/MLX42.git
BUILD_DIR_MLX = $(MLXDIR)/build
MLX_INCLUDE = ./MLX42/include/MLX42/
LIBMLX_TARGET = $(BUILD_DIR_MLX)/$(LIBMLX)
LIBX_FLAGS = -lmlx -lXext -lX11 -lm -lz
MLXDIR = ./MLX42
CODAM_LIB_FLAGS = -L./MLX42/build/ -lmlx42 -ldl -lglfw -pthread -lm


### LIBFT
libft = ./libs/libft.a
SRCSLIB := $(wildcard ./src/*/*.c)
LIB_OBJS = $(wildcard libs/objs/*.o)
LIB := minirt.a

### MINIRT
NAME = minirt
SRC = main.c
VPATH= ./src
BUILD_SRC = ./build/
INCLUDE = ./include
C_FLAGS = -Wall -Werror -Wextra -g3
OBJS = $(addprefix $(BUILD_DIR_RT),$(SRC:.c=.o))
BUILD_DIR_RT= ./build/
CMD = $(CC) $(OBJS) $(C_FLAGS) -I$(MLX_INCLUDE) -I $(INCLUDE) -c $< -o $@

### RECIPES

##### THIS IS FOR COMPILING ALL ALL FUNCTIONS INTO A STATIC LIBRARY TO BE EASILY INCLUDED BY THE TESTERS #####

all: $(NAME)

$(NAME): $(LIBMLX_TARGET) $(OBJS)
	@printf "$(GREEN)[ Build ]$(DEF_COLOR) $(RED) $@ $(GREEN)complete $(DEF_COLOR)"
	@$(CC) $(LIBFT) $(CFLAGS) $(OBJS) -I$(INCLUDE) -I$(MLX_INCLUDE) $(CODAM_LIB_FLAGS) -o $@

$(BUILD_DIR_RT)%.o: %.c $(libft)
	@test -d $(BUILD_DIR_RT) || mkdir $(BUILD_DIR_RT)
	@echo "$(GREEN)[ Compiling ] $(DEF_COLOR) $< $(GREEN) with instruction $(DEF_COLOR) $(CMD)"
	@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(libft):
	make -C ./libs

$(LIBMLX_TARGET): $(MLXDIR)
	cd $(MLXDIR) && cmake --build build -j4;

$(MLXDIR):
	git clone $(MLXSRC) $(MLXDIR);
	cd $(MLXDIR) && cmake -B build

mlxclean:
	@echo "Cleaning MLX42..."
	@rm -rf $(MLXDIR)

clean: mlxclean
	@echo "Cleaning..."
	@make clean --no-print-directory -C libs/
	rm -rf $(BUILD_DIR_RT)

fclean: mlxclean clean
	@echo "Fully Cleaning..."
	@make fclean --no-print-directory -C libs/
	@rm -f $(NAME) $(LIB)

makelib:
	@make --no-print-directory -C libs/

$(LIB): $(LIBMLX_TARGET) $(OBJS)
	@printf "\n$(YELLOW)[ linking ] $(DEF_COLOR)objects into library $(YELLOW)$@ $(DEF_COLOR)\n"
	@ar rcs $@ $^ $(LIB_OBJS)

as_lib: makelib $(LIB)
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
