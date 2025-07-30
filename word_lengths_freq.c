// Find the frequencies of word lengths
#include <stdio.h>
int main(void) {
    int nbWords, l;
    char word[11];
    int length[10] = {0}; // Initialize all elements to 0
    
    scanf("%d", &nbWords);
    
    for(int t = 0; t < nbWords; t++){
        scanf("%s", word);
        
        // Calculate string length inline
        for(l = 0; word[l] != '\0'; l++);
        
        length[l]++;
        printf("%s %d ", word, l);
    }
    
    for(int j = 0; j < 10; j++){
        printf("There are %d words with %d letters.\n", length[j], j);
    }
    
    return 0;
}
