TESTDIRS = tuples \
		   comparing_floats \
		   basic_tuple_operations \
		   complex_tuple_operations

all: makelibft makeminirt_as_lib
	@$(foreach file,$(TESTDIRS),$(MAKE) --no-print-directory -C $(file);)

makelibft:
	@make --no-print-directory -C ../libft_gnl/
makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../

clean:
	@$(foreach file,$(TESTDIRS),$(MAKE) clean --no-print-directory -C $(file);)
