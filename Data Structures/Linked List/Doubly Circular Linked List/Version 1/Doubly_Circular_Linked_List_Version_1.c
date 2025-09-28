#include<stdio.h>
#include<malloc.h>

struct node{
    struct node* pPrev;
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
int SearchAllOccurrences(struct node* , struct node* , int);
void InsertAtPosition(struct node** , struct node** , int , int);
int DeleteAtPosition(struct node** , struct node** , int);
void ConcatLists(struct node** , struct node** , struct node** , struct node**);
void ConcatAtPosition(struct node** , struct node**,struct node** , struct node** , int);
void PhysicalReverse(struct node** , struct node**);
void ReverseDisplay(struct node* , struct node*);
void DeleteAll(struct node** , struct node**);

int main(void){
struct node* pFirst_1 = NULL;
    struct node* pLast_1 = NULL;

    struct node* pFirst_2 = NULL;
    struct node* pLast_2 = NULL;

    InsertFirst(&pFirst_1 , &pLast_1 , 50);
    InsertFirst(&pFirst_1 , &pLast_1 , 40);
    InsertFirst(&pFirst_1 , &pLast_1 , 30);
    InsertFirst(&pFirst_1 , &pLast_1 , 20);
    InsertFirst(&pFirst_1 , &pLast_1 , 10);

    InsertLast(&pFirst_1 , &pLast_1 , 100);
    InsertLast(&pFirst_1 , &pLast_1 , 200);
    InsertLast(&pFirst_1 , &pLast_1 , 100);
    InsertLast(&pFirst_1 , &pLast_1 , 300);
    InsertLast(&pFirst_1 , &pLast_1 , 100);
    InsertLast(&pFirst_1 , &pLast_1 , 400);
    InsertLast(&pFirst_1 , &pLast_1 , 100);
    InsertLast(&pFirst_1 , &pLast_1 , 500);
    InsertLast(&pFirst_1 , &pLast_1 , 100);


    InsertLast(&pFirst_2 , &pLast_2 , 3321);
    InsertLast(&pFirst_2 , &pLast_2 , 3322);
    InsertLast(&pFirst_2 , &pLast_2 , 3323);
    InsertLast(&pFirst_2 , &pLast_2 , 3324);

    Display(pFirst_1 , pLast_1);
    printf("\nnode count = %d\n",CountNodes(pFirst_1,pLast_1));

    int FirstDeleted  = DeleteFirst(&pFirst_1 , &pLast_1);
    if(-1 != FirstDeleted){
        printf("First data deleted %d\n", FirstDeleted);
    }
    Display(pFirst_1 , pLast_1);
    printf("\nnode count = %d\n",CountNodes(pFirst_1,pLast_1));
    int LastDeleted = DeleteLast(&pFirst_1 , &pLast_1);
     if(-1 != LastDeleted){
        printf("Last data deleted %d\n", LastDeleted);
    }
    Display(pFirst_1 , pLast_1);
    printf("\nnode count = %d\n",CountNodes(pFirst_1,pLast_1));
    int iFirstToBeSearched = 100;
    printf("\nFirst Occurrence of %d is at position %d\n",iFirstToBeSearched, SearchFirstOccurrence(pFirst_1 , pLast_1 , iFirstToBeSearched));

    int iLastToBeSearched = 100;
    printf("\nLast Occurrence of %d is at position %d\n",iLastToBeSearched , SearchLastOccurrence(pFirst_1 , pLast_1 , iLastToBeSearched));

    int iAllOccurrencesToBeSearched = 100;
    printf("\nAll Occurrences of %d is/are %d \n", iAllOccurrencesToBeSearched , SearchAllOccurrences(pFirst_1 , pLast_1 , iAllOccurrencesToBeSearched));

    InsertAtPosition(&pFirst_1 , &pLast_1 , 10001, 3);
    Display(pFirst_1 , pLast_1);
    printf("\n");
    InsertAtPosition(&pFirst_1 , &pLast_1 , 100001 , 6);
    Display(pFirst_1 , pLast_1);
    printf("\n");
    InsertAtPosition(&pFirst_1 , &pLast_1 , 100001 , 9);
    Display(pFirst_1 , pLast_1);
    printf("\n");
    int iToBeDeletedPosition = 3;
    printf("Data at position %d is %d\n", iToBeDeletedPosition , DeleteAtPosition(&pFirst_1 , &pLast_1 , iToBeDeletedPosition));
    Display(pFirst_1 , pLast_1);
    printf("\n");


    Display(pFirst_2 , pLast_2);

    printf("\nConcatList\n");
    //ConcatLists(&pFirst_1 , &pLast_1 , &pFirst_2 , &pLast_2);
    printf("\n");

    Display(pFirst_1 , pLast_1);
    printf("\n");
    Display(pFirst_2 , pLast_2);
    printf("\n");
    printf("Concat at position\n");
    ConcatAtPosition(&pFirst_1 , &pLast_1 , &pFirst_2 , &pLast_2 , 5);
    Display(pFirst_1 , pLast_1);
    printf("\n");

    printf("Physical Reverse..\n");
    PhysicalReverse(&pFirst_1 , &pLast_1);
    Display(pFirst_1 , pLast_1);
    printf("\n");
    PhysicalReverse(&pFirst_1 , &pLast_1);
    Display(pFirst_1 , pLast_1);
    printf("\n");

    printf("Reverse Display..\n");
    ReverseDisplay(pFirst_1 , pLast_1);

    if(pFirst_1 != NULL){
        DeleteAll(&pFirst_1 , &pLast_1);
    }
    if(pFirst_2 != NULL){
        DeleteAll(&pFirst_2 , &pLast_2);
    }
    Display(pFirst_1 , pLast_1);
    printf("\nnode count = %d\n",CountNodes(pFirst_1,pLast_1));
    return 0;
}

void InsertFirst(struct node** ppHead , struct node** ppTail , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
        return;
    }

