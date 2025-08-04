// compute space
#include <stdio.h>

int main(void){
    int nr,qta,mem,i;
    char t;
    mem = 0;
    
    scanf("%d",&nr);
    for(i=0;i<nr;i++){
        scanf("%d %c",&qta,&t);
        if(t == 'i'){
            mem = mem +sizeof(int)*qta;
        }else if(t == 'd'){
            mem = mem +sizeof(double)*qta;
        }else if(t == 'c'){
            mem = mem +sizeof(char)*qta;
        }else{
            printf("Invalid tracking code type\n");
            return 0;
        } 
    }
    printf("%d bytes\n",mem);
    return 0;
}
