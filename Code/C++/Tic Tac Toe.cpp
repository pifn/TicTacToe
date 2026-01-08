#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;
void ShowTable(char tb[3][3], char p, char e)
{
	cout<<"  A B C"<<endl;
	for(int i = 0; i<3; i++)
	{
		cout<<i+1;
		for(int j = 0; j<3; j++)
		{
			cout<<'|'<<tb[i][j];
		}
		cout<<'|'<<endl;
	}
}
bool CheckRoom(char tb[3][3])
{
	int v = 0;
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			v = tb[i][j] == ' ' ? 1 : v;
		}
	}
	return v;
}
int CheckForWin(char tb[3][3], char p, char e)
{
	char w = ' ';
	for(int y = 0; y<3; y++)
	{
		if(tb[0][0]==tb[1][1]&&tb[2][2]==tb[1][1])
			w = tb[0][0];
		else if(tb[0][2]==tb[1][1]&&tb[2][0]==tb[1][1])
			w = tb[1][1];
		else if(tb[0][0]==tb[0][1]&&tb[0][0]==tb[0][2])
			w = tb[0][0];
		else if(tb[1][0]==tb[1][1]&&tb[1][2]==tb[1][1])
			w = tb[1][0];
		else if(tb[2][0]==tb[2][1]&&tb[2][0]==tb[2][2])
			w = tb[2][0];
		else if(tb[0][0]==tb[1][0]&&tb[0][0]==tb[2][0])
			w = tb[0][0];
		else if(tb[0][1]==tb[1][1]&&tb[0][1]==tb[2][1])
			w = tb[0][1];
		else if(tb[2][0]==tb[2][1]&&tb[2][0]==tb[2][2])
			w = tb[2][0];
		else if(tb[0][2]==tb[1][2]&&tb[0][2]==tb[2][2])
			w = tb[0][2];
	}
	return (w==p)? 1 : ((w==e) ? -1 : 0);
}
void MakeMove(char tb[3][3],char e,char p)
{
	if(CheckRoom(tb))
	{
		//check for e's win
		if(tb[0][0]==tb[1][1]&&tb[0][0]==e&&tb[2][2]==' ')
			tb[2][2] = e;
		else if(tb[0][0]==tb[2][2]&&tb[0][0]==e&&tb[1][1]==' ')
			tb[1][1] = e;
		else if(tb[2][2]==tb[1][1]&&tb[2][2]==e&&tb[0][0]==' ')
			tb[0][0] = e;

		else if(tb[0][2]==tb[1][1]&&tb[1][1]==e&&tb[2][0]==' ')
			tb[2][0]=e;
		else if(tb[2][0]==tb[1][1]&&tb[1][1]==e&&tb[0][2]==' ')
			tb[0][2]=e;
		else if(tb[0][2]==tb[2][0]&&tb[0][2]==e&&tb[1][1]==' ')
			tb[1][1]=e;

		else if(tb[0][0]==tb[0][1]&&tb[0][0]==e&&tb[0][2]==' ')
			tb[0][2] = e;
		else if(tb[0][0]==tb[0][2]&&tb[0][0]==e&&tb[0][1]==' ')
			tb[0][1] = e;
		else if(tb[0][1]==tb[0][2]&&tb[0][1]==e&&tb[0][0]==' ')
			tb[0][0] = e;

		else if(tb[1][0]==tb[1][1]&&tb[1][1]==e&&tb[1][2]==' ')
			tb[1][2] = e;
		else if(tb[1][2]==tb[1][1]&&tb[1][1]==e&&tb[1][0]==' ')
			tb [1][0] = e;
		else if(tb[1][0]==tb[1][2]&&tb[1][0]==e&&tb[1][1]==' ')
			tb[1][1] = e;

		else if(tb[2][0]==tb[2][1]&&tb[2][1]==e&&tb[2][2]==' ')
			tb[2][2] = e;
		else if(tb[2][0]==tb[2][2]&&tb[2][2]==e&&tb[2][1]==' ')
			tb[2][1] = e;
		else if(tb[2][1]==tb[2][2]&&tb[2][1]==e&&tb[2][0]==' ')
			tb[2][0]= e;

		else if(tb[0][0]==tb[1][0]&&tb[0][0]==e&&tb[2][0]==' ')
			tb[2][0] = e;
		else if(tb[0][0]==tb[2][0]&&tb[2][0]==e&&tb[1][0]==' ')
			tb[1][0]=e;
		else if(tb[1][0]==tb[2][0]&&tb[2][0]==e&&tb[0][0]==' ')
			tb[0][0]=e;


		else if(tb[0][1]==tb[1][1]&&tb[1][1]==e&&tb[2][1]==' ')
			tb[2][1]=e;
		else if(tb[0][1]==tb[2][1]&&tb[0][1]==e&&tb[1][1]==' ')
			tb[1][1] = e;
		else if(tb[1][1]==tb[2][1]&&tb[2][1]==e&&tb[0][1]==' ')
			tb[0][1] = e;

		else if(tb[2][0]==tb[2][1]&&tb[2][0]==e&&tb[2][2]==' ')
			tb[2][2] = e;
		else if(tb[2][0]==tb[2][2]&&tb[2][0]==e&&tb[2][1]==' ')
			tb[2][1] = e;
		else if(tb[2][1]==tb[2][2]&&tb[2][1]==e&&tb[2][0]==' ')
			tb[2][0] = e;


		else if(tb[0][2]==tb[1][2]&&tb[0][2]==e&&tb[2][2]==' ')
			tb[2][2]=e;
		else if(tb[0][2]==tb[2][2]&&tb[0][2]==e&&tb[1][2]==' ')
			tb[1][2]=e;
		else if(tb[1][2]==tb[2][2]&&tb[1][2]==e&&tb[0][2]==' ')
			tb[0][2]=e;

		//check for p's win
		if(tb[0][0]==tb[1][1]&&tb[0][0]==p&&tb[2][2]==' ')
			tb[2][2] = e;
		else if(tb[0][0]==tb[2][2]&&tb[0][0]==p&&tb[1][1]==' ')
			tb[1][1] = e;
		else if(tb[2][2]==tb[1][1]&&tb[2][2]==p&&tb[0][0]==' ')
			tb[0][0] = e;

		else if(tb[0][2]==tb[1][1]&&tb[1][1]==p&&tb[2][0]==' ')
			tb[2][0]=e;
		else if(tb[2][0]==tb[1][1]&&tb[1][1]==p&&tb[0][2]==' ')
			tb[0][2]=e;
		else if(tb[0][2]==tb[2][0]&&tb[0][2]==p&&tb[1][1]==' ')
			tb[1][1]=e;

		else if(tb[0][0]==tb[0][1]&&tb[0][0]==p&&tb[0][2]==' ')
			tb[0][2] = e;
		else if(tb[0][0]==tb[0][2]&&tb[0][0]==p&&tb[0][1]==' ')
			tb[0][1] = e;
		else if(tb[0][1]==tb[0][2]&&tb[0][1]==p&&tb[0][0]==' ')
			tb[0][0] = e;

		else if(tb[1][0]==tb[1][1]&&tb[1][1]==p&&tb[1][2]==' ')
			tb[1][2] = e;
		else if(tb[1][2]==tb[1][1]&&tb[1][1]==p&&tb[1][0]==' ')
			tb [1][0] = e;
		else if(tb[1][0]==tb[1][2]&&tb[1][0]==p&&tb[1][1]==' ')
			tb[1][1] = e;

		else if(tb[2][0]==tb[2][1]&&tb[2][1]==p&&tb[2][2]==' ')
			tb[2][2] = e;
		else if(tb[2][0]==tb[2][2]&&tb[2][2]==p&&tb[2][1]==' ')
			tb[2][1] = e;
		else if(tb[2][1]==tb[2][2]&&tb[2][1]==p&&tb[2][0]==' ')
			tb[2][0]= e;

		else if(tb[0][0]==tb[1][0]&&tb[0][0]==p&&tb[2][0]==' ')
			tb[2][0] = e;
		else if(tb[0][0]==tb[2][0]&&tb[2][0]==p&&tb[1][0]==' ')
			tb[1][0]=e;
		else if(tb[1][0]==tb[2][0]&&tb[2][0]==p&&tb[0][0]==' ')
			tb[0][0]=e;


		else if(tb[0][1]==tb[1][1]&&tb[1][1]==p&&tb[2][1]==' ')
			tb[2][1]=e;
		else if(tb[0][1]==tb[2][1]&&tb[0][1]==p&&tb[1][1]==' ')
			tb[1][1] = e;
		else if(tb[1][1]==tb[2][1]&&tb[2][1]==p&&tb[0][1]==' ')
			tb[0][1] = e;

		else if(tb[2][0]==tb[2][1]&&tb[2][0]==p&&tb[2][2]==' ')
			tb[2][2] = e;
		else if(tb[2][0]==tb[2][2]&&tb[2][0]==p&&tb[2][1]==' ')
			tb[2][1] = e;
		else if(tb[2][1]==tb[2][2]&&tb[2][1]==p&&tb[2][0]==' ')
			tb[2][0] = e;


		else if(tb[0][2]==tb[1][2]&&tb[0][2]==p&&tb[2][2]==' ')
			tb[2][2]=e;
		else if(tb[0][2]==tb[2][2]&&tb[0][2]==p&&tb[1][2]==' ')
			tb[1][2]=e;
		else if(tb[1][2]==tb[2][2]&&tb[1][2]==p&&tb[0][2]==' ')
			tb[0][2]=e;

		//No one's winning
		else
		{
			int rx,ry;
			do {
				rx= rand() % 3;
				ry= rand() % 3;
			} while(tb[rx][ry]==e||tb[rx][ry]==p);
			tb[rx][ry] = e;
		}
	}
}

