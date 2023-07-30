#include <iostream>
using namespace std;
const int R = 6;
const int C = 7;
/* Prints grid to the screen */
void displaySquare(char square[][C]) {

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << square[i][j] << " ";
		cout << endl;
	}
	cout << "0 1 2 3 4 5 6\n";
	
}
/* initilize the square as all elements are set to be .*/
void initSquare(char square[][C], int pos[]){

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			square[i][j] = '.';
	for (int i = 0; i < C; i++)
		pos[i] = R-1;
}

/* Performs the task of update the square, fill the position with specific mark and update the available position for inputted column
*/
bool updateSquare(char square[][C], int pos[], int col, char player) {

	int row = pos[col];
	square[row][col] = player;  // fill the position with player
	pos[col]--;  // update the available position for col column
	// try to find the possible line with 4 marks
	int count = 0;
	for (int i = 0; i < R; i++)
		if (square[i][col] == player)
		{
			count++;
			if (count >= 4)
				return true;
			}
		else
			count = 0;
	count = 0;
	for (int j = 0; j < C; j++)
		if (square[row][j] == player)
		{
			count++;
			if (count >= 4)
				return true;
		}
		else
			count = 0;
	count = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if ((i + j) == (row + col))
				if (square[i][j] == player)
					{
						count++;
						if (count >= 4)
							return true;
					}
				else
					count = 0;
	count = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (i - j == row - col)
			{
				if (square[i][j] == player)
				{
					count++;
					if (count >= 4)
						return true;
				}
				else
					count = 0;
			}
	return false;
}

/* Returns an boolean value, denoting the state of the square
true: square is not full.
false: square is full. */
bool squareState(char square[][C]) {

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (square[i][j] == '.')
				return true;
	return false;
}


int main() {

	char square[R][C];
	int pos[C];
	char p;
	int col, count = 1;
	bool fin = false;
	initSquare(square,pos);
	displaySquare(square);
	while (squareState(square)&!fin){
		if (count % 2)
			p = 'X';
		else
			p = 'O';
		cout << "Player " << p << ", make a move (0-6): ";
		cin >> col;
		while (col >= C || col < 0 || pos[col]<0)
		{
			if (col >= C || col < 0)
				cout << "Invalid move. Try again!\n";
			else
				cout << "Column full. Try again!\n";
			cout << "Player " << p << ", make a move (0-6): ";
			cin >> col;
		}
		fin = updateSquare(square, pos, col, p);
		displaySquare(square);
		count++;
	}
	if (fin)
		cout << "Player " << p << " wins!\n";
	else
		cout << "Draw game!\n";
	system("pause");
	return 0;
}
