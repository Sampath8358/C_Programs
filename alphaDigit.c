#include <stdio.h>

int main(){

    char ch;
    printf("Enter your character (A-Z, a-z and 0-1: ");
    scanf("%s",&ch);
    printf("\n");

    if((ch>64 && ch<91)||(ch>97 && ch<122))
    {
        printf("you have entered alphabet\n");
    }else
    {
        printf("you have entered digit\nASCII = %d",ch);
    }
    return 0;
}
