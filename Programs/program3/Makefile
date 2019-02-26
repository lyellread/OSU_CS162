CC=g++
EXE_FILE=run-zoo

all:$(EXE_FILE)

$(EXE_FILE): application.o zoo.o animal.o sloth.o monkey.o sea_otter.o
	$(CC) -o $(EXE_FILE) application.o zoo.o animal.o sloth.o monkey.o sea_otter.o

application.o:
	$(CC) -c application.cpp

zoo.o:
	$(CC) -c zoo.cpp

animal.o:
	$(CC) -c animal.cpp

sloth.o:
	$(CC) -c sloth.cpp

monkey.o:
	$(CC) -c monkey.cpp

sea_otter.o:
	$(CC) -c sea_otter.cpp

clean:
	rm -f *.o $(EXE_FILE)
