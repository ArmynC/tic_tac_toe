#include <stdio.h>
#include <stdlib.h>

// set the game table in a 2d array
char table[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

int turn, choice;

int checkStatus();
void displayTable();
void setChoice(char write);


int main(){
    char write;
    int checkGame;

    turn = 1; // set the player's number

    do
    {
      displayTable();

      // change turn
      turn = (turn % 2) ? 1 : 2;

      printf("[Turn %d] Input: ", turn);

      scanf("%d", &choice);

      // write the character of the player
      write = (turn == 1) ? 'X' : 'O';

      // write on board
      setChoice(write);

      checkGame = checkStatus();

      turn++;

    }while (checkGame == 0);

    if (checkGame == 1){
        printf("Player with turn %d won! ", --turn);
    }
    else {
        printf("The game ended with a draw!");
    }

    return 0;
}


/*
 *   1 = game ended with a win;
 *   0 = game is still on;
 *  -1 = game ended with a neutral result;
 */

int checkStatus(){

    /*
     i |  table[i][0]  |  table[i][1]  |  table[i][2]
   ----|---------------|---------------|---------------
     0 |  table[0][0]  |  table[0][1]  |  table[0][2]
     1 |  table[1][0]  |  table[1][1]  |  table[1][2]
     2 |  table[2][0]  |  table[2][1]  |  table[2][2]
    */

    for(int i=0;i<3;i++){
        // check row (horizontal win)
        if(table[i][0] == table[i][1] && table[i][1] == table[i][2]){
            return 1;
        }

        // check column (vertical win)
        if(table[0][i] == table[1][i] && table[1][i] == table[2][i]){
            return 1;
        }
    }

    // vertical check
    if(table[0][0] == table[1][1] && table[1][1] == table[2][2]){
        return 1;
    } else if(table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
        return 1;
    }

    // draw check
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (table[i][j] != 'X' && table[i][j] != 'O') {
                return 0; // game is still playing.
            }
        }
    }

    return -1; // no more elements. draw.
}

void displayTable(){

    printf("\033[H\033[J");

    printf("\n\n Tic Tac Toe game - 2 players \n\n");

    printf("         |          |         \n");
    printf("    %c    |    %c     |    %c   \n", table[0][0], table[0][1], table[0][2]);
    printf("---------|----------|---------\n");
    printf("         |          |         \n");
    printf("    %c    |    %c     |    %c   \n", table[1][0], table[1][1], table[1][2]);
    printf("         |          |         \n");
    printf("---------|----------|---------\n");
    printf("         |          |         \n");
    printf("    %c    |    %c     |    %c   \n\n", table[2][0], table[2][1], table[2][2]);

}

void setChoice(char write){
    if(choice == 1 && table[0][0] == '1'){
        table[0][0] = write;
    }

    else if(choice == 2 && table[0][1] == '2'){
        table[0][1] = write;
    }

    else if(choice == 3 && table[0][2] == '3'){
        table[0][2] = write;
    }

    else if(choice == 4 && table[1][0] == '4'){
        table[1][0] = write;
    }

    else if(choice == 5 && table[1][1] == '5'){
        table[1][1] = write;
    }

    else if(choice == 6 && table[1][2] == '6'){
        table[1][2] = write;
    }

    else if(choice == 7 && table[2][0] == '7'){
        table[2][0] = write;
    }

    else if(choice == 8 && table[2][1] == '8'){
        table[2][1] = write;
    }

    else if(choice == 9 && table[2][2] == '9'){
        table[2][2] = write;
    } else {
       turn--;
    }
}