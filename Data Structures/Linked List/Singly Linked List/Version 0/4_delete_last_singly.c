#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node*pNext;
};

void InsertLast(struct node**, int);
void Display(struct node*);
int DeleteLast(struct  node**);

int main(void){
    struct node* pFirst = NULL;
    InsertLast(&pFirst , 10);
    InsertLast(&pFirst , 20);
    InsertLast(&pFirst , 30);
    InsertLast(&pFirst , 40);
    InsertLast(&pFirst , 50);
    Display(pFirst);
    int iDeletedData = DeleteLast(&pFirst);
    Display(pFirst);
}

void InsertLast(struct node** ppHead , int iNo){
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed...!\n");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
    if(NULL == *ppHead){
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
    if(pHead == NULL){
        printf("List is already Empty..!\n");
        return;
    }

    while(pHead->pNext != NULL){
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

int DeleteLast(struct node** ppHead){
    int iDeletedData;
    struct node*pTemp = NULL;
    if(NULL == *ppHead){
        printf("The List is already empty..!\n");
        return -1;
    }
    pTemp = *ppHead;
    if(NULL == pTemp->pNext){
        iDeletedData = pTemp->iData;
        free(pTemp);
        return iDeletedData;
    }
    
    while(pTemp->pNext->pNext != NULL){
        pTemp = pTemp->pNext;
    }
    iDeletedData = pTemp->pNext->iData;
    free(pTemp->pNext);
    pTemp->pNext = NULL;
}