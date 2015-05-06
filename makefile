COMPILER = g++
FLAGS = -g -Wall -std=c++0x
all: program3
program3: program3.o	
	$(COMPILER) $(FLAGS) -o program3 program3.o
program3.o: program3.cpp
	$(COMPILER) $(FLAGS) -c program3.cpp
clean:
	rm -f $(EXECUTABLE) *.o
