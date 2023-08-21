#include <iostream>
#include <string>
#include <cstring>
// STATE & GLOBALS.
    // x is true and o is false.
    bool player = true;
    bool playing = true;
    int selection; 
// Board (Multi-Dimensional Array).
    char board[3][3] = {
        {'#','#','#'},
        {'#','#','#'},
        {'#','#','#'},
    };

bool validSelectionCheck(int selection) {
    // Check for valid range.
    if( selection > 9 || selection < 0) {
        std::cout << "Your selection isn't valid!" << '\n';
        return false;
    };
    // Check if space is already taken.
    return true;
};

void select(int selection) {
    validSelectionCheck(selection);
    switch(selection) {
        case 1: 
            board[2][0] = player ? 'x' : 'o';
            break;
        case 2: 
            board[2][1] = player ? 'x' : 'o';
            break;
        case 3:
            board[2][2] = player ? 'x' : 'o';
            break;
        case 4:
            board[1][0] = player ? 'x' : 'o';
            break;
        case 5: 
            board[1][1] = player ? 'x' : 'o';
            break;
        case 6:
            board[1][2] = player ? 'x' : 'o';
            break;
        case 7:
            board[0][0] = player ? 'x' : 'o';
            break;
        case 8: 
            board[0][1] = player ? 'x' : 'o';
            break;
        case 9:
            board[0][2] = player ? 'x' : 'o';
            break;
    };   
};

// Refactor? O(N^2) sucks
void checkWin() {
    const char* x = "xxx";
    const char* o = "ooo";
    // Horizontal win.
    char row1[3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            row1[j] = board[0][j];
        };
    };
    char row2[3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            row2[j] = board[1][j];
        };
    };
    char row3[3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            row1[j] = board[2][j];
        };
    };
    // Pattern match check for each row
    // -- X --
    char* xwin = strstr(row1, x);
    char* xwin1 = strstr(row2, x);
    char* xwin2 = strstr(row3, x);
    if (xwin || xwin1 || xwin2) {
         std::cout << "player X has won!" << '\n';
    }
    // -- O --
    char* owin = strstr(row1, o);
    char* owin1 = strstr(row2, o);
    char* owin2 = strstr(row3, o);
    if (owin || owin1 || owin2) {
         std::cout << "player O has won!" << '\n';
    }
    // Vertical win
    // Diagonal win
    // Tie
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

void gameLoop() {
    while(playing) {
        std::cout << "Please select a position 1-9 player " << (player ? "x:" : "o:") << '\n';
        std::cin >> selection;
        select(selection);
        checkWin();
        player = !player;
        boardState();
    };
};

int main() {
    boardState();
    std::cout << "Hello!, Welcome to tic-tac-toe." << '\n';
    gameLoop();
    return 0; 
};

