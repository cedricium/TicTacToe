//
//  main.cpp
//  TicTacToe
//
//  Created by Cedric Amaya on 12/24/16.
//  Copyright © 2016 Cedric Amaya. All rights reserved.
//

#include <iostream>
#include <cctype>
using namespace std;

// global variables - not the best use & needs to change for future development
char version[7] = "v1.3.0";

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

char player = 'X';

int turns = 0;
int round = 0;

int xWins = 0;
int oWins = 0;
int numTies = 0;

int menu()
{
    // clears the screen
    cout << "\033[2J\033[1;1H";
    
    int usrChoice;
    
    cout << "Tic Tac Toe - " << version << endl << endl;
    cout << "    MENU:    " << endl << "1. User v. User" << endl << "2. Quit"
    << endl;
    
    cout << endl << "X Wins: " << xWins << "   O Wins: " << oWins << "   Ties: "
    << numTies << endl;
    
    cout << endl << "Select an option: ";
    cin >> usrChoice;
    
    if (usrChoice == 1)
        return 1;
    else
        return 0;
}

void draw()
{
    cout << "\033[2J\033[1;1H";
    cout << "Tic Tac Toe - " << version << endl << endl;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void input()
{
    int userInput;
    cout << endl << "It's " << player << "'s turn.";
    cout << endl << "Press the number that goes with the corresponding field: ";
    
    while (true)
    {
        cin >> userInput;
        
        userInput--;
        
        // checks to see if selected position is a number - if not, then its
        //   already been taken and player must select another position
        if (isdigit(matrix[userInput/3][userInput%3]))
        {
            matrix[userInput/3][userInput%3] = player;
            break;
        }
        else
        {
            cout << "Try another spot: ";
            continue;
        }
    }
}

void togglePlayer()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
    
    turns++;
}

char win()
{
    // check for horizontal wins
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    
    // check for vertical wins
    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'X';
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'X';
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'X';
    
    // check for diagonal wins
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    
    // check for horizontal wins
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    
    // check for vertical wins
    if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'O';
    if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'O';
    if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'O';
    
    // check for diagonal wins
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    
    return '/';
}

bool checkForTie()
{
    if (turns == 9 && win() == '/')
    {
        numTies++;
        round++;
        return true;
    }
    else
        return false;
}

void resetBoard()
{
    cout << "\033[2J\033[1;1H";
    cout << "Tic Tac Toe - " << version << endl << endl;
    
    // resets # of turns to 0 to fix checkForTie() function
    turns = 0;
    
    // ascii code for number one ("1")
    int resetVal = 49;
    
    // resets individual spots to 1-9 using `resetVal`, then prints said spots
    //   - aka "reseting the board" for a new game
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = resetVal;
            ++resetVal;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    while(true)
    {
        if (menu() == 1)
        {
            if (round > 0)
                resetBoard();
            else
                draw();
            while (true)
            {
                input();
                draw();
                
                if (win() == 'X')
                {
                    xWins++;
                    round++;
                    break;
                }
                else if (win() == 'O')
                {
                    oWins++;
                    round++;
                    break;
                }
                
                togglePlayer();
                
                if (checkForTie() == true)
                    break;
                else
                    continue;
            }
        }
        
        else
        {
            cout << "\033[2J\033[1;1H";
            cout << "Thanks for playing!" << endl;
            return 0;
        }
    }
    
    return 0;
}
