CCFLAGS = -Wall -std=c++11

bracket: bracket.o
	g++ $(CCFLAGS) -o bracket bracket.o

bracket.o: bracket.cpp
	g++ $(CCFLAGS) -c bracket.cpp

clean:
	-rm *.o bracket
