#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int tos;
    int size;
    char *sp;
}sta;

char isFull();
char isEmpty();
void push(char ch);
char pop();
char peek();


int main() {

    int flag = 0;
    int i;
    sta.tos = -1;
    sta.size = 0;
    sta.sp = NULL;
        
    printf("Enter the size of the stack ");    
    scanf("%d",&sta.size);
    if(sta.size < -1)
    {
        printf("size should be > '0'\n");
    }
    sta.sp = (char*)malloc(sizeof(char)*sta.size);

    if(sta.sp == NULL)
    printf("Memory is not allocated\n");

    char arr[100];
    printf("Enter the string: ");
    scanf("%s",arr);

    for(i=0;i<strlen(arr);i++)
    {
        char ch = arr[i];
        switch(ch)
        {
            case '{':
            case '[':
                push(ch);
                break;
            case ']':
                if (peek() == '[')
                    pop();
                else
                    flag = 1;
                break;
            case '}':
                if (peek () == '{')
                    pop();
                else
                    flag = 1;
            default:
                break;
        }
    }
    if (flag == 1)
    {
        printf("String is not balanced\n");
    }
    else if (i = strlen(arr) && isEmpty)
    {
        printf("String is balanced");
    }
    return 0;
}

char isFull()
{ 
    if(sta.tos == sta.size-1)
        return 1;
    else
        return 0;
}

char isEmpty()
{
    if(sta.tos == -1)
        return 1;
    else
        return 0;
}

void push(char ch)
{
    if(!isFull())
    {
        sta.tos++;
        sta.sp[sta.tos] = ch;
    }
    else 
    {
        printf("stack is full..can't add\n");
    }
}

char pop()
{
    char x;
    if(!isEmpty())
    {
        x = sta.sp[sta.tos];
        sta.tos--;
        return x;
    }
    else
    {
        printf("Stack is empty can't delete\n");
        return '\0';
    }
        
}

char peek()
{
    char x;
    if(!isEmpty())
    {
        x = sta.sp[sta.tos];
        return x;
    }
    else
    {
        printf("stack is empty\n");
        return '\0';
    }
}
