// Negative logic to name tree
#include <stdio.h>

int main(void){
    int height, leaflets;
    char *tree = "uncertain";
    scanf("%d",&height);
    scanf("%d",&leaflets);
    
    if(height <= 5 && leaflets >= 8){
        tree = "Tinuviel";
    }
    
    else if(height >=10 && leaflets >= 10){
            tree = "Calaelen"; 
    }
    
    else if(height <= 8 && leaflets <= 5){
            tree = "Falarion"; 
    }
    
    else if(height >= 12 && leaflets <= 7){
            tree = "Dorthonion"; 
    }
    
    printf("%s\n",tree);
    
    return 0;
    

}
