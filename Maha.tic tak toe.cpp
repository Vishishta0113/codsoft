#include <stdio.h>
#include <stdlib.h>

// Function declarations
void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
int makeMove(char board[3][3], char player, int row, int col);
int checkWin(char board[3][3], char player);
int isBoardFull(char board[3][3]);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    int row, col;
    int gameOver = 0;

    // Initialize the board
    initializeBoard(board);

    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1: X\nPlayer 2: O\n");

    while (!gameOver) {
        // Display current board state
        displayBoard(board);

        // Get player move
        printf("\nPlayer %c's turn\n", currentPlayer);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);

        // Adjust input to array indices
        row--;
        col--;

        // Validate and make move
        if (row >= 0 && row < 3 && col >= 0 && col < 3) {
            if (makeMove(board, currentPlayer, row, col)) {
                // Check for win
                if (checkWin(board, currentPlayer)) {
                    displayBoard(board);
                    printf("\nPlayer %c wins!\n", currentPlayer);
                    gameOver = 1;
                }
                // Check for draw
                else if (isBoardFull(board)) {
                    displayBoard(board);
                    printf("\nGame is a draw!\n");
                    gameOver = 1;
                }
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            } else {
                printf("\nThat position is already taken! Try again.\n");
            }
        } else {
            printf("\nInvalid input! Row and column must be between 1 and 3.\n");
        }
    }

    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int makeMove(char board[3][3], char player, int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return 1;
    }
    return 0;
}

int checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    
    return 0;
}

int isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}
