CFLAGS = cc -O3 -lcriterion -I../ -lm
LIB = ../../libft_gnl/*.a  ../../minirt.a

all: makelibft makeminirt_as_lib
	@$(CFLAGS) magnitude.c $(LIB) -o magnitude
	@$(CFLAGS) normalization.c $(LIB) -o normalization
	@./magnitude --verbose
	@./normalization --verbose

makelibft:
	@make --no-print-directory -C ../../libft_gnl/
makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../

clean:
	rm -f magnitude
	rm -f normalization
