TESTDIRS = canvas \
		   color_operations \
		   representing_colors \
		   putting_it_together

ORANGE = \033[38;5;214m
YELLOW = \033[38;5;226m
RESET = \033[0m

define MAKE_COMPILE
	cd $(1) && make --no-print-directory | compiledb && cd .. && \
		printf "\r$(YELLOW)Compiling $(RESET)$(1)/ tests and creating its compile_commands.json$(RESET)        "
endef

define MAKE_RUN
	make run --no-print-directory -C $(1)
endef

MAKE_CLEAN = make clean --no-print-directory -C
MAKE_FCLEAN = make fclean --no-print-directory -C

all:
	@printf "\n$(ORANGE)=== CHAPTER TWO ===$(RESET)\n"
	@$(foreach dir,$(TESTDIRS),$(call MAKE_COMPILE, $(dir));)

run:
	@printf "\n$(ORANGE)=== CHAPTER TWO ===$(RESET)\n"
	@$(foreach dir,$(TESTDIRS),$(call MAKE_RUN, $(dir));)

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../

clean:
	@$(foreach dir,$(TESTDIRS),$(MAKE_CLEAN) $(dir);)

fclean: clean
	@$(foreach dir,$(TESTDIRS),$(MAKE_FCLEAN) $(dir);)
