#include<stdio.h>

struct Car
    {
        /* data */
        float weight;
        int wheels;
        int seats;
        char brand[16];
        char color[16];

        

    };

void printData(struct Car *car){

    printf("weight: %f\n", car->weight);
    printf("wheels: %d\n", car->wheels);
    printf("seats: %d\n", car->seats);
    printf("brand: ");
    for (int i = 0; i < 16; i++){
        printf("%c",car->brand[i]);
    };
    printf("\n");
    printf("color: ");
    for (int i = 0; i < 16; i++){
        printf("%c",car->color[i]);
    };
    printf("\n");

};

int main (){
    
    struct Car car1 = {1000.532, 4, 5, "toyota", "white"};

    printData(&car1);
    fflush(stdout);

}