int main()
{
	char table[3][3], player, enemy,let;
	int num,x,y;
	srand(time(0));
	bool v = 1;
	while(v)
	{
		for(int i = 0; i<3; i++)
		{
			for(int j = 0; j<3; j++)
			{
				table[i][j] = ' ';
			}
		}
		do {
			cout<<"X or O? ";
			cin>>player;
		} while(player!='X'&&player!='x'&&player!='o'&&player!='O');
		switch(player)
		{
		case 'x':
			enemy = 'o';
			break;
		case 'X':
			enemy = 'O';
			break;
		case 'o':
			enemy = 'x';
			break;
		case 'O':
			enemy = 'X';
			break;
		default:
			system("Color 04");
			cout<<"Error in first switch in main:Player symbol selection"<<endl;
			break;
		}
		ShowTable(table,player,enemy);
		do {
			cout<<endl<<"Make a move"<<endl;
			do {
				do {
					cout<<"Letter:";
					cin>>let;
				} while(let!='A'&&let!='B'&&let!='C'&&let!='a'&&let!='b'&&let!='c');
				do {
					cout<<"Number:";
					cin>>num;
				} while(num<0||num>3);
				x=num-1;
				switch(let)
				{
				case 'A':
				case 'a':
					y=0;
					break;
				case 'B':
				case 'b':
					y=1;
					break;
				case 'C':
				case 'c':
					y=2;
					break;
				default:
					system("Color 04");
					cout<<"Error in second switch in main:Player column selection"<<endl;
					break;
				}
			} while(table[x][y]!=' ');
			table[x][y] = player;
			ShowTable(table,player,enemy);
			CheckRoom(table);
			if(CheckForWin(table,player,enemy)==0)
				MakeMove(table,enemy,player);
			cout<<endl;
			ShowTable(table,player,enemy);
		} while(CheckForWin(table,player,enemy)==0&&CheckRoom(table));
		cout<<endl;
		switch(CheckForWin(table,player,enemy))
		{
		case 1:
			cout<<"\033[1;32m"<<"You Win";
			break;
		case 0:
			cout<<"\033[1;33m"<<"It's a Tie";
			break;
		case -1:
			cout<<"\033[1;31m"<<"You Lost";
			break;
		default:
			system("Color 04");
			cout<<"Error in third switch in main:Check for victory"<<endl;
			break;
		}
		cout<<"\033[0m";
		char pa='a';
		do {
			cout<<endl<<endl<<"Play Again?(y/n): ";
			cin>>pa;
			if(pa=='y'||pa=='Y')
				v=1;
			else if(pa=='n'||pa=='N')
				v=0;
		} while(pa!='n'&&pa!='N'&&pa!='y'&&pa!='Y');
	}
	return 0;
}
