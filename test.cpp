


//幫你稍微看一下code (洗衣機好慢ㄛ)
//問題我註解惹
//晚ㄤ//





#include<iostream>
#include<cstdlib>
#include <cstdio>
using namespace std;

class Sudoku
{
	public:
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
		static const int sudokusize = 81;
		int map[sudokusize];
		int ans[sudokusize];
		int a[sudokusize];
};

int i;
int j;
int k;
int h;
int t = -1;
int sp[81];
int np=0;

int main()
{
	Sudoku s;
	for(i=0;i<81;i++)
		s.map[i] = 0;
	cout << "-------------------------" << endl;
	s.giveQuestion();
	cout << "-------------------------" << endl;
	s.printOut(false);
	cout << "-------------------------" << endl;

	s.readIn();
	for(i=0;i<81;i++)
		s.a[i]=s.map[i];
	cout << s.checkRow(2) << endl << s.checkCol(2) <<endl << s.checkBlock(2) <<endl;
//	s.solve();
	return 0;
}


void Sudoku::setMap(int set_map[])
{
	for(i=0;i<sudokusize;i++)
		map[i] = set_map[i];
}

void Sudoku::giveQuestion()
{
	int q[sudokusize] = {8,4,0,1,0,0,0,0,6,0,0,3,0,0,0,2,0,0,0,0,0,6,0,5,0,4,0,1,0,0,0,0,0,0,0,5,0,9,0,4,0,8,0,6,0,3,0,0,0,0,0,0,0,9,0,1,0,7,0,3,0,0,0,0,0,6,0,0,0,9,0,0,4,0,0,0,0,6,0,5,3};
	setMap(q);
	for(i=0;i<sudokusize;i++)
		(i+1)%9!=0 ? cout<< q[i] << " " : cout<<map[i]<<endl;
}

void Sudoku::readIn()
{
	int r[sudokusize];
	for(i=0;i<sudokusize;i++)
		cin >> r[i];	
	setMap(r);
}

void Sudoku::solve()
{
	int check[9];
	int solution;
 /* check question */
	/* check row */
	for(j=0;j<9;j++)
	{
		for(i=0;i<9;i++)
			check[i] = 0;
		for(i=0;i<9;i++)
		{	
			if(map[i+9*j]!=0)
				check[map[i+9*j]-1]++;
		}
		for(i=0;i<9;i++)
		{	
			if(check[i]>1)
			{
				solution = 0;
				cout << solution << endl;
				return ;
			}
		}
	}
	/* check column */
	for(j=0;j<9;j++)
	{
		for(i=0;i<9;i++)
			check[i] = 0;
		for(i=0;i<9;i++)
		{
			if(map[j+i*9]!=0)
				check[map[j+i*9]-1]++;
		}
		for(i=0;i<9;i++)
			if(check[i]>1)
			{
				solution = 0;
				cout << solution << endl;
				return ;
			}
	}                                                                                         
	/* check block */
	for( h = 0; h < 3; h++ )
	{
		for(k=0;k<3;k++)
		{	
			for(i=0;i<9;i++)
				check[i] = 0;
			for(j=0;j<3;j++)
				for(i=0;i<3;i++)
					if(map[i+9*j+3*k+27*h]!=0)
						check[map[i+9*j+3*k+27*h]-1]++;
		}
		for(i=0;i<9;i++)
			if(check[i]>1)
			{
				solution = 0;
				cout << solution << endl;
				return ;
			}
	}


/* check answer */

	for( i = 0; i < sudokusize; i++ )		//你的a和ans全部搞混惹0.0 check裡的是ans 但是這裡都是a...檢查一下ㄅ
		a[i] = map[i];
	np = nextBlank(0);
	int sum=0,f=0;

	while( sum < 2 )
	{
		if( f!=0 )
			if( a[sp[0]] == 0 )
				a[sp[0]] = f;
		a[np]++;
		if( a[np] > 9 )
		{
			if( np == sp[0] )
				break;
			a[np] = 0;
			np = previousBlank();
		}
		else
			if( checkBlank(np) == 0 )
			{
			 	if(f==0)
				{
					push(np);
					np = nextBlank(np);
				}
				if(f!=0)
				{	np = sp[t];
					t++;
				}
				if( np == sudokusize-1 )
				{
					sum ++;
					np = sp[0];
					t=1;
					for(i=0;i<sudokusize;i++)
						ans[i] = a[i];
					f = a[sp[0]];
				}
			}

					//sp[]會重複推入np 要建一個int紀錄陣列現在存到哪
											//建議改else
						//第一格a[np]如果大於9會直接break
			//就算填入數字無矛盾checkBlank還是=1
	

	for(i=0;i<sudokusize;i++)			//抱歉先註解掉
		(i+1)%9!=0 ? cout<< a[i] << " " : cout<<map[i]<<endl;
	}
	if(sum==0)
		printf("0\n");
	if (sum>1)
		printf("2\n");
	if(sum==1)
		printOut(true);
}

		//原本是ans[]但check answer是對a做運算所以將a宣告成global var並改成a