    pNewNode->iData = iNo;

    if(NULL == *ppHead){
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
        return;
    }
    pNewNode->pNext = *ppHead;
    pNewNode->pPrev = *ppTail;
    (*ppHead)->pPrev = pNewNode;
    (*ppTail)->pNext = pNewNode;
    *ppHead = pNewNode;
    return;
}

void InsertLast(struct node** ppHead , struct node** ppTail , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
        return;
    }
    pNewNode->iData = iNo;

    if(NULL == *ppHead){
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppHead)->pPrev = *ppTail;
        (*ppTail)->pNext = *ppHead;
        return;
    }
    pNewNode->pPrev = *ppTail;
    pNewNode->pNext = *ppHead;
    (*ppTail)->pNext = pNewNode;
    (*ppHead)->pPrev = pNewNode;
    *ppTail = pNewNode;
}

int DeleteFirst(struct node** ppHead , struct node** ppTail){
    int iDeletedData;
    if(NULL == *ppHead){
        return -1;
    }
    iDeletedData = (*ppHead)->iData;
    if(*ppHead == *ppTail){
        free(*ppHead);
        *ppHead = *ppTail = NULL;
    }
    else{
        *ppHead = (*ppHead)->pNext;
        free((*ppTail)->pNext);
        (*ppTail)->pNext = *ppHead;
        (*ppHead)->pPrev = *ppTail;
    }
    return iDeletedData;
}

int DeleteLast(struct node** ppHead , struct node** ppTail){
    int iDeletedData;
    struct node* pTemp = NULL;
    if(NULL == *ppHead){
        return -1;
    }
    iDeletedData = (*ppTail)->iData;

    if(*ppHead == *ppTail){
        free(*ppTail);
        *ppHead = *ppTail = NULL;
    }
    else{
        pTemp = (*ppTail)->pPrev;
        free(*ppTail);
        *ppTail = pTemp;
        (*ppTail)->pNext = *ppHead;
        (*ppHead)->pPrev = *ppTail;
        pTemp = NULL;
        
    }
    return iDeletedData;
}

int CountNodes(struct node* pHead , struct node* pTail){
    int iCount = 0;
    if(NULL == pHead){
        return iCount;
    }
    do{
        iCount++;
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);
    return iCount;
}


int SearchFirstOccurrence(struct node* pHead , struct node* pTail , int iKey){
    int iFirstOccurrence;
    int iCounter = 0;
    if(NULL == pHead){
        return -1;
    }
    do{
        iCounter ++;
        if(pHead->iData == iKey){
            iFirstOccurrence = iCounter;
            return iFirstOccurrence;
        }
        pHead = pHead->pNext;  
    }while(pHead != pTail->pNext);   
}

int SearchLastOccurrence(struct node*pHead, struct node* pTail, int iKey){
    int iLastOccurrence;
    int iCounter;

    if(NULL == pHead){
        return -1;
    }
    do{
        iCounter ++;
        if(pHead->iData == iKey){
            iLastOccurrence = iCounter;
        }
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);
    return iLastOccurrence;
}

int SearchAllOccurrences(struct node* pHead, struct node* pTail , int iKey){
    int iAllOccurrences;
    int iCounter;

    if(NULL == pHead){
        return -1;
    }

    do{
        iCounter++;
        if(pHead->iData == iKey){
            iAllOccurrences ++;
        }
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);
    return iAllOccurrences;
}

