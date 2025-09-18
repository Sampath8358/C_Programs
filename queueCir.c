#include <stdio.h>
#include <stdlib.h>

struct queue {
	int front;
	int rear;
	int size;
	int *qp;
}que;

int overflow();
int underflow(); 
void enqueue(int n);
int dequeue();
void display ();

int main() {
	que.front = -1;
	que.rear = -1;
	que.qp = NULL;
	printf("Enter the size of the Queue: ");
	scanf("%d",&que.size);

	que.qp = (int*)malloc(sizeof(int)*que.size);

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("\nBefore deletion\n");
    display();
    printf("\n");
	dequeue();
    display();
	printf("\nAfter deletion\n");
	display();
    enqueue(5);
    printf("\nAfter adding\n");
    display();
	return 0;
}

int overflow()
{
	if((que.rear+1)%que.size == que.front)
	return 1;
    else
	return 0;
}

int underflow()
{
	if((que.rear == -1) && (que.front == -1))
	return 1;
	return 0;
}

void enqueue(int n)
{
	if(overflow())
	{
		printf("can't add\n");
	} 
	else
	{
		if(que.front == -1)
		que.front++;
		que.rear = (que.rear+1)%que.size;
		que.qp[que.rear] = n;
	}
}

int dequeue()
{
	int x = -1;
	if(underflow())
	{
		printf("can't delete\n");
	}
	else
	{

		x = que.qp[que.front];
		if(que.front==que.rear)
		{
			que.front = -1;
			que.rear = -1;
		}
		else
		{
			que.front = (que.front+1)%que.size;
		}
	} // outer ifelse
} //dequeue

void display ()
{
	if(!underflow())
	{
		printf("Que elements: ");
		for(int i = que.front;i!=que.rear;i = (i+1)%que.size)
		{
			printf("%d ",que.qp[i]);
		}
        printf("%d",que.qp[que.rear]);
	}
	else
	{
		printf("Que is empty\n");
	}
}
