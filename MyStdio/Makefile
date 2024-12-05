SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
BIN=proc

$(BIN):$(OBJ)
	@gcc -o $@ $^
$(OBJ):$(SRC)
	@gcc -c $@ $^

.PHONY:clean
clean:
	@rm -f $(OBJ) $(BIN)