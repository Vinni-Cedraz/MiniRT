#probably only need to mofify TEST:
TEST = projectile

CFLAGS = cc -O3 -lcriterion -I../../
LIB = ../../../libs/*.a  ../../../minirt.a

all: makeminirt_as_lib
	@$(CFLAGS) $(TEST).c $(LIB) -o $(TEST)
	@./$(TEST) --verbose

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../../
clean:
	rm -f $(TEST)
