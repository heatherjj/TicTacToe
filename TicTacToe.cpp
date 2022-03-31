// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char space[9] = { '1', '2', '3','4','5', '6','7', '8', '9' };
char playerOne = 'X',
    playerTwo = 'O',
    currentPlayer = playerOne;
bool draw = false;
unsigned int position = 0;

void drawBoard() {
    //draws board
	cout << "    |     |    \n";
	cout << " " << space[0] << "  |  " << space[1] << "  |  " << space[2] << "  \n";
	cout << "____|_____|____ \n";
	cout << "    |     |     \n";
	cout << " " << space[3] << "  |  " << space[4] << "  |  " << space[5] << "  \n";
	cout << "____|_____|____ \n";
	cout << "    |     |     \n";
	cout << " " << space[6] << "  |  " << space[7] << "  |  " << space[8] << "  \n";
	cout << "    |     |     \n";
}

bool checkWin(int x, int y, int z) {
    //validate space
    if ((x >= 0 && x <= 8) && (y >= 0 && y <= 8) && (z >= 0 && z <= 8))
    {
        //check if a row has same input
        return (space[x] == currentPlayer && space[y] == currentPlayer && space[z] == currentPlayer);
    }
    return false;
}

bool checkWinner() {
    //returns if win scenarios are true
    return (checkWin(0, 1, 2)
        || checkWin(3, 4, 5)
        || checkWin(6, 7, 8)
        || checkWin(0, 3, 6)
        || checkWin(1, 4, 7)
        || checkWin(2, 5, 8)
        || checkWin(0, 4, 8)
        || checkWin(2, 4, 6));
}

bool checkDraw() {
    //returns if no winner
    for (int i = 0; i < 9; i++) {
        if (space[i] != playerOne && space[i] != playerTwo) {
            return false;
        }
    }
    return true;
}

void initGame() {
    //reset board
    currentPlayer = playerOne;
    space[0] = '1';
    space[1] = '2'; 
    space[2] = '3'; 
    space[3] = '4'; 
    space[4] = '5'; 
    space[5] = '6'; 
    space[6] = '7'; 
    space[7] = '8'; 
    space[8] = '9';
}

int main()
{
    string userInput = "";
    //if the user wants to play again
    while (userInput != "N" && userInput != "n") {
        initGame();
        while (true) {
            system("cls");
            drawBoard();
            cout << "Please select 1 - 9 for " << currentPlayer << endl;
            cin >> position;
            if (position < 1 && position > 9) {
                continue;
            }
            else {
                position--;
            }
            space[position] = currentPlayer;
            if (checkWinner()) {
                break;
            }
            else {
                if (checkDraw()) {
                    draw = true;
                    break;
                }
                //switch player
                if (currentPlayer == playerOne) {
                    currentPlayer = playerTwo;
                }
                else {
                    currentPlayer = playerOne;
                }
            }
        }
        //if no winner
        if (!draw) {
            cout << currentPlayer << " wins!" << endl;
        }
        else {
            cout << "Game was a draw!" << endl;
        }
        //prompt user for another game
        cout << "Would you like to play again? Y/N" << "  ";
        cin >> userInput;
        cout << endl;
    }
}