#probably only need to mofify TEST:
TEST = complex_tuple_operations

SRCS = magnitude.c \
	   # normalization.c

CFLAGS = cc -O3 -lcriterion -I../ -lm
LIB = ../../libft_gnl/*.a  ../../minirt.a

all: makelibft makeminirt_as_lib
	@$(CFLAGS) $(SRCS) $(LIB) -o $(TEST)
	@./$(TEST) --verbose

makelibft:
	@make --no-print-directory -C ../../libft_gnl/
makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../

clean:
	rm -f $(TEST)
