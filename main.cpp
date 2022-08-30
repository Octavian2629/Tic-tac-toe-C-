#include <iostream>
#include <vector>

void rulesTTT() {
    std::cout << "RULES: " << std::endl;
    std::cout << "^The game is played on a grid that's 3 squares by 3 squares." << std::endl;
    std::cout << "^You are 1, your friend (or the computer) is 2" << std::endl;
    std::cout << "^The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner." << std::endl;
    std::cout << "^When all 9 squares are full, the game is over." << std::endl;
}

void displayBoardTTT(std::vector<int> &a) {
    // displaying the board
    std::cout << std::endl;
    std::cout << "_" << a[0] << "_|_" << a[1] << "_|_" << a[2] << "_" << std::endl;
    std::cout << "_" << a[3] << "_|_" << a[4] << "_|_" << a[5] << "_" << std::endl;
    std::cout << "_" << a[6] << "_|_" << a[7] << "_|_" << a[8] << "_" << std::endl;
    std::cout << std::endl;
}

bool gameWinnerCheck(std::vector<int>& a, int n) {
    int counter = 0;
    for (int i = 0; i < 9; i++) {
        if (a[i] == 0)
            counter++;
    }
 
    // CHECKING IF PLAYER 1 WON
    if (a[0] == n) 
        if(a[1] == n)
            if(a[2] == n) // first horizontal line
                return true;
    if (a[3] == n)
        if(a[4] == n)
            if(a[5] == n)  // second horizontal line
                return true;
    if (a[6] == n)
        if(a[7] == n)
            if(a[8] == n)  // third horizontal line
                return true;
    if (a[0] == n)
        if(a[3] == n)
            if(a[6] == n)  // first vertical line  
                return true;
    if (a[1] == n)
        if(a[4] == n)
            if(a[7] == n)  // second vertical line
                return true;
    if (a[2] == n)
        if(a[5] == n)
            if(a[8] == n)  // third vertical line
                return true;
    if (a[2] == n)
        if(a[4] == n)
            if(a[6] == n)  // diagonal from bottom left to top right line
                return true;
    if (a[0] == n)
        if(a[4] == n)
            if(a[8] == n)  // diagonal from top left to bottom right line
                return true;
    if (counter != 9)
        return false;
    
}

bool gameStatusCheck(std::vector<int>& a) {
    int counter = 0;
    for (int i = 0; i < 9; i++) {
        if (a[i] != 0)
            counter += 1;
    }
    if (counter == 9) {
        return true;
    }
    else return false;
}

void gameTTT(std::vector<int> &a) {
    // the game itself 
    int inputNumber;
    bool gameStatus = true;
    bool player1Turn = true, player2Turn = false;

    // The number for X is 1 and the number for O is 2
    while (gameStatus) {
        std::cout << "Where do you want to put your mark? Enter a number between 0 and 8 " << std::endl;

        // Player 1 turn 
        std::cout << "Player 1 " << std::endl;
        std::cin >> inputNumber;

        if (player1Turn == true) {
            a[inputNumber] = 1;
            //first checking if there is a winner
            if (gameWinnerCheck(a, 1)) {
                std::cout << std::endl;
                displayBoardTTT(a);
                std::cout << "PLAYER 1 WON! CONGRATS!";
                gameStatus = false;
                break;
            }
            // and then checking if the board is full 
            if (gameStatusCheck(a)) {
                std::cout << std::endl;
                std::cout << "THE GAME ENDED IN A DRAW" << std::endl;
                gameStatus = false;
                break;
            }
            player1Turn = false;
            player2Turn = true;
            displayBoardTTT(a);
        }
        std::cout << "Player 2 " << std::endl;
        std::cin >> inputNumber;

        // Player 2 turn
        if (player2Turn == true) {
            a[inputNumber] = 2;
            //first checking if there is a winner
            if (gameWinnerCheck(a, 2)) {
                std::cout << std::endl;
                displayBoardTTT(a);
                std::cout << "PLAYER 2 WON! CONGRATS!";
                gameStatus = false;
                break;
            }
            // and then checking if the board is full 
            if (gameStatusCheck(a)) {
                std::cout << std::endl;
                std::cout << "THE GAME ENDED IN A DRAW" << std::endl;
                gameStatus = false;
                break;
            }
            player1Turn = true;
            player2Turn = false;
            displayBoardTTT(a);
        }
    }
}

int main()
{
    std::vector<int>a;
    for (int i = 0; i < 9; i++)
        a.push_back(0); //initial look of the board filled with 0's

    std::cout << "Welcome to Tic Tac Toe! :D" << std::endl;
    rulesTTT();
    displayBoardTTT(a);
    gameTTT(a);
}