NAME = minirt
LIBMLX = libmlx42.a
libft = libft.a
MLXSRC = git@github.com:codam-coding-college/MLX42.git
MLXDIR = ./MLX42
BUILD_DIR = $(MLXDIR)/build
LIBMLX_TARGET = $(BUILD_DIR)/$(LIBMLX)

.PHONY: all clean fclean re mlxclean

all: $(NAME)

$(NAME): $(LIBMLX_TARGET)
	@echo "Building $(NAME)"

$(LIBMLX_TARGET): $(MLXDIR)
	@if [ ! -f "$(LIBMLX_TARGET)" ]; then \
		cd $(MLXDIR) && cmake --build build -j4; \
	fi

$(MLXDIR):
	@if [ ! -d "$(MLXDIR)" ]; then \
		git clone $(MLXSRC) $(MLXDIR); \
	fi
	cd $(MLXDIR) && cmake -B build

clean:
	@echo "Cleaning..."
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean mlxclean
	@echo "Full cleaning..."
	@rm -f $(NAME)

mlxclean:
	@echo "Cleaning MLX42..."
	@rm -rf $(MLXDIR)

re: fclean all
