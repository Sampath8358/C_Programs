#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int tos;
    int size;
    int *sp;
}sta;

int isFull();
int isEmpty();
void push(int n);
int pop();
int peek();
int prece(char c);


int main() {
	sta.tos = -1;
    	sta.size = 0;
    	sta.sp = NULL;
    	
    	printf("Enter the size of the stack ");    
    	scanf("%d",&sta.size);
    	if(sta.size < 0)
    	{
        printf("size should be > '0'\n");
    	}
    	sta.sp = (int*)malloc(sizeof(int)*sta.size);

    	if(sta.sp == NULL)
    	printf("Memory is not allocated\n");
	
	char input[100];
	char output[100];
	printf("Enter the string: ");
	scanf("%s",input);
	
	int i, j = 0;
	for(i=0;i<strlen(input);i++)
	{
		char ch = input [i];
		switch(ch)
		{
			case '(':
			case '[':
			case '{':push (ch);
				break;
			case ')':
				 while (!isEmpty() && peek() != '(') {
					output[j++] = pop();
				  }
				    if (!isEmpty()) 
				    	pop(); 
				    break;

			case ']':
    				while (!isEmpty() && peek() != '[') {
       		 			output[j++] = pop();
    				}		
    				if (!isEmpty()) 
    					pop(); 
    				break;

			case '}':
    				while (!isEmpty() && peek() != '{') {        
        				output[j++] = pop();
    				}
    				if (!isEmpty()) 
    					pop(); 
   			 	break;
			case '*':
			case '/': 
			case '+':
			case '-': while (!isEmpty() && prece(peek()) >= prece(ch))
				{
					output [j++] = pop();
				}
					push (ch);
					break;
			default: output [j++] = ch;
				break;	
		} //switch
	} //for
	
	while (!isEmpty())
	{
		output [j++] = pop();
	}
	output[j] = '\0';
	printf("post fix: %s\n",output);
	for (i=0;i<strlen(output);i++)
	{
		char ch = output[i];
		int a,b,c;
		switch(ch)
		{
			case '+': 
				a = pop();
				b = pop();
				push(b+a);
				break;
			case '-': 
				a = pop();
				b = pop();
				push(b-a);
				break;
			case '*': 
				a = pop();
				b = pop();
				push(b*a);
				break;
			case '/': 
				a = pop();
				b = pop();
				push(b/a);
				break;	
			default: push (atoi(&ch));
			break;			
		}// switch	
	} //for
	printf("Evaluation of post fix = %d",pop());
	return 0;
} //main

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

int prece(char c)
{
	switch (c)
	{
		case '*':
		case '/': return 2;
		case '+':
		case '-': return 1;
		case '(':
		case '[':
		case '{': return 0;
		default: return -1;	
	}
}


