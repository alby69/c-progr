// passing array to function to swap
#include <stdio.h>

void readArray(int *, int);
void reverseArray(int *, int);
void printArray(int *, int);

int main(void){
    int size = 6;
    int array[size];
    
    readArray(array, size);
    reverseArray(array, size);
    printArray(array, size);
    
    return 0;
}

void reverseArray(int *array, int size){
    int tmp;
    int i;
    
    // Scambia elementi simmetrici
    for(i = 0; i < size/2; i++){
        tmp = array[i];
        array[i] = array[size-1-i];
        array[size-1-i] = tmp;
    }
}

void printArray(int *array, int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", array[i]);    
    }
    printf("\n");    
}

void readArray(int *array, int size){
    int i;
    for(i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }    
}
