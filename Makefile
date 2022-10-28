DEPS=display.h

all: compile


main.o: main.c
	gcc -lncurses -c main.c

compile: display.o main.o
	gcc main.o -lncurses -o clock

run:
	./clock.sh | ./clock

clean:
	rm -rf *.o
	rm -rf clock


