#probably only need to mofify TEST:
TEST = basic_tuple_operations

CFLAGS = cc -O3 -lcriterion -I../../
LIB = ../../../libft_gnl/*.a  ../../../minirt.a

all: makelibft makeminirt_as_lib 
	@$(CFLAGS) $(TEST).c $(LIB) -o $(TEST)
	@./$(TEST) --verbose

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../../
makelibft:
	@make --no-print-directory -C ../../../libft_gnl/
clean:
	rm -f $(TEST)
