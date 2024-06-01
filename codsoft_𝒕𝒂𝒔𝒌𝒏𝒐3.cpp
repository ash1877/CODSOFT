#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "--|---|--\n";
    }
    cout << "\n";
}

bool isMoveValid(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

bool isWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playerMove() {
    int row, col;
    do {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        row--; col--; // Adjust for 0-based indexing
    } while (!isMoveValid(row, col));
    board[row][col] = currentPlayer;
}

void playGame() {
    initializeBoard();
    currentPlayer = 'X';
    while (true) {
        displayBoard();
        playerMove();
        if (isWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (isDraw()) {
            displayBoard();
            cout << "The game is a draw!\n";
            break;
        }
        switchPlayer();
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    return 0;
}
