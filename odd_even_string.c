// odd even length of string 
#include <stdio.h>

int main(void){
    char name[51];
    int i=0;
    int line = 2;
    
    scanf("%s",name);
    while(name[i] != '\0')
        i++;
    
    if(i%2 == 0)
        line = 1;
    printf("%d",line);
    
    return 0;
}
