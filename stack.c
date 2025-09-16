#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int tos;
    int size;
    int *sp;
}sta;

int isFull()
{ 
    if(sta.tos == sta.size-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(sta.tos == -1)
        return 1;
    else
        return 0;
}

void push(int n)
{
    if(!isFull())
    {
        sta.tos++;
        sta.sp[sta.tos] = n;
    }
    else 
    {
        printf("stack is full..can't add\n");
    }
}

int pop()
{
    int x = -1;
    if(!isEmpty())
    {
        x = sta.sp[sta.tos];
        sta.tos--;
        return x;
    }
    else
    {
        printf("Stack is empty can't delete\n");
        return -1;
    }
        
}

int peek()
{
    int x = -1;
    if(!isEmpty())
    {
        x = sta.sp[sta.tos];
        return x;
    }
    else
    {
        printf("stack is empty\n");
        return -1;
    }
}

int main() {
    sta.tos = -1;
    sta.size = 0;
    sta.sp = NULL;
        
    printf("Enter the size of the stack ");    
    scanf("%d",&sta.size);
        if(sta.size < -1)
        {
        printf("size should be > '0'\n");
        }
    sta.sp = (int*)malloc(sizeof(int)*sta.size);
        if(sta.sp == NULL)
        printf("Memory is not allocated\n");
    
    push(1);
    push(2);
    push(5);
    printf("tos = %d\n",sta.tos);
    printf("%d is deleted\n",pop());
    printf("%d is deleted\n",pop());
    printf("peek = %d\n",peek());
    push(10);
    

    return 0;
}


