// Write a function: the sum of 2 integers
#include <stdio.h>

int sum(int x, int y){
    return x+y;
}

int main(void) {
    int a,b;
    int result;
    printf("Please enter two numbers: ");
    scanf("%d%d", &a, &b);
    printf("Result of the sum = %d.\n", sum(a, b));
    return 0;
}
