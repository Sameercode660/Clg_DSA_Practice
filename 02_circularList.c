#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printCircularSinglyList(struct Node *start)
{
    struct Node *temp = start;
   
    do {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != start);

    printf("\n");
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

    list2->data = 20;
    list2->next = list3;

    list3->data = 30;
    list3->next = list4;

    list4->data = 40;
    list4->next = list1;

    printCircularSinglyList(list1);
    return 0;
}