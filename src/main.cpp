//
//  main.cpp
//  TicTacToe
//
//  Created by Cedric Amaya on 12/24/16.
//  Copyright © 2016 Cedric Amaya. All rights reserved.
//

#include <iostream>
#include <unistd.h>
using namespace std;

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';
int turns = 0;

int menu()
{
    int usrChoice;
    
    cout << "Tic Tac Toe - v1.1.0" << endl << endl;
    cout << "    MENU:    " << endl << "1. User v. User" << endl << "2. Quit" << endl;
    
    
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
    cout << "Tic Tac Toe - v1.1.0" << endl << endl;
    
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
    int a;
    cout << endl << "Press the number that goes with the corresponding field: ";
    cin >> a;
    
    a--;
    matrix[a/3][a%3] = player;
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
        cout << endl << "It's a tie!" << endl;
        return true;
    }
    else
        return false;
}

int main()
{
    if (menu() == 1)
    {
        draw();
        while (true)
        {
            input();
            draw();
            
            if (win() == 'X')
            {
                cout << endl << "X wins!" << endl;
                break;
            }
            else if (win() == 'O')
            {
                cout << endl << "O wins!" << endl;
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
    }
    
    return 0;
}
