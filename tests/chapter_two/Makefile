TESTDIRS = canvas \
		   color_operations \
		   representing_colors \
		   putting_it_together

ORANGE = \033[38;5;214m
RESET = \033[0m

define MAKE_COMPILE
	cd $(1) && compiledb make --no-print-directory && cd ..
endef

define MAKE_RUN
	make run --no-print-directory -C $(1)
endef

MAKE_CLEAN = make clean --no-print-directory -C

run:
	@printf "$(ORANGE)=== CHAPTER TWO ===$(RESET)\n"
	@$(foreach dir,$(TESTDIRS),$(call MAKE_RUN, $(dir));)
	@$(foreach dir,$(TESTDIRS),$(call MAKE_COMPILE, $(dir));)

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../

clean:
	@$(foreach dir,$(TESTDIRS),$(MAKE_CLEAN) $(dir);)
