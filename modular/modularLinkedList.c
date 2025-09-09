#include<stdio.h>
#include<malloc.h>
#include "SinglyLinkedList.h"

int main(void){
    struct node* pFirst = NULL;
    InsertFirst(&pFirst , 40);
    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);
    InsertLast(&pFirst , 50);
    InsertLast(&pFirst , 60);
    InsertLast(&pFirst , 70);
    InsertLast(&pFirst , 80);
    DeleteAll(&pFirst);
}