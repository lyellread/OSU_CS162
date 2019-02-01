CC=g++
EXE_FILE=lab4

all: $(EXE_FILE)

$(EXE_FILE): lab4.o card.o hand.o deck.o
	$(CC) -o $(EXE_FILE) lab4.o card.o hand.o deck.o


lab4.o:
	$(CC) -c lab4.cpp

card.o:
	$(CC) -c card.cpp

deck.o:
	$(CC) -c deck.cpp


clean:
	rm -f *.o $(EXE_FILE)

