// exercise array and functions
#include <stdio.h>

void behind(int *, int);
int max_array(int *, int);
void print_array(int *, int);
void read_array(int *, int);

int main(void) {
    int array[10];
    int N, i;
    
    scanf("%d", &N);
    read_array(array, N);
    behind(array, N);
    print_array(array, N);
    
    return 0;
}

void read_array(int * ptr, int size){
    int i;
    for (i=0; i<size; i++) {
        scanf("%d", &ptr[i]);
    }
}
void print_array(int * ptr, int size){
    int i;
    for (i=0; i<size; i++) {
        printf("%d\n", ptr[i]);
    }
}
int max_array(int * ptr, int size){
    int i = 0;
    int max = ptr[i];
    
    for(i=1;i<size;i++){
        if(ptr[i] > max)
            max = ptr[i];
    }
    return max;
}
void behind(int * ptr, int size){
    int i;
    int max = max_array(ptr,size);
    for(i=0;i<size;i++){
        ptr[i] = max - ptr[i];
    }
    
}
