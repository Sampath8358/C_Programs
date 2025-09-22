#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
    struct node *prev;
	struct node *next;
}*start;

void insertBeg(int n);
void travelForward();
void insertEnd(int n);
void insertBefore(int n,int s);
int deleteFirst();
int deleteLast();
void deleteSpec(int s);
void travelBack();

int main(){
	//start = (struct node*)malloc(sizeof(struct node));
    start = NULL;
    insertBeg(8);
    insertBeg(17);
    insertEnd(25);
    insertBefore(30,25);
    insertBefore(31,30);
    insertBeg(8);
    travelForward();
    printf("\n");
    travelBack();
}

void insertBeg(int n){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    if(start == NULL)
        start = temp;
    else
    {
        temp->next = start;
        start->prev = temp;
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
    temp->prev = NULL;
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
        temp->prev = current;
    }
}

void insertBefore(int n, int s) {
    struct node *temp, *current;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    if (start->data == s)
    {
        insertBeg(n);
        return;
    }
    else
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = n;
        temp->next = NULL;
        temp->prev = NULL;
        current = start;
        while(current->next != NULL && current->next->data != s)
        {
            current = current->next;
        }

        if(current->next != NULL) 
        {
            temp->next = current->next;
            temp->prev = current;
            current->next->prev = temp;
            current->next = temp;
        } 
        else 
        {
            printf("Element not found\n");
            free(temp); 
        }
    }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  

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
            while(current->next->next != NULL) {
                current = current->next;
            }
            temp = current->next;
            x = temp->data;
            current->next = NULL;
            free(temp);
            temp = NULL;
        }
    } //outer if else
    return x;
}//function

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

void travelBack() {
    struct node* current;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    current = start;
    while (current->next != NULL) {
        current = current->next;
    }

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}
