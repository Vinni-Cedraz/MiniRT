TESTDIRS = comparing_floats \
		   tuple_operations \
		   tuples

all: makelibft
	@$(foreach file,$(TESTDIRS),$(MAKE) --no-print-directory -C $(file);)
makelibft:
	@make --no-print-directory -C ../libft_gnl/

clean:
	@$(foreach file,$(TESTDIRS),$(MAKE) clean --no-print-directory -C $(file);)
