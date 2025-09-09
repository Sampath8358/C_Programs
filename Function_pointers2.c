#include <stdio.h>

int add(int a, int b);

int main(){
    int a, b;

    printf("Enter first operand: ");
    scanf("%d",&a);

    printf("Enter second operand: ");
    scanf("%d",&b);
    int (*ptr)(int, int) = &add;
    printf("%d + %d = %d",a,b,ptr(a,b));

}

int add(int a, int b)
{
    return a+b;
}
