#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node *next;
};


// function for printing the the list 

void printList(struct Node * start)
{
    struct Node *temp = start;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// insert add beginning 

struct Node * insertAddbegining(struct Node * start, int value)
{
    struct Node *newNode = (struct Node * )malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = start;
    start = newNode;
    return start;
}


// function to inserting a value at the end
struct Node * insertAddEnd(struct Node * start , int value)
{
    struct Node *temp = start;
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return start;
}


// function for inserting a value at a given position
struct Node * insertAtPosition(struct Node *start , int position, int value)
{
    struct Node * temp = start;
    struct Node * newNode = (struct Node * )malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(position == 1)
    {
        start = insertAddbegining(start, value);
        return start;
    }

    for(int i = 1; i <= position-2; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return start;
}

// delete from beginning of a list

struct Node * deleteFromBeginning(struct Node * start)
{
    struct Node * deletedNode = start;
    start = start->next;
    free(deletedNode);
    return start;
}


// delete from end of the list
struct Node * deleteFromEnd(struct Node * start)
{
    struct Node * temp = start;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    struct Node * deletedNode = temp->next;
    temp->next = NULL;
    free(deletedNode);
    return start;
}


// function for giving the size of the list
int sizeOfList(struct Node * start)
{
    int i = 0;
    struct Node * temp = start;
    while(temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    return i;
}

// function for deleting the  node from list from a given position
struct Node * deleteAtGivenPosition(struct Node * start, int position)
{
    struct Node * temp = start;
    int listSize = sizeOfList(start);

    if(position == 1)
    {
        start = deleteFromBeginning(start);
        return start;
    }

    if(position == listSize)
    {
        start = deleteFromEnd(start);
        return start;
    }
    for(int i = 1; i <= position-2; i++)
    {
        temp = temp->next;
    }
    struct Node * deletedNode = temp->next;
    temp->next = deletedNode->next;
    free(deletedNode);
    return start;
}
int main()
{

    struct Node *list1, *list2, *list3, *list4;

    list1 = (struct Node *) malloc (sizeof(struct Node));
    list2 = (struct Node *) malloc (sizeof(struct Node));
    list3 = (struct Node *) malloc (sizeof(struct Node));
    list4 = (struct Node *) malloc (sizeof(struct Node));

    list1->data = 20;
    list1->next = list2;

    list2->data = 30;
    list2->next = list3;

    list3->data = 40;
    list3->next = list4;

    list4->data = 50;
    list4->next = NULL;

   printList(list1);
   list1 = deleteAtGivenPosition(list1, 1);
   printList(list1);
    return 0;
}