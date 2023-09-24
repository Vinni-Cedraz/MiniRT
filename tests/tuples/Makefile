#probably only need to mofify TEST:
TEST = tuples

CFLAGS = cc -g3 -lcriterion -I../
LIB = ../../libft_gnl/*.a  ../../minirt.a

all: makelibft makeminirt_as_lib
	@$(CFLAGS) $(TEST).c $(LIB) -o $(TEST)
	@./$(TEST) --verbose

makelibft:
	@make --no-print-directory -C ../../libft_gnl/
makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../

clean:
	rm -f $(TEST)
