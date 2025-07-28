// complex logic conditions to find hostel cost
#include <stdio.h>

int main(void){
    int age;
    int weight; // in pounds
    int cost = 0;
    
    scanf("%d",&age);
    scanf("%d",&weight);
    if(age == 60){
        cost = 0;    
    }else{
        if(age < 10){
            cost = 5;
        }else{
            cost = 30;
            if(weight > 20.0){
                cost = cost + 10;
            }
        }
    }
    printf("%d\n",cost);
    return 0;
}
