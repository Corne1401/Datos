#include <stdio.h>


void ftoc(){
    float fahr, celsius;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = upper;

    printf("farenheit to celcius conversion table\n");

    while (fahr >= lower) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr - step;
    }

    
};

void ctof(){
    float celsius, fahr;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    celsius = upper;

    printf("celsius to farenheit conversion table\n");

    while (celsius >= lower){
        fahr = 32 + (celsius * (9.0/5.0));
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius -= step;
    }

};




int main()
{
    ftoc();
    printf("\n");
    ctof();
}