int Sudoku::nextBlank(int np)
{
	while( np<sudokusize-1 && a[np]!=0)
		np++;
	return np;
}

void Sudoku::push(int np)
{	
	t++;
	sp[t] = np;
}

int Sudoku::previousBlank()
{		
	t--;
	return sp[t];
}

int Sudoku::checkBlank(int np)
{
	if( checkRow(np)==1 )
		return 1;	
	if( checkCol(np)==1 )
		return 1;
	if( checkBlock(np)==1)
		return 1;
	return 0;
}

int Sudoku::checkRow(int np)
{
	for(i=np-(np%9);i<np-(np%9)+9;i++)
		if(a[np]==a[i])
			return 1;
	return 0;
}

int Sudoku::checkCol(int np)
{
	for(i=0;i<9;i++)
		if( a[np] == a[np%9+i*9] )
			return 1;
	return 0;
}

int Sudoku::checkBlock(int np)
{
	if( np/9 < 3 )
		for(j=0;j<3;j++)
		{	
			if( np%9 < 3 )
			{
				for(i=0;i<3;i++)
					if( a[np]==a[i+9*j] )
						return 1;
				return 0;
			}
			if( ( 3 <= np%9 ) && ( np%9 < 6 ) )
			{
				for(i=3;i<6;i++)
					if( a[np]==a[i+9*j] )
						return 1;
				return 0;
			}
			if( ( 6 <= np%9 ) && ( np%9 < 9 ) )
			{
				for(i=6;i<9;i++)
					if( a[np]==a[i+9*j] )
						return 1;
				return 0;
			}
		}
	if( ( 3 <= np/9 ) && ( np/9 < 6 ) )
		for( j = 3; j < 6; j++ )
		{	
			if( np%9 < 3 )
			{
				for(i=0;i<3;i++)
					if( a[np]==a[i+9*j] )
						return 1;
				return 0;
			}
			if( ( 3 <= np%9 ) && ( np%9 < 6 ) )
			{
				for(i=3;i<6;i++)
					if( a[np]==a[i+9*j] )
						return 1;
				return 0;
			}
			if( ( 6 <= np%9 ) && ( np%9 < 9 ) )
			{
				for(i=6;i<9;i++)
					if( a[np]==a[i+9*j] )
						return 1;
				return 0;
			}
		}
	if( ( 6 <= np/9 ) && ( np/9 < 9 ) )
		for(j=6;j<9;j++)
		{	
			if( np%9 < 3 )
			{
				for(i=0;i<3;i++)
					if( a[np]==a[i+9*j] )
						return 1;
				return 0;
			}
			if( ( 3 <= np%9 ) && ( np%9 < 6 ) )
			{
				for(i=3;i<6;i++)
					if( a[np]==a[i+9*j] )
						return 1;
				return 0;
			}
			if( ( 6 <= np%9 ) && ( np%9 < 9 ) )
			{
				for(i=6;i<9;i++)
					if( a[np]==a[i+9*j] )
						return 1;
				return 0;
			}
		}
}

