#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertLast(struct node** , int);
void Display(struct node*);
void DeleteAll(struct node**);

int main(void){
    struct node* pFirst = NULL;
    InsertLast(&pFirst , 10);
    InsertLast(&pFirst , 20);
    InsertLast(&pFirst , 30);
    InsertLast(&pFirst , 40);
    InsertLast(&pFirst , 50);
    Display(pFirst);
    // DeleteAll(&pFirst);
}

void InsertLast(struct node **ppHead , int iNo){
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!!\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
    if(NULL == *ppHead){
        *ppHead = pNewNode;
        return;
    }
    pTemp = *ppHead;

    while(pTemp->pNext !=NULL){
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;
    return;
}

void Display(struct node*pHead){
    if(NULL == pHead){
        printf("The List is empty..!\n");
        return;
    }
    while(pHead != NULL){
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}