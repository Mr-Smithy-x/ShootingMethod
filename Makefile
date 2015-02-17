CC = g++
CFLAGS = -g -Wall -lm 
PROGRAM = main.cpp SOURCE/DiffEqns.cpp SOURCE/Integrators.cpp
OBJECTS = $(PROGRAM:.cpp=.o)
EXEC = shoot.out

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJECTS)
	
clean:
	rm $(OBJECTS) $(EXEC) 
