all: combinations

combinations: globals.o functions.o main.o
	g++ globals.o functions.o main.o -o combinations

globals.o: globals.cpp
	g++ -c globals.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f combinations *.o
