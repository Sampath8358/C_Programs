#include <stdio.h>
#include <ctype.h>   // for isalpha() and isdigit()

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    if (isalpha(ch)) {
        printf("You entered an alphabet");
    }
    else if (isdigit(ch)) {
        printf("You entered a digit\n");
        printf("ASCII = %d",ch);
    }
    else {
        printf("You entered a special character");
    }

    return 0;
}
