#include <iostream>
#include <string>
#include <cstring>
#include "raylib.h"
// STATE & GLOBALS.
    // x is true and o is false.
    static bool player = true;
    static bool playing = true;
    static int selection; 
// Board (Multi-Dimensional Array).
    char board[3][3] = {
        {'#','#','#'},
        {'#','#','#'},
        {'#','#','#'},
    };

void boardState() {
    // Print the board.
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            std::cout << board[i][j] << " ";
        };
        std::cout << std::endl;
    };
};

bool validSelectionCheck(int selection) {
    // Check for valid range.
    if( selection > 9 || selection < 0) {
        std::cout << "Your selection isn't valid!" << '\n';
        return false;
    };
    return true;
};

// Update board with selection.
void select(int selection) {
    validSelectionCheck(selection);
    switch(selection) {
        case 1: 
            // Check if space is already taken.
            if (board[2][0] == 'x' || board[2][0] == 'o') {
                std::cout << "That space is already taken!" << '\n';
                break;
            };
            board[2][0] = player ? 'x' : 'o';
            break;
        case 2: 
            // Check if space is already taken.
            if (board[2][1] == 'x' || board[2][1] == 'o') {
                std::cout << "That space is already taken!" << '\n';
                break;
            };
            board[2][1] = player ? 'x' : 'o';
            break;
        case 3:
            // Check if space is already taken.
            if (board[2][2] == 'x' || board[2][2] == 'o') {
                std::cout << "That space is already taken!" << '\n';
                break;
            };
            board[2][2] = player ? 'x' : 'o';
            break;
        case 4:
            // Check if space is already taken.
            if (board[1][0] == 'x' || board[1][0] == 'o') {
                std::cout << "That space is already taken!" << '\n';
                break;
            };
            board[1][0] = player ? 'x' : 'o';
            break;
        case 5: 
            // Check if space is already taken.
            if (board[1][1] == 'x' || board[1][1] == 'o') {
                std::cout << "That space is already taken!" << '\n';
                break;
            };
            board[1][1] = player ? 'x' : 'o';
            break;
        case 6:
            // Check if space is already taken.
            if (board[1][2] == 'x' || board[1][2] == 'o') {
                std::cout << "That space is already taken!" << '\n';
                break;
            };
            board[1][2] = player ? 'x' : 'o';
            break;
        case 7:
            // Check if space is already taken.
            if (board[0][0] == 'x' || board[0][0] == 'o') {
                std::cout << "That space is already taken!" << '\n';
                break;
            };
            board[0][0] = player ? 'x' : 'o';
            break;
        case 8: 
            // Check if space is already taken.
            if (board[0][1] == 'x' || board[0][1] == 'o') {
                break;
            };
            board[0][1] = player ? 'x' : 'o';
            break;
        case 9:
            // Check if space is already taken.
            if (board[0][2] == 'x' || board[0][2] == 'o') {
                std::cout << "That space is already taken!" << '\n';
                break;
            };
            board[0][2] = player ? 'x' : 'o';
            break;
    };   
};

// Win Conditions
// Refactor? O(N^2) is slug-ish but not working with large data set.
void checkWin() {
    const char* x = "xxx";
    const char* o = "ooo";
    // Horizontal win.
    char row1[4];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            row1[j] = board[0][j];
        };
    };
    char row2[4];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            row2[j] = board[1][j];
        };
    };
    char row3[4];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            row3[j] = board[2][j];
        };
    };
    // Pattern match check for each row (strstr requires null termination).
    // -- X --
    char* x_row_win = strstr(row1, x);
    char* x_row_win1 = strstr(row2, x);
    char* x_row_win2 = strstr(row3, x);
    if (x_row_win || x_row_win1 || x_row_win2) {
        boardState();
        std::cout << "player X has won!" << '\n';
        playing = false;
    };
    // -- O --
    char* o_row_win = strstr(row1, o);
    char* o_row_win1 = strstr(row2, o);
    char* o_row_win2 = strstr(row3, o);
    if (o_row_win || o_row_win1 || o_row_win2) {
        boardState();
        std::cout << "player O has won!" << '\n';
        playing = false;
    };
    // Vertical win [0][1][1][2][2][3].
    // Pattern match check for each column (strstr?).
    char col1[4];
    for(int i=0; i<3; i++) {
        col1[i] = board[i][0];
    };
    char col2[4];
    for(int i=0; i<3; i++) {
        col2[i] = board[i][1];
    };
    char col3[4];
    for(int i=0; i<3; i++) {
        col3[i] = board[i][2];
    };
    // -- X --
    char* x_col_win = strstr(col1, x);
    char* x_col_win1 = strstr(col2, x);
    char* x_col_win2 = strstr(col3, x);
    if (x_col_win || x_col_win1 || x_col_win2) {
        boardState();
        std::cout << "Player X has won!" << '\n';
        playing = false;
    };
    // -- O --
    char* o_col_win = strstr(col1, o);
    char* o_col_win1 = strstr(col2, o);
    char* o_col_win2 = strstr(col3, o);
    if (o_col_win || o_col_win1 || o_col_win2) {
        boardState();
        std::cout << "Player O has won!" << '\n';
        playing = false;
    };
    // Diagonal win
    /* {[0][0],[1][1],[2][2] */
    char diag[4];
    for(int i=0; i<3; i++) {
        diag[i] = board[i][i];
    };

    char reverse_diag[4];
    for(int i=2; i>=0; i--) {
        switch(i) {
            case 2: 
                reverse_diag[i] = board[i][0];
                break;
            case 1:
                reverse_diag[i] = board[i][1];
                break;
            case 0: 
                reverse_diag[i] = board[i][2];
                break;
        }
    };
    if (strstr(diag, x) || strstr(reverse_diag, x)) {
        boardState();
        std::cout << "Player X has won!" << '\n';
        playing = false;
    };
    if (strstr(diag, o) || strstr(reverse_diag, o)) {
        boardState(); 
        std::cout << "Player O has won!" << '\n';
        playing = false;
    };
   
    // Tie
    int counter = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (board[i][j] == 'x' || board[i][j] == 'o') {
                counter += 1;
            };
            if(counter == 9 && playing) {
                std::cout << "It's a tie!" << '\n';
                playing = false;
            };
        };
    };
};

void gameLoop(bool exitWindow, bool exitRequest) {
    while(!exitWindow) {
        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitRequest = true;
        if (exitRequest) {
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitRequest = false;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
            if (exitRequest) {
                DrawRectangle(0, 100, 450, 200, BLACK);
                DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
            } else DrawText("Try to close the window to get confirmation message!", 120, 200, 20, LIGHTGRAY);
        EndDrawing();
        boardState();
        std::cout << "Please select a position 1-9 player: " << (player ? "x" : "o") << '\n';
        std::cin >> selection;
        select(selection);
        checkWin();
        player = !player;
    };
    CloseWindow();
    playing = false;
};

int main() {
    InitWindow(800, 450, "raylib [core] example - basic window");
    // SetTargetFPS(24); 
    std::cout << "Hello!, Welcome to tic-tac-toe." << '\n';
    bool exitWindow = false;
    bool exitRequest = false;
    gameLoop(exitWindow, exitRequest);
    return 0; 
};

