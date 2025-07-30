// monitoring a chemical experiment
#include <stdio.h>

int main(void){
    int min,max,temp;
    
    scanf("%d %d",&min,&max);
    scanf("%d",&temp);
    while(temp != -999){
        if(temp >= min && temp <= max){
            printf("Nothing to report\n");    
        } else{
            printf("Alert!\n");
            break;
        }
        scanf("%d",&temp);
        
    }
    return 0;
}
