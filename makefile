#Default or "all" compiles a grocery list program that presents a menu prompting
#	the user for input. Executed with standard ./a.out
#"clean" clears out the object files and the executable.

CC = g++
OBJECTS = Space.o Cave.o Fountain.o Wheel.o Ruins.o River.o Start.o End.o
FLAGS = -g -Wall

all: $(OBJECTS) main.o
	$(CC) $(FLAGS) $(OBJECTS) main.o

test: $(OBJECTS) test.o
	$(CC) $(FLAGS) $(OBJECTS) test.o

%.o: %.cpp
	$(CC) -c $(FLAGS) $<

clean:
	rm -f $(OBJECTS) a.out main.o test.o
