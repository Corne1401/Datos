#include <stdio.h>


void ftoc(int upper){
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    step = 20;
    fahr = lower;

    printf("farenheit to celcius conversion table\n");

    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    
};

void ctof(int upper){
    float celsius, fahr;
    float lower, upper, step;
    lower = 0;
    step = 20;
    celsius = lower;

    printf("celsius to farenheit conversion table\n");

    while (celsius <= upper){
        fahr = 32 + (celsius * (9.0/5.0));
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }

};
int main(){

    ftoc(2000);
    ctof(1000);

}