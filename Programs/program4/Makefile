CC=g++
EXE_FILE=hunt

all:$(EXE_FILE)

$(EXE_FILE): application.o bat.o pit.o wumpus.o player.o event.o gold.o room.o game.o
	$(CC) -o $(EXE_FILE) application.o bat.o wumpus.o pit.o player.o event.o gold.o room.o game.o

application.o:
	$(CC) -c application.cpp -std=c++11 

event.o:
	$(CC) -c event.cpp

gold.o:
	$(CC) -c gold.cpp

room.o:
	$(CC) -c room.cpp

game.o:
	$(CC) -c game.cpp -std=c++11

pit.o:
	$(CC) -c pit.cpp

bat.o:
	$(CC) -c bat.cpp

wumpus.o:
	$(CC) -c wumpus.cpp

player.o:
	$(CC) -c player.cpp

clean:
	rm -f *.o $(EXE_FILE)

clear:
	rm -f *.o $(EXE_FILE)
