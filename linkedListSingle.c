#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
}*start;

void insertBeg(int n);
void travelForward();
void insertEnd(int n);
void insertAfetr(int n,int s);
int deleteFirst();
int deleteLast();
void deleteSpec(int s);
void reverseList();
void funPrint(struct node *current);
void travelBack();
void insertBefore(int n,int s);

int main(){
	//start = (struct node*)malloc(sizeof(struct node));
    start = NULL;
    insertBeg(8);
    insertEnd(17);
    insertBefore(8,17);
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

int deleteFirst(){
    int x = -1;
    struct  node *temp;
    if(start == NULL)
        printf("List is empty");
    else
    {
        temp = start;
        x = temp->data;
        start = start->next;
        free(temp);
        temp = NULL;
    }
    return x;
}

int deleteLast() {
    int x = -1;
    if (start == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp, *current;
        
        if (start->next == NULL) {
            temp = start;
            x = temp->data;
            start = NULL;
            free(temp);
            temp = NULL;
        } else {
            current = start;
            while (current->next->next != NULL) {
                current = current->next;
            }
            temp = current->next;
            x = temp->data;
            current->next = NULL;
            free(temp);
            temp = NULL;
        }
    }
    return x;
}
void deleteSpec(int s){
    struct node *temp,*current;
    if(start == NULL)
        printf("List is empty\n");
    if(start->data==s)
    {
        temp = start;
        start = temp->next;
        free(temp);
        temp = NULL;
    }
    else
    {
        current = start;
        while(current->next!=NULL && current->next->data!=s)
        {
            current = current->next;
        }
        if(current->next!=NULL)
        {
              temp = current->next;
              current->next = temp->next;
              free(temp);
              temp = NULL;
        }
        else
        {
            printf("Element not found\n");
        }
    }
}

void reverseList(){
    struct node *temp,*rev;
    rev = NULL;
    while(start!=NULL)
    {
        temp = start;
        start = temp->next;
        temp->next = rev;
        rev = temp;
    }
    start = rev;
    /*struct node *current;
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
    }*/
}
void travelBack(){
    if(start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        funPrint(start);
    }
}

void funPrint(struct node *current){
    if(current->next!=NULL)
    {
        funPrint(current->next);
    }
    printf("%d ",current->data);
}

void insertBefore(int n,int s){
    struct node *temp,*current;
    if(start == NULL)
        printf("List is empty");
    else
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        if(start->data == s)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            current = start;
            while(current->next != NULL && current->next->data != s)
            {
                current = current->next;
            }
            if(current->next != NULL)
            {
                temp->next = current->next;
                current->next = temp;
            }
            else
            {
                printf("Element not found");
                free(temp);  // free temp since we didn't insert it
            }
        }
    }
}

