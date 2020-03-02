#include <stdio.h>
void getData(){
    int c =  getchar() != EOF;

    printf("%d", c);

}
void valueOfEof(){
    printf("%d", EOF);
}
int main(){
    getData();
    printf("\n");
    valueOfEof();
}