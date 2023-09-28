NAME = minirt
LIBMLX = libmlx42.a
libft = libft.a
MLXSRC = git@github.com:codam-coding-college/MLX42.git
VPATH= ./src/canvas/ ./src/tuples/
MLXDIR = ./MLX42
SRC= create_tuples.c
BUILD_SRC = ./build/
INCLUDE = -I./include -I./libs/
C_FLAGS = -Wall -Werror -Wextra -g3
OBJS = $(addprefix $(BUILD_DIR_RT), $(SRC:.c=.o))
BUILD_DIR_MLX = $(MLXDIR)/build
BUILD_DIR_RT= ./build/
MLX_INCLUDE = ./MLX42/include/MLX42/
LIBMLX_TARGET = $(BUILD_DIR_MLX)/$(LIBMLX)
LIBX_FLAGS = -lmlx -lXext -lX11 -lm -lz
CODAM_LIB_FLAGS = -L./MLX42/build/ -lmlx42 -ldl -lglfw -pthread -lm
VNC_CHECK := $(shell ps aux | grep -q '[X]vnc' && echo "VNC")


.PHONY: all clean fclean re mlxclean

all: $(NAME)


##### THIS IS FOR COMPILING ALL ALL FUNCTIONS INTO A STATIC LIBRARY TO BE EASILY INCLUDED BY THE TESTERS #####
SRCSLIB := $(wildcard ./src/*/*.c)
MINIRT_LIB_OBJS:= $(SRCSLIB:.c=.o)
LIB_OBJS = $(wildcard libs/objs/*.o)
LIB := minirt.a
makelib:
	@compiledb make --no-print-directory -C libs/
%.o: %.c
	$(CC) -I$(INCLUDE) -c $< -o $@
$(LIB): $(MINIRT_LIB_OBJS)
	ar rcs $@ $^ $(LIB_OBJS) 
as_lib: makelib $(LIB)
##### THIS IS FOR COMPILING ALL ALL FUNCTIONS INTO A STATIC LIBRARY TO BE EASILY INCLUDED BY THE TESTERS #####



ifeq ($(VNC_CHECK), "VNC")
$(NAME): $(OBJS)
	# $(CC) -DUSE_CODAM=0 $(CFLAGS) $(OBJS) $(LIBX_FLAGS) -D -o $@
	echo "É workspace"
else
$(NAME): $(LIBMLX_TARGET) $(OBJS)
	# $(CC) -DUSE_CODAM=1 $(CFLAGS) $(OBJS) -I$(INCLUDE) -I$(MLX_INCLUDE) $(CODAM_LIB_FLAGS) -o $@
	echo "Não é workspace"
endif

$(BUILD_DIR_RT)%.o: %.c
	@test -d $(BUILD_DIR_RT) || mkdir $(BUILD_DIR_RT)
	@$(CC) $(CFLAGS) -I$(MLX_INCLUDE) -I$(INCLUDE) -c $< -o $@

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
	@make clean --no-print-directory -C tests/
	rm -f src/*.o

fclean: mlxclean clean
	@echo "Fully Cleaning..."
	@make fclean --no-print-directory -C libs/
	@rm -f $(NAME) $(LIB)

re: fclean all
