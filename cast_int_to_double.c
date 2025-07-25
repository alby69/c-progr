// convert integers to doubles
#include <stdio.h>

int main(void){
    int grades = 0;
    int grade = 0;
    int sum = 0;
    double avg = 0.00;
    int i = 0;
    printf("How many grades you want to insert?\n");
    scanf("%d",&grades);
    for(i=0;i<grades;i++){
        scanf("%d\n",&grade);
        sum = sum + grade;
    }
    avg = (double)sum/grades;
    
    printf("The average of these grades is %.2lf",avg);
    return 0;
}
