#include<stdio.h>

void printData(float weight, int wheels, int seats, short axis, short cilinder){

    printf("weight: %f\n", weight);

    printf("wheels: %d\n", wheels);

    printf("seats: %d\n", seats);

    printf("axis: ");
    printf("%d", axis);
    printf("\n");

    printf("cilinder: ");
    printf("%d", cilinder);
    printf("\n");

};

int main (){

    float weight;
    int wheels;
    int seats;
    short axis;
    short cilinders;

    printf("weight\n");
    scanf("%f", &weight);

    printf("wheels\n");
    scanf("%d", &wheels);

    printf("seats\n");
    scanf("%d", &seats);

    
    printf("axis\n");
    scanf("%hd", &axis);
    

    printf("cilinders\n");
    scanf("%hd", &cilinders);
 


    

    printData(weight,wheels,seats,axis,cilinders);

}