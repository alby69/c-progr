// Nest FOR loops
#include <stdio.h>
int main(void){
    int nbThrows = 0;    // number of players or turns
    int nbDice = 0;      // number of dice for player
    int diceValue = 0;   // value of current dice          
    int throwSum = 0;    // some of dice value of a turn
    int throw = 0;       // index first loop for the player 
    int dice = 0;        // index of dice in every player's turn

    scanf("%d %d", &nbThrows, &nbDice);
    for(throw = 0; throw<nbThrows; throw++){
        for(dice = 0; dice<nbDice; dice++){
            scanf("%d", &diceValue);
            throwSum = throwSum + diceValue;
        }
        printf("throw %d sum equals %d\n", throw, throwSum);
        throwSum = 0;
    }
    return 0;
}

/*
Input example:
5 4
1 4 2 3
3 2 6 4
2 4 1 4
2 2 1 4
3 6 1 2
*/
