#include<stdio.h>
#include<malloc.h>

struct node{
    struct node* pPrev;
    int iData;
    struct node *pNext;
};

void InsertAtPosition(struct node** , int , int);
void Display(struct node*);
void DeleteAll(struct node**);
void InsertFirst(struct node** , int);
void InsertLast(struct node**, int);
int CountNodes(struct node*);

int main(void){
    struct node* pFirst = NULL;
    InsertFirst(&pFirst , 40);
    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);
    Display(pFirst);
    InsertAtPosition(&pFirst ,100 , 5);
    Display(pFirst);
    DeleteAll(&pFirst);
    Display(pFirst);
}

void InsertFirst(struct node **ppHead , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    if(NULL == *ppHead){
        pNewNode->pNext  = NULL;
        *ppHead = pNewNode;
        return;
    }
    else{
        pNewNode->pNext = *ppHead;
        (*ppHead)->pPrev = pNewNode;
        *ppHead = pNewNode;
    }
    return ;
}

void InsertLast(struct node** ppHead , int iNo){
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
    if(NULL == *ppHead){
        pNewNode->pPrev = NULL;
        *ppHead = pNewNode;
        return;
    }
    pTemp = *ppHead;
    while(pTemp->pNext != NULL){
        pTemp = pTemp->pNext;
    }
    pNewNode->pPrev = pTemp;
    pTemp->pNext = pNewNode;
    return;
}

void Display(struct node*pHead){
    if(NULL == pHead){
        printf("List is already empty..\n");
        return;
    }

    while(pHead != NULL){
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
    return;
}

void DeleteAll(struct node** ppHead){
    struct node* pTemp = NULL;
    if(NULL == *ppHead){
        return;
    }
    
    while(NULL != *ppHead){
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    return;
}

int CountNodes(struct node* pHead){
    int iCount = 0;
    while(pHead != NULL){
        iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
}

/**
 * InsertAtPosition
 * position < 0 Invalid
 * position = 0 position Invalid
 * position =  list size + 1 Valid
 * position > listsize +1 invalid
 * 
*/
void InsertAtPosition(struct node** ppHead , int iNo , int  iPos){
    int iSize = CountNodes(*ppHead);
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;

    if(iPos <= 0 || iPos > iSize+1){
        printf("Invalid Position..!\n");
        return;
    }
    if(1 == iPos){
        InsertFirst(ppHead , iNo);
        return;
    }
    // if(iPos == iSize+1){
    //     InsertLast(ppHead , iNo);
    //     return;
    // }
    else{
        iSize = 1;
        pNewNode = (struct node*)malloc(sizeof(struct node));
        if(NULL == pNewNode){
            printf("Memory Allocation Failed..!\n");
            return;
        }
        pNewNode->iData = iNo;
        pTemp = *ppHead;
        while (iSize != iPos - 1)
        {
            iSize++;
            pTemp = pTemp->pNext;
        }
        pNewNode->pNext = pTemp->pNext;
        if(pTemp->pNext != NULL){
            pTemp->pNext->pPrev = pNewNode;
        }
        pTemp->pNext = pNewNode;
        pNewNode->pPrev = pTemp;        
    }
    return;
}