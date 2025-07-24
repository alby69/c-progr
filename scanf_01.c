/*
Title: Use scanf() inside a loop to read multiple user inputs
From: Dartmouth_IMTx DART.IMT.C.01 C Programming: Getting Started
Link: https://learning.edx.org/course/course-v1:Dartmouth_IMTx+DART.IMT.C.01+1T2020/home

*/

#include <stdio.h>
int main() {
    int numbers = 0;    // integers number to sum
    int number = 0;     // number inserted in terminal    
    int sum = 0;        // sum of the numbers
    
    printf("How many numbers do you want to sum? ");
    scanf( "%d\n",&numbers);
    for(int i = 0; i < numbers; i++){
        printf("-->> ");
        scanf("%d",&number);
        sum = sum + number;
        printf("you input (%d): sum = (%d)\n",number,sum);
    }
    printf("Well done!\n");
  return 0;
}
