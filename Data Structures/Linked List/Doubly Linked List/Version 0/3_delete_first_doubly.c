#include<stdio.h>
#include<malloc.h>

struct node{
    struct node* pPrev;
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , int);
void Display(struct node*);
int DeleteFirst(struct node**);

int main(void){
    struct node* pFirst = NULL;
    int iDeletedData;
    InsertFirst(&pFirst , 50);
    InsertFirst(&pFirst , 40);
    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);
    Display(pFirst);
    iDeletedData = DeleteFirst(&pFirst);
    Display(pFirst);
    printf("The deleted data is %d", iDeletedData);
}


void InsertFirst(struct node**ppHead , int iNO){
    struct node*pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed..\n");
        return;
    }

    pNewNode->iData = iNO;
    pNewNode->pPrev = NULL;
    if(NULL == *ppHead){
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
    }
    else{pNewNode->pNext = *ppHead;
    (*ppHead)->pPrev = pNewNode;
    *ppHead = pNewNode;
    }
}

void Display(struct node*pHead){
    if(NULL == pHead){
        printf("The List is empty..!\n");
        return;
    }
    printf("NULL");
    while(pHead != NULL){
        printf("<-|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

int DeleteFirst(struct node**ppHead){
    int iDelData;
    if(NULL == *ppHead){
        return -1;
    }
    iDelData = (*ppHead)->iData;
    if(NULL == (*ppHead)->pNext){
        free(*ppHead);
        *ppHead = NULL;
    }

    else{
        *ppHead = (*ppHead)->pNext;
        (*ppHead)->pPrev->pNext = NULL;
        free((*ppHead)->pPrev);
        (*ppHead)->pPrev = NULL; 
    }

    return iDelData;
}

