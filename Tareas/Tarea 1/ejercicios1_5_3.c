#include <stdio.h>

void balnks(){
    int c,blnks, tab, nlin;

    blnks = 0;
    tab = 0;
    nlin = 0;

    while((c = getchar()) != EOF){
        if(c == ' '){
            ++blnks;
        }
        else if (c == '\t'){
            ++tab;
        }
        else if (c == '\n'){
            ++nlin;
        }
        else if (c == '$'){
            printf("blanks: %d | tabs: %d | new lines: %d\n" ,blnks, tab, nlin);
            break;
        }

    }
   
}

void noBlanks(){
    char noSpaces = '-';
    int c,lastChar;

    lastChar=noSpaces;

    while((c=getchar()) != EOF)
    {
        if(c==' '){
            if(lastChar!=' ')
                putchar(c);
            }
        else if (c == '$'){
            break;
        }
        else{
            putchar(c);
        }


        lastChar=c;
    }
}

void replacement(){
    int c;

    while ((c = getchar()) != EOF){
        if(c == '\t'){
            putchar('\\');
            putchar('t');
        }
        else if(c == '\b'){
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\'){
            putchar('\\');
            putchar('\\');
        }
        else if (c == '$'){
            break;
        }
        else{
            putchar(c);
        }
    }

}

int main(){
    balnks();
    noBlanks();
    replacement();
}