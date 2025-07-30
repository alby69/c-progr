// find the longest word in a text
#include <stdio.h>

int main(void){
    int nr,i;
    int j;
    int max = 0;
    char word[101];
    
    scanf("%d",&nr);
    for(i=0;i<nr;i++){
        j=0;
        scanf("%s",word);
        while(word[j]!='\0')
            j++;
            
        if(max < j)
            max=j;
    }
    printf("%d",max);
    return 0;
    
}
