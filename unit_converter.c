// a simple smart unit converter
#include <stdio.h>
char metric(char u);
double convert(double n, char u);

int main(void){
    int id,i;
    double number,result;
    char iu;    // input unit
    char ou;    // output unit
    // m: meters    -> ft:foot
    // g: grams     ->  lbs:pounds
    // c: degrees Celsius -> f: degrees Fahrenheit
    scanf("%d",&id);
    for(i=0;i<id;i++){
        scanf("%lf %c",&number,&iu);
        ou = metric(iu);
        result = convert(number,ou);
        
        if(ou == 'E'){
            printf("unit wrong!\nUse (m):meter, (g):gram, (c):celsius\n");
        }
        else{
            printf("%.6lf ",result);    
            if(ou == 't') printf("%s\n","ft");
            else if(ou == 'l') printf("%s\n","lbs");
            else if(ou == 'f') printf("%s\n","f");        
        }    
    }

    return 0;
}
char metric(char u){

    if(u == 'm')        return 't';        // ft
    else if(u == 'g')   return 'l';   // lbs
    else if(u == 'c')   return 'f';
    else return 'E';

}
double convert(double n, char u){
    //1 meter = 3.2808 feet;
    //1 gram = 0.002205 pounds;
    //temperature in degrees Fahrenheit = 32 + 1.8 × temperature in degrees Celsius.

    if(u == 't'){
        return n * 3.2808;
    }else if(u == 'l'){
        return n * 0.002205;
    }else if(u == 'f'){
        return 32 + 1.8 * n;
    }
    return 0.0;

}
