#include <iostream>
#include <vector>
using namespace std;

// Define the board as a vector of vectors of chars
vector<vector<char>> board(3,vector<char>(3, ' '));

// Function to print the board
void printBoard() {
    for (int i = 0; i < 3; i++) {
        cout<<"|";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " |";
        }
        cout<<"\n|--|--|--|";
        cout<<endl;
    }
}

// Function to check if there is a winner
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

int main() {
    int move;
    bool player1Turn = true;

    while (true) {
        printBoard();
        cout << (player1Turn ? "Player 1's turn: " : "Player 2's turn: ");
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move. Try again." <<endl;
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] != ' ') {
            cout << "Cell already occupied. Try again." << endl;
            continue;
        }

        board[row][col] = player1Turn ? 'X' : 'O';

        if (checkWin()) {
            printBoard();
            cout << (player1Turn ? "Player 1 wins!" : "Player 2 wins!") << endl;
            break;
        }

        player1Turn = !player1Turn;
    }

    return 0;
}