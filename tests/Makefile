TESTDIRS = 01 \
		   02 \
	  	   03 \
	       04 \
	       05 \
	       06 \
		   07 \
		   09 \
		   
all:
	@$(foreach file,$(TESTDIRS),$(MAKE) --no-print-directory -C $(file);)

run:
	@$(foreach file,$(TESTDIRS),$(MAKE) run --no-print-directory -C $(file);)

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../
clean:
	@$(foreach file,$(TESTDIRS),$(MAKE) clean --no-print-directory -C $(file);)

fclean: clean
	@$(foreach file,$(TESTDIRS),$(MAKE) fclean --no-print-directory -C $(file);)
