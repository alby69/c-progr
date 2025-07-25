// compare decimals to cross bridge
#include <stdio.h>

int main(void){
    int dice1;
    int dice2;
    int sum = 0;
    int great_total;
    
    scanf("%d %d",&dice1,&dice2);
    sum = dice1+dice2;
    great_total = sum >= 10;
    
    if((dice1 >= 1 || dice1 <=6) && (dice2 >= 1 || dice2 <=6)){
        if(great_total){
            printf("Special tax\n");
            printf("%d",36);
        }else{
            printf("Regular tax\n");
            printf("%d",2*sum);
            
        }        
    }

}
