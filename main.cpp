#include <iostream>
#include <string>
#include <cstring>
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

// Refactor? O(N^2) is slug-ish but not working with large data set
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
    // Pattern match check for each row (strstr requires null termination)
    // -- X --
    char* xwin = strstr(row1, x);
    char* xwin1 = strstr(row2, x);
    char* xwin2 = strstr(row3, x);
    if (xwin || xwin1 || xwin2) {
        boardState();
        std::cout << "player X has won!" << '\n';
        playing = false;
    }
    // -- O --
    char* owin = strstr(row1, o);
    char* owin1 = strstr(row2, o);
    char* owin2 = strstr(row3, o);
    if (owin || owin1 || owin2) {
        boardState();
        std::cout << "player O has won!" << '\n';
        playing = false;
    }
    // Vertical win [0][1][1][2][2][3]
    // Diagonal win
    // Tie
};

void gameLoop() {
    while(playing) {
        boardState();
        std::cout << "Please select a position 1-9 player " << (player ? "x:" : "o:") << '\n';
        std::cin >> selection;
        select(selection);
        checkWin();
        player = !player;
    };
};

int main() {
    std::cout << "Hello!, Welcome to tic-tac-toe." << '\n';
    gameLoop();
    return 0; 
};

