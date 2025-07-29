// use an array to balance weights
#include <stdio.h>

int main(void){
    int cars;
    double box[50];
    int i = 0;
    double sum = 0.0;
    double avg = 0.0;

    scanf("%d",&cars);
    for(i=0;i<cars;i++){
        scanf("%lf",&box[i]);
        sum = sum + box[i];
    }
    avg = sum / cars;
    for(i=0;i<cars;i++){
        printf("%.1lf\n",avg - box[i]);
    }
    return 0;
}
