// compare decimals to play tug of war
#include <stdio.h>

int main(void){
    int players, weight, i;
    int team1 = 0;
    int team2 = 0;
    int win = 0;
    
    scanf("%d",&players);
    for(i=0;i<players;i++){
        scanf("%d",&weight);
        team1 = team1 + weight;
        
        scanf("%d",&weight);
        team2 = team2 + weight;
        
    }
    
    win = 2;
    if(team1>team2){
        win = 1;
    }
    printf("Team %d has an advantage\n",win);
    printf("Total weight for team 1: %d\n",team1);
    printf("Total weight for team 2: %d\n",team2);

    
    return 0;
}
