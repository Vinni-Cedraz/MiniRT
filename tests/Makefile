TESTDIRS = tuples \
		   comparing_floats \
		   basic_tuple_operations \
		   complex_tuple_operations

all: makelibft
	@$(foreach file,$(TESTDIRS),$(MAKE) --no-print-directory -C $(file);)
makelibft:
	@make --no-print-directory -C ../libft_gnl/

clean:
	@$(foreach file,$(TESTDIRS),$(MAKE) clean --no-print-directory -C $(file);)
