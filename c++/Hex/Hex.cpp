#include <iostream>
using namespace std;
const int N = 11;

/* Initialize the grid */
void initVectors(char board[][N])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			board[i][j] = '.';
		}
}

/* Prints grid to the screen */
void printFig(char board[][N])
{
	cout << "  A B C D E F G H I J K" << endl;
	for (int i = 0; i < N; i++)
	{
		if (i<N-1) cout << " ";
		cout << i;
		for (int j = 0; j < i; j++)
			cout << " ";
		for (int j = 0; j < N; j++)
			cout << " " << board[i][j];
		cout << endl;
	}
}


/* Compute the reachability of the current player along the row/column */
void spreadTrue(char board[][N], bool connect[][N], int row, int col, char player)
{
	if (row>0)
		if (board[row-1][col]==player)
			connect[row-1][col]=true;
	if (row<N-1)
		if (board[row+1][col]==player)
                        connect[row+1][col]=true;
	if (col>0)
                if (board[row][col-1]==player)
                        connect[row][col-1]=true;
        if (col<N-1)
                if (board[row][col+1]==player)
                        connect[row][col+1]=true;
	if ((row>0) && (col<N-1))
                if (board[row-1][col+1]==player)
                        connect[row-1][col+1]=true;
        if ((row<N-1) && (col>0))
                if (board[row+1][col-1]==player)
                        connect[row+1][col-1]=true;

}


/* Update the grid after a player move and check if that player wins */
bool updateAndCheckWin(char board[][N], int row, int col, char player)
{
	bool connect[N][N] = {0};
	board[row][col] = player;
	connect[row][col] = true;
	int countChange = 1;
	int oldCount=0;
	int newCount=1;
	while (countChange>0)
	{
		oldCount = newCount;
		newCount = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (connect[i][j])
					spreadTrue(board,connect,i,j,player);
		for (int i = 0; i < N; i++)
                        for (int j = 0; j < N; j++)
                                newCount += connect[i][j]?1:0;
		countChange = newCount-oldCount;
	}
	bool border1 = false;
	bool border2 = false;
	if (player == 'O')
		for (int i = 0; i < N; i++)
		{
			border1 = border1||connect[i][0];
			border2 = border2||connect[i][N-1];
		}
	else
		for (int i = 0; i < N; i++)
                {
                        border1 = border1||connect[0][i];
                        border2 = border2||connect[N-1][i];
                }
	return border1&&border2;
}



int main()
{
	char board[N][N];
	bool win = false;
	initVectors(board);
	printFig(board);
	char player[2] = {'O','X'};
	int players = 1; //'0' for player 'O', '1' for player 'X'
	char col_letter;
	int row_dim, col_dim;
	do
	{
		players = (players+1)%2;
		cout << "Player " << player[players] << ", make our move (e.g., A1): ";
		cin >> col_letter >> row_dim;
		col_dim = static_cast<int>(col_letter - 'A');
		while( col_dim>10 || col_dim<0 || row_dim > 10 || row_dim < 0 || board[row_dim][col_dim]!='.' )
		{
			cout << "Invalid move. Enter again!\n";
			cout << "Player " << player[players] << ", make our move (e.g., A1): ";
			cin >> col_letter >> row_dim;
			col_dim = static_cast<int>(col_letter - 'A');
		}
		win = updateAndCheckWin(board, row_dim,col_dim,player[players]);
		printFig(board);
	}while(!win);
	if (win)
		cout << "Player " << player[players] << " wins!\n";
	while (1)
	{
		cout << "Player " << player[players] << ", make our move: ";
                cin >> col_letter >> row_dim;
	}
	system("pause");
	return 0;
}
