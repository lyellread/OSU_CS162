CC=g++
EXE_FILE=escape

all:$(EXE_FILE)

$(EXE_FILE): application.o maze_level.o player.o maze_person.o instructor.o ta.o maze_location.o open_space.o wall.o maze.o
	$(CC) -o $(EXE_FILE) application.o maze_level.o maze_person.o instructor.o ta.o player.o maze_location.o open_space.o wall.o maze.o

application.o:
	$(CC) -c application.cpp -std=c++11

maze_person.o:
	$(CC) -c maze_person.cpp -std=c++11
	
player.o:
	$(CC) -c player.cpp -std=c++11

instructor.o:
	$(CC) -c instructor.cpp

ta.o:
	$(CC) -c ta.cpp -std=c++11

maze.o:
	$(CC) -c maze.cpp -std=c++11

maze_location.o:
	$(CC) -c maze_location.cpp

open_space.o:
	$(CC) -c open_space.cpp

wall.o:
	$(CC) -c wall.cpp

maze_level.o:
	$(CC) -c maze_level.cpp -std=c++11
	
clean:
	rm -f *.o $(EXE_FILE)
	
remove_ofiles:
	rm -f *.o

clear:
	rm -f *.o $(EXE_FILE)
