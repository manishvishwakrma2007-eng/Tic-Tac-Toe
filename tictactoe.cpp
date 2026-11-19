#include <iostream>
#include <limits>
using namespace std;

char board[3][3];

void initializeBoard() {
    char n = '1';
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = n++;
}

void displayBoard() {
    cout << "\n       TIC TAC TOE\n\n";
    for (int i = 0; i < 3; ++i) {
        cout << "       ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << '\n';
        if (i < 2) cout << "      ---+---+---\n";
    }
    cout << '\n';
}

bool checkWin(char p) {
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return true;
    for (int j = 0; j < 3; ++j)
        if (board[0][j] == p && board[1][j] == p && board[2][j] == p)
            return true;
    return (board[0][0] == p && board[1][1] == p && board[2][2] == p) ||
           (board[0][2] == p && board[1][1] == p && board[2][0] == p);
}

bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
    return true;
}

void playGame() {
    initializeBoard();
    char player = 'X';

    while (true) {
        displayBoard();
        int pos;
        cout << "Player " << player << ", enter position (1-9): ";
        if (!(cin >> pos)) {
            cout << "Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (pos < 1 || pos > 9) {
            cout << "Choose a position from 1 to 9.\n";
            continue;
        }

        int row = (pos - 1) / 3;
        int col = (pos - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Position already occupied. Try again.\n";
            continue;
        }

        board[row][col] = player;
        if (checkWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            break;
        }
        if (isDraw()) {
            displayBoard();
            cout << "Game draw!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

int main() {
    char replay;
    cout << "============================\n";
    cout << "       TIC TAC TOE\n";
    cout << "============================\n";
    do {
        playGame();
        cout << "\nPlay again? (Y/N): ";
        cin >> replay;
    } while (replay == 'Y' || replay == 'y');

    cout << "Thanks for playing!\n";
    return 0;
}
