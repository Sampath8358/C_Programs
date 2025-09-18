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

	int a,j=0;
	do
	{
		printf("Enter the %d element to add: ",j);
		scanf("%d",&a);
		enqueue(a);
		j++;
	} while (a<que.size);
	display();
	dequeue();
	printf("\nAfter deletion\n");
	display();

	return 0;
}

int overflow()
{
	if(que.rear == que.size-1)
	return 1;
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
		que.rear++;
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
			que.front++;
		}
	} // outer ifelse
} //dequeue

void display ()
{
	if(!underflow())
	{
		printf("Que elements: ");
		for(int i = que.front;i<=que.rear;i++)
		{
			printf("%d ",que.qp[i]);
		}
	}
	else
	{
		printf("Que is empty\n");
	}
}
