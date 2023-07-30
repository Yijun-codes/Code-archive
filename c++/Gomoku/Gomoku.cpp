#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int N = 13;

/* Prints square to the screen */
void displaySquare(char square[][N]) {

	cout << "   A B C D E F G H I J K L M\n";
	for (int i = 0; i < N; i++)
	{
		cout << setw(2) << right << i;
		for (int j = 0; j < N; j++)
			cout << " " << square[i][j];
		cout << endl;
	}
}



/* Returns true if position pos of grid is filled with @ or X; returns false
otherwise. */
bool isFilled(char square[][N], int row, int col) {
	return (square[row][col] != '.');
}

/* initilize the square as all elements are set to be .*/
void initSquare(char square[][N]) {

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			square[i][j] = '.';
}
/* Performs the task of update the square, fill a line with X when there are 2 @
*/
void updateSquare(char square[][N], int row, int col, int p) {

	if (p == 1) square[row][col] = 'O';
	else square[row][col] = 'X';

}

/* Returns an boolean denoting the state of square listed
below:
false: square is full filled.
true: square is not finished.
*/
int squareState(char square[][N], int N) {
	bool full = true;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (square[i][j] == '.')
				full = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			if (square[i][j] == '.')continue;
			for (int r = i; r < N; r++) {
				if (square[r][j] == square[i][j])cnt++;
				else break;
			}
			if (cnt > 4) return 1;
			else cnt = 0;

			for (int c = j; c < N; c++) {
				if (square[i][c] == square[i][j])cnt++;
				else break;
			}
			if (cnt > 4) return 1;
			else cnt = 0;

			for (int c = j, r = i; c < N, r < N; c++, r++) {
				if (square[r][c] == square[i][j])cnt++;
				else break;
			}
			if (cnt > 4) return 1;
			else cnt = 0;

			for (int c = j, r = i; c < N, r >= 0; c++, r--) {
				if (square[r][c] == square[i][j])cnt++;
				else break;
			}
			if (cnt > 4) return 1;
			else cnt = 0;
		}
	}
	if (full) return 2;

	return 0;
}

int main() {

	char square[N][N];
	int row, col, p = 1;
	char colX;
	initSquare(square);
	displaySquare(square);
	int stat = squareState(square, N);
	while (stat==0) {
		cout << "Player " << ((p == 1) ? "O" : "X") << ", make a move (e.g., A1): ";
		cin >> colX >> row;
		col = (int)(colX - 'A');
		while (row >= N || row < 0 || col >= N || col < 0 || isFilled(square, row, col))
		{
			cout << "Invalid. Try again!\n";
			cout << "Player " << ((p==1)?"O":"X") << ", make a move: ";
			cin >> colX >> row;
		}
		updateSquare(square, row, col, p);
		displaySquare(square);
		stat = squareState(square, N);
		if (stat == 0)p = 3 - p;
	}
	if (stat == 2) cout << "Draw game!\n";
	else if (stat == 1) {
		if (p == 1) cout << "Player O wins!\n";
		else cout << "Player X wins!\n";
	}
	system("pause");
	return 0;
}