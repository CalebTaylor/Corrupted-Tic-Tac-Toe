#include <iostream>

using namespace std;

void initializeBoard();
void initializeLoseComboX();
void initializeLoseComboO();
void turn(int playerNum);
int checkWin();
void printBoard();

//functions used to debug
void printLoseComboO();
void printLoseComboX();

char board[9];
char loseComboX[7][3];
char loseComboO[7][3];

int main()
{
	int winner = 0;
	initializeBoard();
	initializeLoseComboO();
	initializeLoseComboX();

	printBoard();

	//alternate player's turns until one player has won
	while(1)
	{
		turn(1);
		winner = checkWin();
		if(winner != 0)
		{
			break;
		}
		turn(2);
		winner = checkWin();
		if(winner != 0)
		{
			break;
		}
	}
	cout << "Player " << winner << " wins!!" << endl;
	return 0;
}

//functions used to initialize 
void initializeBoard()
{
	board[0] = '0';
	board[1] = '1';
	board[2] = '2';
	board[3] = '3';
	board[4] = '4';
	board[5] = '5';
	board[6] = '6';
	board[7] = '7';
	board[8] = '8';
}

void initializeLoseComboX()
{
	loseComboX[0][0] = 'x';
	loseComboX[0][1] = 'X';
	loseComboX[0][2] = 'X';

	loseComboX[1][0] = 'X';
	loseComboX[1][1] = 'x';
	loseComboX[1][2] = 'X';

	loseComboX[2][0] = 'X';
	loseComboX[2][1] = 'X';
	loseComboX[2][2] = 'x';

	loseComboX[3][0] = 'x';
	loseComboX[3][1] = 'x';
	loseComboX[3][2] = 'X';

	loseComboX[4][0] = 'X';
	loseComboX[4][1] = 'x';
	loseComboX[4][2] = 'x';

	loseComboX[5][0] = 'x';
	loseComboX[5][1] = 'X';
	loseComboX[5][2] = 'x';

	loseComboX[6][0] = 'x';
	loseComboX[6][1] = 'x';
	loseComboX[6][2] = 'x';
}

void initializeLoseComboO()
{
	loseComboO[0][0] = 'o';
	loseComboO[0][1] = 'O';
	loseComboO[0][2] = 'o';

	loseComboO[1][0] = 'O';
	loseComboO[1][1] = 'o';
	loseComboO[1][2] = 'O';

	loseComboO[2][0] = 'O';
	loseComboO[2][1] = 'O';
	loseComboO[2][2] = 'o';

	loseComboO[3][0] = 'o';
	loseComboO[3][1] = 'o';
	loseComboO[3][2] = 'O';

	loseComboO[4][0] = 'O';
	loseComboO[4][1] = 'o';
	loseComboO[4][2] = 'o';

	loseComboO[5][0] = 'o';
	loseComboO[5][1] = 'O';
	loseComboO[5][2] = 'o';

	loseComboO[6][0] = 'o';
	loseComboO[6][1] = 'o';
	loseComboO[6][2] = 'o';
}


//functions used during gameplay
void printBoard()
{
	cout << "   |    |   " << endl;
	for(int i = 0; i < 9; i++)
	{
		cout << " " << board[i]; 
		if(i == 2 || i == 5)
		{
			cout << endl << "___|____|___" << endl;
		}
		else if(i != 8)
		{
			cout << " | ";
		}
	}
	cout << endl << "   |    |   " << endl;
}

void turn(int playerNum)
{
	int choice;
	cout << "It is player number " << playerNum << "\'s turn" << endl;
	cout << "Please enter the position you would like to play" << endl;
	cin >> choice;

	while(board[choice] == 'x' || board[choice] == 'o' || choice > 9 || choice < 0)
	{
		cout << "Invalid entry, please try again" << endl;
		cout << "Please enter the position you would like to play" << endl;
		cin >> choice;
	}

	//determines what piece is placed in the selected spot
	if(board[choice] == 'X')
	{
		board[choice] = 'o';
	}
	else if(board[choice] == 'O')
	{
		board[choice] = 'x';
	}
	else if(playerNum == 1)
	{
		board[choice] = 'X';
	}
	else if(playerNum == 2)
	{
		board[choice] = 'O';
	}

	printBoard();
}

int checkWin()
{
	if((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') ||
		(board[3] == 'X' && board[4] == 'X' && board[5] == 'X') ||
		(board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
		(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') ||
		(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
		(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
		(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
		(board[2] == 'X' && board[4] == 'X' && board[6] == 'X'))
	{
		return(1);
	}
	else if((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') ||
			(board[3] == 'O' && board[4] == 'O' && board[5] == 'O') ||
			(board[6] == 'O' && board[7] == 'O' && board[8] == 'O') ||
			(board[0] == 'O' && board[3] == 'O' && board[6] == 'O') ||
			(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') ||
			(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
			(board[0] == 'O' && board[4] == 'O' && board[8] == 'O') ||
			(board[2] == 'O' && board[4] == 'O' && board[6] == 'O'))
	{
		return(2);
	}
	else
	{
		for(int i = 0; i < 7; i++)
		{
			if((board[0] == loseComboX[i][0] && board[1] == loseComboX[i][1] && board[2] == loseComboX[i][2]) ||
				(board[3] == loseComboX[i][0] && board[4] == loseComboX[i][1] && board[5] == loseComboX[i][2]) ||
				(board[6] == loseComboX[i][0] && board[7] == loseComboX[i][1] && board[8] == loseComboX[i][2]) ||
				(board[0] == loseComboX[i][0] && board[3] == loseComboX[i][1] && board[6] == loseComboX[i][2]) ||
				(board[1] == loseComboX[i][0] && board[4] == loseComboX[i][1] && board[7] == loseComboX[i][2]) ||
				(board[2] == loseComboX[i][0] && board[5] == loseComboX[i][1] && board[8] == loseComboX[i][2]) ||
				(board[0] == loseComboX[i][0] && board[4] == loseComboX[i][1] && board[8] == loseComboX[i][2]) ||
				(board[2] == loseComboX[i][0] && board[4] == loseComboX[i][1] && board[6] == loseComboX[i][2]))
			{
				return(2);
			}
			else if((board[0] == loseComboO[i][0] && board[1] == loseComboO[i][1] && board[2] == loseComboO[i][2]) ||
					(board[3] == loseComboO[i][0] && board[4] == loseComboO[i][1] && board[5] == loseComboO[i][2]) ||
					(board[6] == loseComboO[i][0] && board[7] == loseComboO[i][1] && board[8] == loseComboO[i][2]) ||
					(board[0] == loseComboO[i][0] && board[3] == loseComboO[i][1] && board[6] == loseComboO[i][2]) ||
					(board[1] == loseComboO[i][0] && board[4] == loseComboO[i][1] && board[7] == loseComboO[i][2]) ||
					(board[2] == loseComboO[i][0] && board[5] == loseComboO[i][1] && board[8] == loseComboO[i][2]) ||
					(board[0] == loseComboO[i][0] && board[4] == loseComboO[i][1] && board[8] == loseComboO[i][2]) ||
					(board[2] == loseComboO[i][0] && board[4] == loseComboO[i][1] && board[6] == loseComboO[i][2]))
			{
				return(1);
			}
		}
			
		return(0);
	}
}


//debug functions
void printLoseComboO()
{
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << loseComboO[i][j] << "	";
		}
		cout << endl << endl;
	}
}

void printLoseComboX()
{
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << loseComboX[i][j] << "	";
		}
		cout << endl << endl;
	}
}