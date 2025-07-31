// find the smallest integer
#include <stdio.h>

int min(int a, int b);

int main(void){
    
    int i,len;
    int ris = 0;
    scanf("%d",&len);    // number of integers   
    int array[len];
    
    for(i=0;i<len;i++){
        scanf("%d",&array[i]);
        if(i==0){
            ris = array[0];
        }else{
           ris = min(ris,array[i]); 
        }
        
    }
    printf("%d\n",ris);
    
    return 0;
}

int min(int a, int b){
    if(a <= b)
        return a;
    return b;
}