void Sudoku::changeNum(int a,int b)
{
	for(i=0;i<sudokusize;i++)
	{
		int flag = 0;
		if( map[i] == a )
		{
			flag = 1;
			map[i] = b;
		}
		if( ( map[i] == b ) && ( flag != 1 ) )
			map[i] = a;
	}
}

void Sudoku::changeRow(int a,int b)
{
	if( ( 2 < a ) || ( 2 < b ) || ( a < 0 ) || ( b < 0 ) )
	{
		cout << "a,b must be in the interval(0,2)."<<endl;
		return ;
	}
	int tmp;
	for(i=0;i<27;i++)
	{
		tmp = map[i+27*a];
		map[i+27*a] = map[i+27*b];
		map[i+27*b] = tmp;
	}	
}

void Sudoku::changeCol(int a,int b)
{
	if( ( 2 < a ) || ( 2 < b ) || ( a < 0 ) || ( b < 0 ) )
	{
		cout << "a,b must be in the interval(0,2)."<<endl;
		return ;
	}
	int tmp;
	for(i=0;i<3;i++)
		for(j=0;j<9;j++)
		{
			tmp = map[i+3*a+9*j];
			map[i+3*a+9*j] = map[i+3*b+9*j];
			map[i+3*b+9*j] = tmp;
		}
}

void Sudoku::rotate(int n)  
{
	if( ( n > 100 ) || ( n < 0 ) )
	{
		cout << "n must be in the interval [0,100]."<<endl;
		return ;
	}
	if( n%4 == 0 )
		n = 0;
	if( n%4 == 1)
		n = 1;
	if( n%4 == 2 )
		n = 2;
	if( n%4 == 3 )
		n = 3;
	int t[sudokusize] ;
	for(k=0;k<n;k++)
	{
		for(i=0;i<sudokusize;i++)
			t[i] = map[i];
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			{
				map[i+9*j] = t[72+j-9*i];
				map[8+9*i-j] = t[i+9*j];
				map[80-9*j-i] = t[8+9*i-j];
				map[72+j-9*i] = t[80-9*j-i];		
			}
		for(i=0;i<4;i++)
		{
			map[4+9*i] = t[36+i];
			map[44-i] = t[4+9*i];
			map[76-9*i] = t[44-i];
			map[36+i] = t[76-9*i];
		}
	}
}

void Sudoku::flip(int n)
{
	int tmp;
	if( ( n != 0) && ( n != 1 ) )
	{
		cout << "n must be 0 or 1."<<endl;
		return ;
	}
	if( n == 0 )
	{
		for(i=0;i<9;i++)
			for(j=0;j<4;j++)
			{
				tmp = map[i+9*j];
				map[i+9*j] = map[72+i-9*j];
				map[72+i-9*j] = tmp;
			}
	}
	if( n == 1 )
	{
		for(i=0;i<4;i++)
			for(j=0;j<9;j++)
			{
				tmp = map[i+9*j];
				map[i+9*j] = map[8+9*j-i];
				map[8+9*j-i] = tmp;
			}
	}
}

void Sudoku::transform()
{
	readIn();
	change();
	printOut(false);
}

void Sudoku::change()
{
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}

void Sudoku::printOut(bool isAns)
{
	int i;
	if(!isAns)
		for(i=0;i<sudokusize;i++)
			printf("%d%c",map[i],(i+1)%9==0?'\n':' ');
	else
	{	
		printf("1\n");
		for(i=0;i<sudokusize;i++)
			printf("%d%c",ans[i],(i+1)%9==0?'\n':' ');
	}
}
