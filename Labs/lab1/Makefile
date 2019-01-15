CC=g++
EXE_FILE=multdiv-print

all: $(EXE_FILE)

$(EXE_FILE): multdiv.o multdiv.hpp multdiv-print.cpp
	$(CC) multdiv.o multdiv-print.cpp -o $(EXE_FILE)

multdiv.o: multdiv.hpp multdiv.cpp
	$(CC) -c multdiv.cpp

clean:
	rm -f *.o $(EXE_FILE)

