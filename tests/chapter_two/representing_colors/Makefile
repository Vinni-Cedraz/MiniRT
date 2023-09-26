#probably only need to mofify TEST:
TEST = representing_colors

CFLAGS = cc -O3 -lcriterion -I../../
LIB = ../../../libs/*.a  ../../../minirt.a

all:
	@$(CFLAGS) $(TEST).c $(LIB) -o $(TEST)
	@./$(TEST) --verbose

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../../
makelibft:
	@make --no-print-directory -C ../../../libs/
clean:
	rm -f $(TEST)
