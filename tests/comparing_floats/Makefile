#probably only need to mofify TEST:
TEST = compare_floats

CFLAGS = cc -g3 -lcriterion -I../
LIB = ../../libft_gnl/*.a 

all: 
	@$(CFLAGS) $(TEST).c $(LIB) -o $(TEST)
	@./$(TEST) --verbose

clean:
	rm -f $(TEST)
