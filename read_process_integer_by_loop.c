/*
Title: Activity: read and process multiple integers via a loop
Description:
Write a program that takes several lines of input from a user (see the below example).
The first line of the input indicates the number of robots to be deployed.
Each subsequent line shows the height, the weight, the power of the engines 
and a resistance rating (1,2, or 3) of each of of these robots.
Your program should use this information to calculate the total power of these robots.
The power of all robots is the sum of the power of each robot, 
where the power of an individual robot is calculated via:

(enginePower + resistance) * (weight - height)

Example
Input:
2
50 60 2 1
43 62 5 2

Output:
163

Here the output in this example is the calculation
(2 + 1) * (60-50) + (5 + 2) * (62-43)

*/

#include <stdio.h>

int main(void){
    int i,robots,height,weight,power,resistance,tot_power = 0;
    //printf("How many robots do you want to deploy? ");
    scanf("%d\n",&robots);
    for(i=0;i<robots;i++){
        //printf("height weight power resistance");
        scanf("%d %d %d %d\n",&height,&weight,&power,&resistance);
        tot_power = tot_power + (power+resistance)*(weight-height);
        
    }
    printf("%d",tot_power);
    return 0;
}
