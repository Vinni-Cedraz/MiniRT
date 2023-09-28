# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 11:11:55 by vcedraz-          #+#    #+#              #
#    Updated: 2023/09/28 15:10:47 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## SET-UP VARIABLES ##
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -O3
R = rm -f
RD = rm -rf
OBJS_PATH = ./objs/
OBJSB_PATH = ./objs_bonus/

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

## SRCS VARIABLES ##
SRCS = ft_abs \
ft_atoi \
ft_free_t_split \
ft_free_arr \
ft_free_arr_size \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_ishexup \
ft_ishexlow \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memorylen \
ft_memset \
ft_numlen \
ft_putchar \
ft_putchar_fd \
ft_strlen \
ft_atoi_base \
ft_strncmp \
ft_word_counter \
ft_calloc \
ft_memmove \
ft_putnbr_fd \
ft_putstr \
ft_putstr_fd \
ft_striteri \
ft_strrchr \
ft_strrev \
ft_swap \
ft_tolower \
ft_toupper \
ft_bzero \
ft_atol \
ft_isalnum \
ft_itoa_base \
ft_putendl_fd \
ft_strchr \
ft_strdup \
ft_strlcat \
ft_strlcpy \
ft_strmapi \
ft_strnstr \
ft_strjoin \
ft_strtrim \
ft_substr \
ft_gnl \
ft_itoa \
ft_split \
ft_randomize_array \
ft_iswhitespace \
ft_fmt_str \
ft_simple_itoa \

BSRCS = ft_lstadd_back \
ft_lstadd_front \
ft_lstfree \
ft_lstlast \
ft_lstnew \
ft_lstsize \
ft_lstprint \
ft_lstadd_here \
ft_lstdel_here \
ft_lstgetby_index \
ft_lstgetby_content \
ft_lst_circular \
ft_lstcircular_free \
ft_lstpop \
ft_lstshift \
ft_check_balanced \
	
OBJS = $(addprefix $(OBJS_PATH), $(addsuffix .o, $(SRCS)))
OBJSB = $(addprefix $(OBJSB_PATH), $(addsuffix .o, $(BSRCS)))
message = \nObjects are $(GREEN)linked$(DEF_COLOR) into $(RED)$(NAME)$(DEF_COLOR).\n
bmessage = \nBonus Objects are $(GREEN)linked$(DEF_COLOR) into $(RED)$(NAME)$(DEF_COLOR).\n
armessage = $(YELLOW)[ Linking ] $(DEF_COLOR) $(notdir $(1))  $(YELLOW) with instruction: $(DEF_COLOR)  ar -rcs $(NAME) $(1)                   
ccmessage = $(CYAN)compiling source files into object files $(DEF_COLOR)\n

ifdef WITH_BONUS
	OBJS=$(OBJSB)
	message=$(bmessage)
endif

all: $(OBJS_PATH) $(NAME)

define ft_make_archive
	ar -rcs $(NAME) $(1)
	printf "\r$(armessage)"
endef

$(NAME): $(OBJS)
	@printf "\n$(CYAN)linking objects into library $(NAME) $(DEF_COLOR)\n"
	@$(foreach obj,$?,$(call ft_make_archive,$(obj)) &&) true
	@printf "$(message)"

$(OBJS_PATH):
	@printf "$(ccmessage)"
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: %.c
	@printf "\r$(GREEN)[ Compiling ]$(DEF_COLOR) $< $(GREEN) with instruction: $(DEF_COLOR) $(CC) $(CFLAGS) -c $< -o $@             "
	@$(CC) $(CFLAGS) -c $< -o $@
	
bonus: $(OBJSB_PATH) $(NAME_BONUS)
	@make --no-print-directory WITH_BONUS=TRUE

$(OBJSB_PATH):
	@printf "$(ccmessage)"
	@mkdir -p $(OBJSB_PATH)

$(OBJSB_PATH)%.o: %.c
	@printf "\r$(GREEN)[ Compiling ]$(DEF_COLOR) $< $(GREEN) with instruction: $(DEF_COLOR) $(CC) $(CFLAGS) -c $< -o $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RD) $(OBJS_PATH)
	@$(RD) $(OBJSB_PATH)

bclean:
	@$(RD) $(OBJSB_PATH)

fclean: clean
	@$(R) $(NAME)
	@$(R) $(NAME_BONUS)

fbclean: bclean
	@$(R) $(NAME_BONUS)

re: fclean all

bre: fbclean bonus
