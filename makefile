OBJECTS= main.o draw.o display.o matrix.o parser.o gmath.o
CFLAGS= -Wall
LDFLAGS= -lm
CC= gcc

run: all
	./main script

all: $(OBJECTS)
	$(CC) -o main $(OBJECTS) $(LDFLAGS)

main.o: main.c display.h draw.h ml6.h matrix.h parser.h
	$(CC) -c main.c

draw.o: draw.c draw.h display.h ml6.h matrix.h gmath.h
	$(CC) $(CFLAGS) -c draw.c

display.o: display.c display.h ml6.h matrix.h
	$(CC) $(CFLAGS) -c display.c

gmath.o: gmath.c matrix.h gmath.h ml6.h
	$(CC) $(CFLAGS) -c gmath.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

parser.o: parser.c parser.h matrix.h draw.h display.h ml6.h
	$(CC) $(CFLAGS) -c parser.c

clean:
	rm *.o *~
