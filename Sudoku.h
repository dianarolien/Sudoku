#include<iostream>

class Sudoku
{
	public:
		Sudoku();
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void setMap(int set_map[]);
		void change();
		int nextBlank(int np);
		void push(int np);
		int previousBlank();
		int checkBlank(int np);
		int checkRow(int np);
		int checkCol(int np);
		int checkBlock(int np);
		void printOut(bool isAns);
	
	private:
		static const int sudokusize = 81;
		int map[sudokusize];
		int ans[sudokusize];
		int a[sudokusize];
};
