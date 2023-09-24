
TESTDIRS = representing_colors \
		   color_operations \
		   # creating_a_canvas \
		   # saving_a_canvas \
		   # putting_it_together

ORANGE = \033[38;5;214m
RESET = \033[0m

all: makeminirt_as_lib
	@printf "$(ORANGE)=== CHAPTER TWO ===$(RESET)\n"
	@$(foreach file,$(TESTDIRS),$(MAKE) --no-print-directory -C $(file);)

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../

clean:
	@$(foreach file,$(TESTDIRS),$(MAKE) clean --no-print-directory -C $(file);)
