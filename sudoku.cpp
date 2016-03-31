#include<iostream>
#include<cstdlib>
#include"s.h"
using namespace std;

int main()
{
	Sudoku s;
	s.giveQuestion();
	s.readIn();
	s.solve();
	return 0;
}
