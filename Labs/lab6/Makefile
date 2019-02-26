CC=g++
EXE_FILE=application

all:$(EXE_FILE)

$(EXE_FILE): shape.o application.o circle.o rectangle.o square.o
	$(CC) -o $(EXE_FILE) shape.o application.o circle.o rectangle.o square.o

shape.o:
	$(CC) -c shape.cpp

application.o:
	$(CC) -c application.cpp

circle.o:
	$(CC) -c circle.cpp

rectangle.o:
	$(CC) -c rectangle.cpp

square.o:
	$(CC) -c square.cpp

clean:
	rm -f *.o $(EXE_FILE)
