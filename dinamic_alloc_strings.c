// dynamically allocate memory for strings 
#include <stdio.h>
#include <stdlib.h>
char * allocateString(int);

int main(void) {
    int lengthLight, lengthDark;
    char *strLight, *strDark;
    
    scanf("%d %d", &lengthLight, &lengthDark); 
    strLight = allocateString(lengthLight);
    strDark = allocateString(lengthDark);
   
    scanf("%s", strLight);
    scanf("%s", strDark);
    printf("Local settings: %s - %s\n", strLight, strDark);

    free(strLight);
    free(strDark);
	
    return 0;
}

char * allocateString(int numChars){
    char * ptr;
    ptr = (char *) malloc(numChars*sizeof(char));
    return ptr;
}
