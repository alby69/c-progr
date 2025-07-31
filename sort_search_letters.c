//  sorting and searching repetitive letters
#include <stdio.h>

int main(void){
    char word[50];
    char swap;
    int i,j;
    int n = 0;
    int count = 0;

    scanf("%s",word);
    
    for(i=0;i<50;i++){
        if(word[i] == '\0'){
            n = i;  // set n as len of word
            break;
        }
    }

    for(j=0;j<n-1;j++){
        for(i=0;i<n-1;i++){
            if(word[i]>word[i+1]){
              swap = word[i];
              word[i] = word[i+1];
              word[i+1] = swap;
            }
        }
    }
    
    printf("\nsorted word:\n");
    printf("%s\n",word);
   
    //erroneousnesses
    //eeeennoorrssssu
    

    for(i=0;i<n-1;i++){
        if(word[i] == word[i+1]){
            // Trovato inizio di un gruppo
            printf("%c:%c\n",word[i],word[i+1]);
            count++;
            // Salta tutti i caratteri uguali consecutivi
            while(i < n-1 && word[i] == word[i+1]){
                i++;
            }
            
        }
    }
    printf("%d",count);

    return 0;
}
