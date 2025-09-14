#include <stdio.h>

struct student{
    int age;
    int marks;
};

void print(struct student *ptr){
    printf("%d\n%d\n",ptr->age,ptr->marks);
    int sum = ptr->age + ptr->marks;
    printf("Sum = %d",sum);
}
int main(){
    struct student s1;
    s1.age = 15;
    s1.marks = 35;
    //printf("%d\n%d\n",s1.age,s1.marks);
    print(&s1);
}
