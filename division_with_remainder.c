// find the remainder in integer division
#include <stdio.h>

int main(void){
    int matches = 0;    // number of matches to put in the boxes
    int size = 0;       // the size of each box
    printf("Put the number of matches:\n");
    scanf("%d",&matches);

    printf("Put the size of each box:\n");
    scanf("%d",&size);
    
    printf("The number of box is:\n");
    printf("%d\n",matches/size);
    printf("The number of remaing matches is:\n");
    printf("%d\n",matches%size);
    
    return 0;
}
