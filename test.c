#include <stdio.h>
struct test
{
    int a;
};


int main() {
    struct test b;
    b.a = 0;
    printf("%d",b.a);

    return 0;
}