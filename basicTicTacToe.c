#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char isAWin(int n, char board[]);
void printBoard(int n, char board[]);
void runGame();

int main() {
    runGame();
    return 0;
}

char isAWin(int n, char board[]) {
    int i, h, v, d;
    //Horizontal
    for (i = 1; i <= ((n*n) - (n-1)); i += n) {
        for (h = 1; h <= (n-1); h++) {
            if (board[i] == board[i+h]) 
                continue;
            else
                break;
        }

        if (h == n)
            return 'w';
    }
    //Vertical
    for (i = 1; i <= n; i++) {
        for (v = n; v <= (n * (n-1)); v += n) {
            if (board[i] == board[i+v]) 
                continue;
            else
                break;
        }

        if (v == (n*n))
            return 'w';
    }
    //Diagonal
    for (i = 1; i <= n; i += (n-1)) {
        if (i == 1) {
            for (d = (n+1); d <= ((n*n) - 1); d += (n+1)) {
                if (board[i] == board[i+d])
                    continue;
                else
                    break;
            }
            
            if (d == (n * (n+1)))
                return 'w';
                
        } else {
            for (d = (n-1); d <= ((n * (n-2)) + 1); d += (n-1)) {
                if (board[i] == board[i+d])
                    continue;
                else
                    break;
            }
            
            if (d == (n * (n-1)))
                return 'w';
        }
    }
    //Unfinished game
    for (i = 1; i <= (n*n); i ++) {
        if (board[i] == 'X' || board[i] == 'O')
            continue;
        else
            return '-';
    }
    //Draw
    return 'd';
}

void printBoard(int n, char board[]) {
    system ("cls");
    printf ("\n\n");
    for (int blankspace = 1; blankspace <= ((n-1 + n*5 - 11) / 2); blankspace++) {
        printf (" ");
    }
    printf ("Tic Tac Toe\n\n\n");
    for (int i = 1; i <= (n*3); i++) {
        for (int j = 1; j <= n; j++) {
            if (i % 3 == 0 && (i+1) <= (n*3)) {
                if (j < n)
                    printf ("_____|");
                else
                    printf ("_____\n");
            } else if ((i+1) % 3 == 0) {
                static int k = 1;
                if (k > (n*n))
                    k -= (n*n);
                if (j < n) {
                    printf ("  %c  |", board[k]);
                    k++;
                } else {
                    printf ("  %c  \n", board[k]);
                    k++;
                }
            } else {
                if (j < n)
                    printf ("     |");
                else
                    printf ("     \n");
            }
        }
    }
}

void runGame () {
    int side = 1, choice;
    char winner, XAndO;
    int n;

    printf ("Please choose the size of the Board with odd numbers only (3, 5, 7, ...): ");
    scanf ("%d", &n);
    while ((n % 2) == 0 || n < 3) {
        printf ("Invalid option!\n");
        printf ("Please choose another size: ");
        scanf ("%d", &n);
    }

    char board[(n*n) + 1];
    for (int i = 0; i <= (n*n); i++) {
        if (i == 0)
            board[i] = '-';
        else if ((i-9) == 0)
            board[i] = '9'; 
        else if (i > 9)
            board[i] = (i%10) + '0';
        else
            board[i] = i + '0';
    }
    
    do {
        printBoard(n, board);
        
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
        
        for (int i = 1; i <= (n*n); i++) {
            if(choice == i && board[i] != 'X' && board[i] != 'O') {
                board[i] = XAndO;
                break;
            } else if (i == n*n) {
                printf ("Invalid option!\n");
                printf ("Please choose another choice: ");
                side--;
            }
        }
        
        winner = isAWin(n, board);
        side++;
        getch();
    } while (winner == '-');
    
    printBoard(n, board);
    
    if (winner == 'w')
        printf ("Congratulations! Player%d won!\n",--side);
    else
        printf ("Game draw\n");
    
    getch();
}