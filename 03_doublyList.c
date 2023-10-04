#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * prev;
    struct Node * next;
};

void printDoublyList(struct Node *start)
{
    struct Node * temp, *endPoint;
    temp = start;
    while(temp != NULL)
    {
        if(temp->next == NULL)
        {
            endPoint = temp;
        }
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
  
    while(endPoint != NULL)
    {
        printf("%d\t", endPoint->data);
        endPoint = endPoint->prev;
    }
}

int main(void)
{

    struct Node *list1, *list2, *list3, *list4;

    list1 = (struct Node *)malloc(sizeof(struct Node));
    list2 = (struct Node *)malloc(sizeof(struct Node));
    list3 = (struct Node *)malloc(sizeof(struct Node));
    list4 = (struct Node *)malloc(sizeof(struct Node));

    list1->data = 10;
    list1->next = list2;
    list1->prev = NULL;

    list2->data = 20;
    list2->next = list3;
    list2->prev = list1;

    list3->data = 30;
    list3->next = list4;
    list3->prev = list2;

    list4->data = 40;
    list4->next = NULL;
    list4->prev = list3;

    printDoublyList(list1);
    return 0;
}