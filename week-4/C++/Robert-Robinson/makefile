test: Robert-Robinson.o SumList.o LinkedList.o Reverse.o
	g++ -o test Robert-Robinson.o SumList.o LinkedList.o Reverse.o -ggdb

Robert-Robinson.o: Robert-Robinson.cpp SumList.h Reverse.h
	g++ -c Robert-Robinson.cpp -g

SumList.o: SumList.cpp SumList.h LinkedList.h
	g++ -c SumList.cpp -g

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -c LinkedList.cpp -g

Reverse.o: Reverse.cpp Reverse.h LinkedList.h
	g++ -c Reverse.cpp -g

clean:
	rm *.o

backup:
	tar -cvf week_4.tar *.h *.cpp
