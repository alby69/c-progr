// use recursion to compute the sum of digits
#include <stdio.h>

int sumOfDigits(int);

int main(void){
    int n, sum;
    scanf("%d",&n);
    sum = sumOfDigits(n);
    printf("%d",sum);
    return 0;
}

int sumOfDigits(int n){
    if(n!=0){
        // n%10 extract the last digit
        // n/10 the number without the last digit
        return (n%10) + sumOfDigits(n/10);
        
    }else{
        return 0;
    }
    
}
