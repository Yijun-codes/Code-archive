#include <iostream>
#include <string>
using namespace std;

/* Prints grid to the screen */
void displayGrid(long long grid) {
	// Horizontal lines occupy three spaces (---)
	// Diagonal lines (/ or \) occupy one space
	string g1 = "   ", g2 = "   ", g3 = " ", g4 = " ", g5 = " ", g6 = " ";
	string g7 = " ", g8 = "   ", g9 = "   ", g10 = " ", g11 = " ", g12 = " ";
	string g13 = " ", g14 = " ", g15 = "   ", g16 = "   ";
	int p1, p2;

	p2 = grid % 10;             // Player 2's score
	p1 = grid / 10 % 10;        // Player 1's score

	if (grid / 100000000000000000LL % 10 != 0)
		g1 = "---";
	if (grid / 10000000000000000LL % 10 != 0)
		g2 = "---";
	if (grid / 1000000000000000LL % 10 != 0)
		g3 = "/";
	if (grid / 100000000000000LL % 10 != 0)
		g4 = "\\";
	if (grid / 10000000000000LL % 10 != 0)
		g5 = "/";
	if (grid / 1000000000000LL % 10 != 0)
		g6 = "\\";
	if (grid / 100000000000LL % 10 != 0)
		g7 = "/";
	if (grid / 10000000000LL % 10 != 0)
		g8 = "---";
	if (grid / 1000000000 % 10 != 0)
		g9 = "---";
	if (grid / 100000000 % 10 != 0)
		g10 = "/";
	if (grid / 10000000 % 10 != 0)
		g11 = "\\";
	if (grid / 1000000 % 10 != 0)
		g12 = "/";
	if (grid / 100000 % 10 != 0)
		g13 = "\\";
	if (grid / 10000 % 10 != 0)
		g14 = "/";
	if (grid / 1000 % 10 != 0)
		g15 = "---";
	if (grid / 100 % 10 != 0)
		g16 = "---";

	cout << "    o" << g1 << "o" << g2 << "o\n";
	cout << "   " << g3 << " " << g4 << " " << g5 << " " << g6 << " " << g7 << "\n";
	cout << "  o" << g8 << "o" << g9 << "o\n";
	cout << " " << g10 << " " << g11 << " " << g12 << " " << g13 << " " << g14 << "      Player 1 score: " << p1 << endl;
	cout << "o" << g15 << "o" << g16 << "o       Player 2 score: " << p2 << endl;
}

/* Returns true if position pos of grid is filled with a line; returns false
otherwise. */
bool isFilled(long long grid, int pos) {
	grid /= 100;
	// Shift position pos to the units-digit
	for (int i = 0; i < 16 - pos; i++)
		grid /= 10;
	return (grid % 10 != 0);
}

/* Returns the score of Player p in grid. */
int playerScore(long long grid, int p) {
	int score = 0;

	if (p == 1)
		score = grid / 10 % 10;
	else
		score = grid % 10;;

	return score;
}

/* Performs the task of Player p putting a line in position pos in grid. The
grid should get updated, and if any new triangles are formed, the score of
Player p should be incremented. Note that putting one line can form at most
two triangles. The reference parameter grid should store the updated grid
when the function returns. To determine if a new triangle is formed, calling
the isFilled(...) function is useful.
*/
void updateGrid(long long &grid, int pos, int p) {

	long long inc = 100;
	int point_r = playerScore(grid, 3-p); // point of another player
	for (int i = 0; i < 16 - pos; i++)
		inc *= 10;
	grid += inc;  //add new egde
	//compute the total number of complete triangles in grid
	int point = 0; 
	if (isFilled(grid, 1) && isFilled(grid, 4) && isFilled(grid, 5)) // triangle 1
		point += 1;
	if (isFilled(grid, 5) && isFilled(grid, 6) && isFilled(grid, 9)) // triangle 2
		point += 1;
	if (isFilled(grid, 7) && isFilled(grid, 6) && isFilled(grid, 2)) // triangle 3
		point += 1;
	if (isFilled(grid, 3) && isFilled(grid, 4) && isFilled(grid, 8)) // triangle 4
		point += 1;
	if (isFilled(grid, 10) && isFilled(grid, 11) && isFilled(grid, 15)) // triangle 5
		point += 1;
	if (isFilled(grid, 11) && isFilled(grid, 12) && isFilled(grid, 8)) // triangle 6
		point += 1;
	if (isFilled(grid, 12) && isFilled(grid, 16) && isFilled(grid, 13)) // triangle 7
		point += 1;
	if (isFilled(grid, 9) && isFilled(grid, 14) && isFilled(grid, 13)) //triangle 8
		point += 1;
	if (p == 1) // update the score of player p
		grid = grid - (grid % 100) + (point - point_r) * 10 + (grid % 10);
	else
		grid = grid - (grid % 10) + (point - point_r);
}

/* Returns an integer 0, 1, 2, or 3, denoting the game state of grid listed
below:
0: Game is finished and is a draw.
1: Game is finished and Player 1 wins.
2: Game is finished and Player 2 wins.
3: Game is not yet finished. (That is, grid is not full.)
*/
int gameState(long long grid) {

	if (playerScore(grid, 1) + playerScore(grid, 2) < 8)
		return 3;
	else if (playerScore(grid, 1) < playerScore(grid, 2))
		return 2;
	else if (playerScore(grid, 1) > playerScore(grid, 2))
		return 1;
	else
		return 0;
}

int main() {

	long long grid = 0;
	int player = 1, pos;
	int times = 0; // the times of consecutive turns of the same player
	int point_o, point_n; // old point and new point
	while (gameState(grid) == 3)
	{
		displayGrid(grid);
		point_o = playerScore(grid, player);
		cout << "Player " << player << ", make your move (1-16): ";
		cin >> pos;
		// validate the input
		while (pos < 1 || pos > 16 || (pos - int(pos) != 0.0) || isFilled(grid, pos))
		{
			cout << "Invalid move! Try again." << endl;
			cout << "Player " << player << ", make your move (1-16): ";
			cin >> pos;
		}
		times += 1;
		updateGrid(grid, pos, player);
		point_n = playerScore(grid, player);
		// if point is not changed, or number of consecutive turn reached 2, switch player
		if (point_o == point_n)
		{
			player = 3 - player;  // change player
			times = 0;
		}
		else
			if (times == 2)
			{
				player = 3 - player;   // change player
				times = 0;
			}
	}
	displayGrid(grid);
	if (gameState(grid) == 0)
		cout << "Draw game!\n";
	else if (gameState(grid) == 1)
		cout << "Player 1 wins!\n";
	else
		cout << "Player 2 wins!\n";

    system("pause");

	return 0;
}
