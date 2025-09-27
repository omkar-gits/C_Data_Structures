#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , struct node**, int);
void InsertFirst(struct node** , struct node**, int);
void Display(struct node* ,struct node*);
void DeleteAll(struct node** , struct node**);

int main(void){
    struct node* pFirst = NULL;
    struct node* pLast = NULL;

    InsertFirst(&pFirst , &pLast , 50);
    InsertFirst(&pFirst , &pLast , 40);
    InsertFirst(&pFirst , &pLast , 30);
    InsertFirst(&pFirst , &pLast , 20);
    InsertFirst(&pFirst , &pLast , 10);

    InsertLast(&pFirst , &pLast , 100);
    InsertLast(&pFirst , &pLast , 200);
    InsertLast(&pFirst , &pLast , 300);
    InsertLast(&pFirst , &pLast , 400);
    InsertLast(&pFirst , &pLast , 500);

    Display(pFirst , pLast);
    if(pFirst != NULL){
        DeleteAll(&pFirst , &pLast);
    }
    Display(pFirst , pLast);
    return 0;
}

void InsertFirst(struct node** ppHead , struct node** ppTail , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed ...!\n");
        return;
    }
    pNewNode->iData = iNo;
    if(NULL == *ppHead){
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail)->pNext = *ppHead;
        return;
    }
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
    (*ppTail)->pNext = *ppHead;

}

void InsertLast(struct node** ppHead, struct node** ppTail , int iNo){
    
}

void Display(struct node* pHead , struct node* pTail){
    if(NULL == pHead){
        printf("\nThe list is already Emtpy..\n");
        return;
    }
    do{
        printf("|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);
    

}

void DeleteAll(struct node** ppHead  ,struct node** ppTail){
    struct node* pTemp = NULL;
    (*ppTail)->pNext = NULL;

    while(*ppHead != NULL){
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    *ppTail = NULL;
    return;

}