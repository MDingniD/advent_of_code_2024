CC=gcc
CFLAGS=-I.
DEPS = read_input.h process_input.h
OBJ = main.o read_input.o process_input.o
ARGS = input.txt 2

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: main
	@./main $(ARGS)

clean:
	rm -f $(OBJ) main