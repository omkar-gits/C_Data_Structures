#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , struct node**, int);
void InsertLast(struct node** , struct node**, int);
int DeleteFirst(struct node** , struct node**);
int DeleteLast(struct node** , struct node**);
void Display(struct node* ,struct node*);
int CountNodes(struct node* , struct node*);
int SearchFirstOccurrence(struct node* , struct node* , int);
int SearchLastOccurrence(struct node* , struct node* , int);
int SearchLastOccurrence(struct node* , struct node* , int);
void InsertAtPosition(struct node** , struct node** , int);
int DeleteAtPosition(struct node** , struct node**);
void ConcatLists(struct node** , struct node**);
void ConcatAtPosition(struct node** , struct node** , int);
void PhysicalReverse(struct node** , struct node**);
void ReverseDisplay(struct node*);
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
    printf("\nnode count = %d\n",CountNodes(pFirst,pLast));

    int FirstDeleted  = DeleteFirst(&pFirst , &pLast);
    if(-1 != FirstDeleted){
        printf("First data deleted %d\n", FirstDeleted);
    }
    Display(pFirst , pLast);
    printf("\nnode count = %d\n",CountNodes(pFirst,pLast));
    int LastDeleted = DeleteLast(&pFirst , &pLast);
     if(-1 != LastDeleted){
        printf("Last data deleted %d\n", LastDeleted);
    }
    Display(pFirst , pLast);
    printf("\nnode count = %d\n",CountNodes(pFirst,pLast));
    if(pFirst != NULL){
        DeleteAll(&pFirst , &pLast);
    }
    Display(pFirst , pLast);
    printf("\nnode count = %d\n",CountNodes(pFirst,pLast));
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
    struct node *pNewNode = NULL;
    struct node* pTemp = 
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
        return;
    }

    if(NULL == *ppHead){
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail)->pNext = *ppHead;
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = (*ppTail)->pNext;
    (*ppTail)->pNext = pNewNode;
    *ppTail = pNewNode;
    return;
}

int DeleteFirst(struct node** ppHead , struct node** ppTail){
    int iDeletedData;
    if(NULL == *ppHead){
        return -1;
    }
    iDeletedData = (*ppHead)->iData;
    *ppHead = (*ppHead)->pNext;
    free((*ppTail)->pNext);
    (*ppTail)->pNext = *ppHead;
    return iDeletedData;
}

int DeleteLast(struct node** ppHead, struct node**ppTail){
    struct node* pTemp = NULL;
    int iDeletedData;
    if(NULL == *ppHead){
        return -1;
    }
    iDeletedData = (*ppTail)->iData;
    pTemp = *ppHead;

    while(pTemp->pNext != *ppTail){
        pTemp = pTemp->pNext;
    }
    *ppTail = pTemp;
    free((*ppTail)->pNext);
    (*ppTail)->pNext = *ppHead;
    return iDeletedData;

}

int CountNodes(struct node* pHead , struct node* pTail){
    //struct node* pTemp = NULL;
    int iCounter = 0;
    if(NULL == pHead){
        return iCounter;
    }
    do{
        iCounter++;
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

    return iCounter;
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
    printf("\n");
}

int SearchFirstOccurrence(struct node* pHead , struct node* pTail , int iKey){

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