P=doomsday
OBJECTS=
CFLAGS=-g -pedantic -gdwarf-2 -g3 -Wall -O0
CPPFLAGS=
LDFLAGS=
LDLIBS=
CC=gcc

$(P): $(OBJECTS)

clean: 
	-rm *.o

run: $(P)
	./$(P) $(PARGS)

