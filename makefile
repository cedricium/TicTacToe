TicTacToe: main.o
	g++ main.o -o TicTacToe

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o
