#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertLast(struct node** ,int);
void PhysicalReverse(struct node**);
void ReverseDisplay(struct node*);
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
    ReverseDisplay(pFirst);
    if(NULL != pFirst){
        DeleteAll(&pFirst);
    }
    Display(pFirst);
}

void InsertLast(struct node **ppHead , int iNo){
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory Allocation Failed ..\n");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;

    if(NULL == *ppHead ){
        *ppHead = pNewNode;
        return;
    }
    pTemp = *ppHead;
    while(pTemp->pNext != NULL){
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;
    return;
}


void Display(struct node* pHead){
    if(NULL == pHead){
        printf("The list is already empty..!\n");
        return;
    }
    while(pHead != NULL){
        printf("|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
    return;
}

void DeleteAll(struct node **ppHead){
    struct node* pTemp = NULL;
    if(NULL == *ppHead){
        return;
    }
    while(*ppHead != NULL){
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
}

void PhysicalReverse(struct node** ppHead){
    struct node* pCurrent = *ppHead;
    struct node* pPrev = NULL;
    struct node* pNext = NULL;

    while(pCurrent != NULL){
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    *ppHead = pPrev;
}

void ReverseDisplay(struct node *pHead){
    if(NULL == pHead){
        printf("List already Empty...!\n");
        return;
    }
    PhysicalReverse(&pHead);
    Display(pHead);
    PhysicalReverse(&pHead);
}