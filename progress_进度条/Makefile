SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
BIN=proc

$(BIN):$(OBJ)
	@gcc -o $@ $^
	@echo "linking $^ to $@"
%.o:%.c
	@gcc -c $< -std=c99
	@echo "compleing $< to $@"

.PHONY:
clean:
	@rm -f $(OBJ) $(BIN)
	@echo "remove ...$(BIN) $(OBJ)"
