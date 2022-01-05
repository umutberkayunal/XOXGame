#include <iostream>
#include <cstdlib>
#include <time.h>

/*
Simple XOX game playable between player and AI. This is a homework of Artificial Intelligince course CENG-466.
Umut Berkay Ünal
*/

//table
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
//player == 1 first player makes move.
int player = 1;
//win lines- 0-2 horizontal, 3-5 vertical 5-7 cross
int lines[8] = {0, 0, 0, 0, 0, 0, 0, 0};
//i thought of implementing winning lines but couldn't managed it, lack of time, maybe later
//int winlines[8] = {0, 0, 0, 0, 0, 0, 0, 0};
char mark;

void board()
{
    printf("Player 1 (X) HUMAN  -  Player 2 AI (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

/*
checking win condition, also an exit condition

*/

int checkwin()
{
    if ((square[1] == square[2] && square[2] == square[3]) && square[1] == 'X')
        return 1;
       
    else if ((square[4] == square[5] && square[5] == square[6]) && square[4] == 'X')
        return 1;
       
    else if ((square[7] == square[8] && square[8] == square[9]) && square[7] == 'X')
        return 1;
       
    else if ((square[1] == square[4] && square[4] == square[7]) && square[1] == 'X')
        return 1;
       
    else if ((square[2] == square[5] && square[5] == square[8]) && square[2] == 'X')
        return 1;
       
    else if ((square[3] == square[6] && square[6] == square[9]) && square[3] == 'X')
        return 1;
       
    else if ((square[1] == square[5] && square[5] == square[9]) && square[1] == 'X')
        return 1;
       
    else if ((square[3] == square[5] && square[5] == square[7]) && square[3] == 'X')
        return 1;

    else if ((square[1] == square[2] && square[2] == square[3]) && square[1] == 'O')
        return 2;
       
    else if ((square[4] == square[5] && square[5] == square[6]) && square[4] == 'O')
        return 2;
       
    else if ((square[7] == square[8] && square[8] == square[9]) && square[7] == 'O')
        return 2;
       
    else if ((square[1] == square[4] && square[4] == square[7]) && square[1] == 'O')
        return 2;
       
    else if ((square[2] == square[5] && square[5] == square[8]) && square[2] == 'O')
        return 2;
       
    else if ((square[3] == square[6] && square[6] == square[9]) && square[3] == 'O')
        return 2;
       
    else if ((square[1] == square[5] && square[5] == square[9]) && square[1] == 'O')
        return 2;
       
    else if ((square[3] == square[5] && square[5] == square[7]) && square[3] == 'O')
        return 2;
         
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return  - 1;
}

/*
Code segment for AI moves, i gave each winning line a score, then ai decides whether 2 of players mark are in the same line, ai plays for not losing.

I also thought of implementing winning lines but couldn't managed it, lack of time, maybe later
*/

void aiMove() {
          int x;
          if(3 - lines[0] == 1) {
            for(int i = 1; i <= 3; i++) {
              if(square[i] != mark && square[i] != 'X') {
                square[i] = mark;
                player ++;
                continue;
                }
            }
          }
          else if(3 - lines[1] == 1) {
            for(int i = 4; i <= 6; i++) {
              if(square[i] != mark && square[i] != 'X') {
                square[i] = mark;
                break;
                }
            }
          }
          else if(3 - lines[2] == 1) {
            for(int i = 7; i <= 9; i++) {
              if(square[i] != mark && square[i] != 'X') {
                square[i] = mark;
                break;
                }
            }
          }
          else if(3 - lines[3] == 1) {
            for(int i = 1; i <= 7; i = i + 3) {
              if(square[i] != mark && square[i] != 'X') {
                square[i] = mark;
                break;
                }
            }
          }
          else if(3 - lines[4] == 1) {
            for(int i = 2; i <= 8; i = i + 3) {
              if(square[i] != mark && square[i] != 'X') {
                square[i] = mark;
                break;
                }
            }
          }
          else if(3 - lines[5] == 1) {
            for(int i = 3; i <= 9; i = i + 3) {
              if(square[i] != mark && square[i] != 'X') {
                square[i] = mark;
                break;
                }
            }
          }
          else if(3 - lines[6] == 1) {
            for(int i = 1; i <= 9; i = i + 4) {
              if(square[i] != mark && square[i] != 'X') {
                square[i] = mark;
                break;
                }
            }
          }
          else if(3 - lines[7] == 1) {
            for(int i = 3; i <= 7; i = i + 2) {
              if(square[i] != mark && square[i] != 'X') {
                square[i] = mark;
                break;
                }
            }
          }
          else {
            do {
              x = rand() % 9;
              printf("%d%d%d\n%d%d\n", x, x, x, x, x);
            } while(square[x] == mark && square[x] == 'X');
            square[x] = mark;
          }
}

int main()
{
    srand(time(NULL));
    int i, choice;

    do
    {
        board();
        player = (player % 2) ? 1 : 2;
        if(player == 1) mark = 'X';
        if(player == 2) mark = 'O';
        if(player == 2) {
          aiMove();
          i = checkwin();
          player++;
          continue;
        }
        if(player == 1) {
        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);
        if (choice == 1 && square[1] == '1') {
            square[1] = mark;
         
            lines[0]++;
            lines[3]++;
            lines[6]++;
          }
        else if (choice == 2 && square[2] == '2') {
            square[2] = mark;
         
            lines[0]++;
            lines[4]++;
          }
        else if (choice == 3 && square[3] == '3') {
            square[3] = mark;
         
            lines[0]++;
            lines[5]++;
            lines[7]++;
          }
        else if (choice == 4 && square[4] == '4') {
            square[4] = mark;
         
            lines[1]++;
            lines[3]++;
          }
        else if (choice == 5 && square[5] == '5') {
            square[5] = mark;
         
            lines[1]++;
            lines[4]++;
            lines[6]++;
            lines[7]++;
          }
        else if (choice == 6 && square[6] == '6') {
            square[6] = mark;
         
            lines[1]++;
            lines[5]++;
          }
        else if (choice == 7 && square[7] == '7') {
            square[7] = mark;
         
            lines[3]++;
            lines[2]++;
            lines[7]++;
          }
        else if (choice == 8 && square[8] == '8') {
            square[8] = mark;
         
            lines[2]++;
            lines[4]++;
          }
        else if (choice == 9 && square[9] == '9') {
            square[9] = mark;
         
            lines[2]++;
            lines[5]++;
            lines[6]++;
          }
        else
        {
            printf("Invalid move ");

            player--;
        }
        }
        i = checkwin();
        player++;
    }while (i ==  - 1);
   
    board();
   
    if (i == 1)
        printf("==>\aPlayer win ");
    else if (i == 2)
        printf("==>\aAI win ");
    else
        printf("==>\aGame draw");

    return 0;
}