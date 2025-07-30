// searching for letter in word
#include <stdio.h>

int main(void){
    char word[51];
    int i = 0;
    int middle = 0;

    scanf("%s",word);
    while(word[i])
        i++;    
    middle = i/2 + 1;
    i = 0;
    while(word[i]){
        if(word[i]=='t' || word[i]=='T'){
            if(i <= middle){
                printf("1");
            }else{
                printf("2");
            }
            return 0;
        }else{
            i++;
        }
    }
    printf("-1");
    return 0;
}
