#include <stdio.h>
int sum(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}
int mul(int a,int b){return a*b;}
int div(int a,int b){return a/b;}
int main(){

    int a,b,choice;
    printf("Enter the first operand:");
    scanf("%d",&a);
    printf("Enter the first operand:");
    scanf("%d",&b);

    printf("Select the operation (0 for sum,1 for sub,2 for mul, 3 for div) ");
    scanf("%d",&choice);

    int (*ptr[4])(int, int) = {sum,sub,mul,div};
    printf("Result = %d",ptr[choice](a,b));

    return 0;
}
