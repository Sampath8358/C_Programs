#include <stdio.h>
#include <stdlib.h>

void insertBeg(int n);
void travelForward();
void insertEnd(int n);
void insertAfetr(int n,int s);

struct node {
	int data;
	struct node *next;
}*start = NULL;

int main(){
	//start = (struct node*)malloc(sizeof(struct node));
    
    insertEnd(25);
    insertEnd(26);
    travelForward();
    printf("\n");
    insertAfetr(27,26);
    travelForward();
}

void insertBeg(int n){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    if(start == NULL)
        start = temp;
    else
    {
        temp->next = start;
        start = temp;
    }

}

void travelForward(){
    struct node *current;
    current = start;
    if(start == NULL)
        printf("List is empty");
    else
    {
        while(current!=NULL)
        {
            printf("%d ",current->data);
            current = current->next;
        }
    }

}

void insertEnd(int n){
    struct node *temp,*current;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    if(start == NULL)
    {
        start = temp;
    }  
    else
    {
        current = start;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void insertAfetr(int n,int s){
    struct  node *temp,*current;
    if(start==NULL)
        printf("List is empty");
    else
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        current = start;
        while(current!=NULL && current->data!=s)
        {
            current = current->next;
        }
        if(current!=NULL)
        {
            temp->next = current->next;
            current->next = temp;
        }
        else
        {
            printf("Element not found");
        }
    } //outer ifelse
}// function

void travelForward(){
    struct node *current;
    current = start;
    if(start == NULL)
        printf("List is empty");
    else
    {
        while(current!=NULL)
        {
            printf("%d ",current->data);
            current = current->next;
        }
    }

}

void insertEnd(int n){
    struct node *temp,*current;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    if(start == NULL)
    {
        start = temp;
    }  
    else
    {
        current = start;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void insertAfetr(int n,int s){
    struct  node *temp,*current;
    if(start==NULL)
        printf("List is empty");
    else
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        current = start;
        while(current!=NULL && current->data!=s)
        {
            current = current->next;
        }
        if(current!=NULL)
        {
            temp->next = current->next;
            current->next = temp;
        }
        else
        {
            printf("Element not found");
        }
    } //outer ifelse
}// function