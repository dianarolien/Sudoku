sudoku:: sudoku.o s.o
	g++ -o sudoku sudoku.o s.o
sudoku.o:: sudoku.cpp s.h
	g++ -c sudoku.cpp
s.o:: s.cpp s.h
	g++ -c s.cpp
clean:
	rm sudoku *.o
