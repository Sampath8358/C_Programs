#include <stdio.h>

int main()
{
    int a;
    int b;
    char op;

    printf("Enter two operand with operator symbol (eg: first operand + second operand ) = ");
    scanf("%d %c %d",&a,&op,&b);

    switch(op)
    {
    case '+':
        printf("%d",a + b);
        break;
    case '-':
        printf("%d - %d = %d",a,b,a - b);
        break;
    case '*':
        printf("%d * %d = %d",a,b,a * b);
        break;
    default:
        printf("Invalid operator");
    }

    return 0;
}

