EXECS = canvas

SRCS = $(addsuffix .c, $(EXECS))
INCS = -I../../ -I../../../include/ -I../../../libs/
FLAGS = -O3 -lcriterion -lm -w
LIBS = ../../../libs/*.a ../../../minirt.a
RM = rm -f
SHELL = /bin/zsh

define run_fn
	$(1) --verbose;
endef

all: makeminirt_as_lib $(EXECS)

$(EXECS): $(SRCS)
	$(CC) $(FLAGS) $< $(INCS) $(LIBS) -o $@

run: all
	@$(foreach name, $(EXECS), $(call run_fn, ./$(name)))

makeminirt_as_lib:
	@make as_lib --no-print-directory -C ../../../

clean:
	$(foreach name, $(EXECS), $(RM) $(name);)
