NAME = minirt
LIBMLX = libmlx42.a
libft = libft.a
MLXSRC = git@github.com:codam-coding-college/MLX42.git
VPATH= ./src
MLXDIR = ./MLX42
SRC= main.c
BUILD_SRC = ./build/
INCLUDE = ./include
C_FLAGS = -Wall -Werror -Wextra
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

ifeq ($(VNC_CHECK), "VNC")
$(NAME): $(LIBMLX_TARGET) $(OBJS)
	$(CC) -DUSE_CODAM=0 $(CFLAGS) $(OBJS) $(LIBX_FLAGS) -D -o $@
else
$(NAME): $(LIBMLX_TARGET) $(OBJS)
	$(CC) -DUSE_CODAM=1 $(CFLAGS) $(OBJS) -I$(INCLUDE) -I$(MLX_INCLUDE) $(CODAM_LIB_FLAGS) -o $@
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

fclean: mlxclean
	@echo "Full cleaning..."
	@rm -rf $(BUILD_DIR_RT)
	@rm -f $(NAME)


re: fclean all
