execute: StatTest.o Statistics.o
	g++ -g Statistics.o StatTest.o -o StatTest

StatTest.o: StatTest.cpp
	g++ -Wall -g -c  StatTest.cpp 

Statistics.o: Statistics.cpp Statistics.h
	g++ -Wall -g -c  Statistics.cpp
clean:
	rm -r *.o execute

