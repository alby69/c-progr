// store recipe ingredients in an array
#include <stdio.h>

int main(void){
    int ingredients[10];
    int id,i,curr;

    for(i=0;i<10;i++){
        scanf("%d",&curr);
        ingredients[i] = curr;
    }
    scanf("%d",&id);
    printf("%d",ingredients[id]);
    
    return 0;
}
