#include<iostream>
#include<cstdlib>
#include"s.h"
using namespace std;

int main()
{
	Sudoku s;
	s.giveQuestion();
	cout<<"----------------------"<<endl;
	s.readIn();
	cout<<"----------------------"<<endl;
	s.solve();
	return 0;
}
