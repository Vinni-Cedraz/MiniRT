CFLAGS = cc -O3 -lcriterion -I../ -lm
LIB = ../../libft_gnl/*.a  ../../minirt.a

all: makelibft makeminirt_as_lib
	@$(CFLAGS) magnitude.c $(LIB) -o magnitude
	@$(CFLAGS) normalization.c $(LIB) -o normalization
	@$(CFLAGS) dot_product.c $(LIB) -o dot_product
	@$(CFLAGS) cross_product.c $(LIB) -o cross_product
	@./magnitude --verbose
	@./normalization --verbose
	@./dot_product --verbose
	@./cross_product --verbose

makelibft:
	@make --no-print-directory -C ../../libft_gnl/
makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../
clean:
	rm -f magnitude
	rm -f dot_product
	rm -f normalization
	rm -f cross_product
