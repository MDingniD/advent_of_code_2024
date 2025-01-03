CC=gcc
CFLAGS= -O2 -Wall -Wextra -I.
#CFLAGS= -O2 -Wall -Wextra -I. -DDEBUG
DEPS = read_input.h data_structure.h check_operation.h
OBJ = main.o read_input.o data_structure.o check_operation.o
ARGS = input.txt input1.txt

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: main
	@./main $(ARGS)

clean:
	rm -f $(OBJ) main