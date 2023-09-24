TESTDIRS = chapter_one \
	  	  chapter_two \
	      #  chapter_three \
	      #  chapter_four \
	      #  chapter_five \
		   
all: makeminirt_as_lib
	@$(foreach file,$(TESTDIRS),$(MAKE) --no-print-directory -C $(file);)

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../
clean:
	@$(foreach file,$(TESTDIRS),$(MAKE) clean --no-print-directory -C $(file);)
