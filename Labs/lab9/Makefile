CC=g++
EXE_FILE=run

all:$(EXE_FILE)

$(EXE_FILE): application.o player.o maze_location.o open_space.o wall.o maze.o
	$(CC) -o $(EXE_FILE) application.o player.o maze_location.o open_space.o wall.o maze.o

application.o:
	$(CC) -c application.cpp

player.o:
	$(CC) -c player.cpp

maze.o:
	$(CC) -c maze.cpp

maze_location.o:
	$(CC) -c maze_location.cpp

open_space.o:
	$(CC) -c open_space.cpp

wall.o:
	$(CC) -c wall.cpp

clean:
	rm -f *.o $(EXE_FILE)

clear:
	rm -f *.o $(EXE_FILE)
