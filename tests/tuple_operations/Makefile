#probably only need to mofify TEST:
TEST = tuple_operations

CFLAGS = cc -O3 -lcriterion -I../
LIB = ../../libft_gnl/*.a 

all: 
	$(CFLAGS) $(TEST).c $(LIB) -o $(TEST)
	./$(TEST) --verbose

clean:
	rm -f $(TEST)