void InsertAtPosition(struct node** ppHead, struct node** ppTail , int iNo , int iPos){
    int iListSize = CountNodes(*ppHead, *ppTail);
    if(iPos <= 0 || iPos > iListSize+1){
        printf("Invalid Position..!\n");
        return;
    }
    if(NULL == *ppHead){
        return;
    }

    if(1 == iPos){
        InsertFirst(ppHead , ppTail ,iNo);
        return;
    }
    if(iPos == iListSize+1){
        InsertLast(ppHead ,ppTail, iNo);
        return;
    }

    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed.!\n");
        return;
    }

    pNewNode->iData = iNo;
    int iCounter = 1;
    struct node* pTemp = NULL;
    pTemp = *ppHead;
    while(iCounter < iPos -1){
        iCounter++;
        pTemp = pTemp->pNext;
    }
    
    pNewNode->pNext = pTemp->pNext;
    pNewNode->pNext->pPrev = pNewNode;
    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;
    pTemp = NULL;
    return;

}

int DeleteAtPosition(struct node** ppHead ,struct node** ppTail , int iPos){
    int iDeletedData;
    int iListSize = CountNodes(*ppHead , *ppTail);

    if(iPos <= 0 || iPos > iListSize){
        printf("Invalid Position..!\n");
        return -1;
    }

    if(NULL == *ppHead){
        return -1;
    }

    if(1 == iPos){
        iDeletedData = DeleteFirst(ppHead , ppTail);
        return iDeletedData;
    }

    if(iListSize == iPos){
        iDeletedData = DeleteLast(ppHead , ppTail);
        return iDeletedData;
    }

    struct node* pTemp = NULL;
    pTemp = *ppHead;

    int iCounter = 1;
    while(iCounter < iPos -1){
        iCounter++;
        pTemp = pTemp->pNext;
    }
    iDeletedData = pTemp->pNext->iData;
    pTemp->pNext = pTemp->pNext->pNext;
    free(pTemp->pNext->pPrev);
    pTemp->pNext->pPrev = pTemp;
    return iDeletedData;
}

void Display(struct node* pHead , struct node* pTail){
    if(NULL == pHead){
        printf("\nThe list is already Empty..\n");
        return;
    }
    do{
        printf("<-|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }while(pHead != pTail->pNext);

}

void ConcatLists(struct node** ppHead1 , struct node** ppTail1 , struct node** ppHead2 , struct node** ppTail2){
    if(NULL == *ppHead2){
        return;
    }
    if(NULL == *ppHead1){
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;
        *ppHead2 = *ppTail2 = NULL;
        return;
    }
    (*ppTail1)->pNext = *ppHead2;
    (*ppHead2)->pPrev = *ppTail1;
    (*ppTail2)->pNext = *ppHead1;
    (*ppHead1)->pPrev = *ppTail2;
    *ppTail1 = *ppTail2;
    *ppHead2 = *ppTail2 = NULL;
    return;
}

void ConcatAtPosition(struct node** ppHead1 , struct node** ppTail1 , struct node** ppHead2 , struct node** ppTail2 , int iPos){
    int iListSize = CountNodes(*ppHead1 , *ppTail1);
    if(iPos <= 0|| iPos > iListSize+1){
        printf("Invalud Position..!\n");
        return;
    }
    if(NULL == *ppHead2){
        return;
    }
    if(NULL == *ppHead1){
        ConcatLists(ppHead2 , ppTail2 , ppHead1 , ppTail1);
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;
        *ppHead2 = *ppTail2 = NULL;
        return;
    }
    struct node* pTemp = NULL;
    int iCounter = 1;
    pTemp = *ppHead1;
    while(iCounter < iPos - 1){
        iCounter++;
        pTemp = pTemp->pNext;
    }
    (*ppTail2)->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = (*ppTail2);
    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;
    *ppHead2 = *ppTail2 = NULL;
    return;
}

void PhysicalReverse(struct node** ppHead , struct node** ppTail){
    struct node* pPrev = NULL;
    struct node* pCurrent = *ppHead;

    if(NULL == *ppHead){
        return;
    }
    do{
        pPrev = pCurrent->pPrev;
        pCurrent->pPrev = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pCurrent = pCurrent->pPrev;
        
    }while(pCurrent != *ppHead);
    pPrev = *ppHead;
    *ppHead = *ppTail;
    *ppTail = pPrev;
    return;
}

void ReverseDisplay(struct node* pHead,  struct node* pTail){
    if(NULL == pHead){
        printf("\nThe list is already Empty..\n");
        return;
    }
    do{
        printf("<-|%d|->", pTail->iData);
        pTail = pTail->pPrev;
    }while(pHead != pTail->pNext);
    return;
}

void DeleteAll(struct node** ppHead, struct node** ppTail){
    struct node* pTemp = NULL;
    if(NULL == *ppHead){
        return;
    }
    (*ppTail)->pNext = NULL;

    while(*ppHead != NULL){
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    *ppTail = NULL;
    return;
}