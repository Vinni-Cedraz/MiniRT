TESTS = basic_tuple_operations

INCS = -I../../ -I../../../include/ -I../../../libs/
FLAGS = -O3 -lcriterion -lm -w
LIBS = ../../../libs/*.a ../../../minirt.a
RM = rm -f
SHELL = /bin/zsh

define compile_fn
	if [[ ! -f $(1) ]] || [[ $(1).c -nt $(1) ]]; then \
		$(CC) $(FLAGS) $(1).c $(INCS) $(LIBS) -o $(1) && printf "$(CC) $(FLAGS) $(1).c $(INCS) $(LIBS) -o $(1)\n"; \
	fi
endef

define run_fn
	$(1) --verbose && sleep 0.1;
endef

all: makeminirt_as_lib
	@$(foreach name, $(TESTS), $(call compile_fn, $(name)))

run:
	@$(foreach name, $(TESTS), $(call run_fn, ./$(name)))

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../../

clean:
	$(foreach name, $(TESTS), $(RM) $(name);)

fclean: clean
	$(RM) compile_commands.json

re: fclean
