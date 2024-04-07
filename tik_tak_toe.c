#include <stdio.h>

char board[3][3]; // 3x3 Tic-Tac-Toe board

// Function to initialize the board
void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void display_board() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if there's a winner
char check_winner() {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    // Check if the game is a draw
    int draw = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                draw = 0;
                break;
            }
        }
        if (!draw) break;
    }
    if (draw) return 'D'; // 'D' represents a draw

    return ' '; // Game is still ongoing
}

// Function to get player's move
void get_move(char player) {
    int row, col;
    printf("Player %c's turn. Enter row and column (1-3): ", player);
    scanf("%d %d", &row, &col);
    row--;
    col--;

    // Check if the selected cell is empty
    if (board[row][col] != ' ') {
        printf("Invalid move. Cell already taken. Try again.\n");
        get_move(player);
    } else {
        board[row][col] = player;
    }
}

int main() {
    char player = 'X'; // Player X starts the game
    char winner = ' ';

    initialize_board();
    display_board();

    // Main game loop
    while (1) {
        get_move(player);
        display_board();
        winner = check_winner();

        if (winner != ' ') {
            if (winner == 'D') {
                printf("It's a draw!\n");
            } else {
                printf("Player %c wins!\n", winner);
            }
            break;
        }

        // Switch player
        if (player == 'X') player = 'O';
        else player = 'X';
    }

    return 0;
}

