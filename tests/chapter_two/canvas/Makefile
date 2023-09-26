#probably only need to mofify TEST:
TEST = canvas

CFLAGS = cc -O3 -lcriterion -I../../
LIB = ../../../libs/*.a  ../../../minirt.a -lm

all: makelibft makeminirt_as_lib 
	@$(CFLAGS) $(TEST).c $(LIB) -o $(TEST)
	@./$(TEST) --verbose

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../../
makelibft:
	@make --no-print-directory -C ../../../libs/

clean:
	rm -f $(TEST)
	rm -f output.ppm
