// memory usage displayed
#include <stdio.h>

int main(void){
    int qta,mem;
    char t;
    mem = 0;
    
    scanf("%c %d",&t,&qta);
    if(t == 'i'){
        mem = mem +sizeof(int)*qta;
    }else if(t == 'd'){
        mem = mem +sizeof(double)*qta;
    }else if(t == 'c'){
        mem = mem +sizeof(char)*qta;
    }else{
        printf("Invalid tracking code type\n");
    }
    if(mem < 1000){
        printf("%d bytes\n",mem);    
    }else if(mem >= 1000 && mem < 1000000){
        // 147 KB and 176 B
        printf("%d KB and %d B\n",mem/1000,mem%1000);
    }else if(mem >= 1000000 && mem < 999000000){
        // 5 MB and 234 KB and 0 B
        printf("%d MB and %d KB and %d B\n",mem/1000000,(mem%1000000)/1000,mem%1000);
    }
    return 0;
}
