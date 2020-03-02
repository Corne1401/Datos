#include <stdio.h>

/* 1-11
Inputs numericos son los que tienen una 
mayor probabilidad de descubrir bugs en un programa*/

int main(){
// 1-12

    int c;

    while ((c = getchar()) != EOF){
        if(c == ' '){
            putchar('\n');
        }
        else{
            putchar(c);
        }
        
    }
};