#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


char board[10] = {'-','1','2','3','4','5','6','7','8','9'};

//Line 20
char isAWin();
//Line 51
void printBoard();
//Line 65
void runGame();

int main() {
    runGame();
    return 0;
}

char isAWin() {
    //Horizontal
    if (board[1] == board [2] && board[2] == board[3])
        return 'w';
    else if (board[4] == board [5] && board[5] == board[6])
        return 'w';
    else if (board[7] == board [8] && board[8] == board[9])
        return 'w';
    //Vertical
    else if (board[1] == board [4] && board[4] == board[7])
        return 'w';
    else if (board[2] == board [5] && board[5] == board[8])
        return 'w';
    else if (board[3] == board [6] && board[6] == board[9])
        return 'w';
    //Diagonal
    else if (board[1] == board [5] && board[5] == board[9])
        return 'w';
    else if (board[3] == board [5] && board[5] == board[7])
        return 'w';
    //Draw
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' 
    && board[4] != '4' && board[5] != '5' && board[6] != '6' 
    && board[7] != '7' && board[8] != '8' && board[9] != '9')
        return 'd';
    else

    //Unfinished game
    return '-';
}

void printBoard() {
    system ("cls");
    printf ("\n\n   Tic Tac Toe \n\n\n");
    printf ("     |     |     \n");
    printf ("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf ("_____|_____|_____\n");
    printf ("     |     |     \n");
    printf ("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf ("_____|_____|_____\n");
    printf ("     |     |     \n");
    printf ("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
    printf ("     |     |     \n\n");
}

void runGame () {
    int side = 1, choice;
    char winner, XAndO;
    
    do {
        printBoard();
        
        if (side % 2)
            side = 1;
        else
            side = 2;
        
        printf ("Player%d enter your choice: ", side);
        scanf ("%d", &choice);
        
        if (side == 1)
            XAndO = 'X';
        else
            XAndO = 'O';
        
        if (choice == 1 && board[1] == '1')
            board[1] = XAndO;
        else if (choice == 2 && board[2] == '2')
            board[2] = XAndO;
        else if (choice == 3 && board[3] == '3')
            board[3] = XAndO;
        else if (choice == 4 && board[4] == '4')
            board[4] = XAndO;
        else if (choice == 5 && board[5] == '5')
            board[5] = XAndO;
        else if (choice == 6 && board[6] == '6')
            board[6] = XAndO;
        else if (choice == 7 && board[7] == '7')
            board[7] = XAndO;
        else if (choice == 8 && board[8] == '8')
            board[8] = XAndO;
        else if (choice == 9 && board[9] == '9')
            board[9] = XAndO;
        else {
            printf ("Invalid option!\n");
            printf ("Please choose another choice: ");
            side--;
        }
        
        winner = isAWin();
        side++;
        getch();
    } while (winner == '-');
    
    printBoard();
    
    if (winner == 'w')
        printf ("Congratulations! Player%d won!\n",--side);
    else
        printf ("Game draw\n");
    
    getch();
}