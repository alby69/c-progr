// use pointers to improve elixir
#include <stdio.h>

//Write your function prototype here
void younger(int *);

int main(void){
	int age;
	int *ageAddr = &age;
	scanf("%d", ageAddr);
	printf("Your current age is %d.\n", age);

	//Write your function call here
    younger(ageAddr);
	printf("Your new age will be %d!\n", age);
	return 0;
}


//Write your function here
void younger(int * age){
    if(*age < 21){
        *age = *age * 2;
    } else{
        *age = *age - 10;
    }
    
}
