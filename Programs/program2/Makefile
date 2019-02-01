CC=g++
EXE_FILE=gofish

all: $(EXE_FILE)

$(EXE_FILE): gofish.o card.o hand.o deck.o player.o game.o
	$(CC) -o $(EXE_FILE) gofish.o card.o hand.o deck.o player.o game.o 

gofish.o:
	$(CC) -c gofish.cpp -std=c++11

card.o:
	$(CC) -c card.cpp

deck.o:
	$(CC) -c deck.cpp

hand.o:
	$(CC) -c hand.cpp

player.o:
	$(CC) -c player.cpp

game.o:
	$(CC) -c game.cpp -std=c++11

clean:
	rm -f *.o $(EXE_FILE)

