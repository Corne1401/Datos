#include <stdio.h>

void WordLenght(){
    int input;

    while ((input = getchar()) != EOF){
        if (input != ' ' && input != '\n'){
            putchar('#');
        }
        else{
            printf("\n");
        }
    }
    printf("EOF CONFIRMED");
    
}

void CharFrec(){
    int charAmount = 128;
    int frequency[charAmount];

    int i;
    int j;
    int input;

    for (i = 0; i < charAmount; i++){
        frequency[i] = 0;
    }

    while((input = getchar()) != EOF){
        frequency[input]++;
        //uses the numerical value of 'input' insted of its character value
    }

    for(i = 0; i < charAmount; i++){
        putchar(i);
        
        for(j=0; j<frequency[i]; ++j){

            putchar('*');
        }
        
        putchar('\n');
    }




}

int main(){
    WordLenght();
    CharFrec();


}