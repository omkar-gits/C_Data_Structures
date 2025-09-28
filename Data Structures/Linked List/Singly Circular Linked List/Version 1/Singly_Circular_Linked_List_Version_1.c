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
    int iToBeDeletedPosition = 21;
    printf("Data at position %d is %d\n", CountNodes(pFirst_1,pLast_1) , DeleteAtPosition(&pFirst_1 , &pLast_1 , CountNodes(pFirst_1,pLast_1)));
    Display(pFirst_1 , pLast_1);
    printf("\n");

    Display(pFirst_2 , pLast_2);
    
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
    struct node* pTemp = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
        return;
    }
    pNewNode->iData = iNo;
    if(NULL == *ppHead){
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail)->pNext = *ppHead;
        return;
    }

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

void InsertAtPosition(struct node** ppHead , struct node** ppTail , int iNo , int iPos){
    int iListSize = CountNodes(*ppHead , *ppTail);
    if(iPos <= 0 || iPos > iListSize+1){
        printf("Invalid Position..!\n");
        return;
    }

    if(NULL == *ppHead){
        return;
    }

    if(1 == iPos){
        InsertFirst(ppHead, ppTail , iNo);
        return;
    }

    if(iPos == iListSize+1){
        InsertLast(ppHead , ppTail , iNo);
        return;
    }
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
    }

    pNewNode->iData = iNo;

    pTemp = *ppHead;
    int iCounter = 1;

    while(iCounter < iPos-1){
        iCounter++;
        pTemp = pTemp->pNext;
    }
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
    return;    
}

int DeleteAtPosition(struct node** ppHead , struct node** ppTail , int iPos){
    int iListSize = CountNodes(*ppHead , *ppTail);
    int iDeletedData;
    
    if(iPos <= 0  || iPos > iListSize){
        printf("Invalid Position");
        return -1;
    }

    if(NULL == *ppHead){
        return -1;
    }

    if(1 == iPos){
        iDeletedData = DeleteFirst(ppHead , ppTail);
        return iDeletedData;
    }

    if(iPos == iListSize){
        iDeletedData = DeleteLast(ppHead , ppTail);
        return iDeletedData;
    }
    struct node* pTemp1 = NULL;
    struct node* pTemp2 = NULL;
    pTemp1 = *ppHead;
    
    int iCounter = 1;

    while(iCounter < iPos-1){
        iCounter++;
        pTemp1 = pTemp1->pNext;
    }
    pTemp2 = pTemp1->pNext;
    iDeletedData = pTemp2->iData;
    pTemp1->pNext = pTemp2->pNext;
    free(pTemp2);
    pTemp2 = NULL;
    return iDeletedData ;
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
    (*ppTail2)->pNext = *ppHead1;
    *ppTail1 = *ppTail2;
    *ppHead2 = *ppTail2 = NULL;
    return;
}

void ConcatAtPosition(struct node** ppHead1 , struct node** ppTail1 , struct node** ppHead2 , struct node** ppTail2 , int iPos){
    int iListSize = CountNodes(*ppHead1 , *ppTail1);
    if(iPos <= 0 || iPos > iListSize+1){
        printf("Invalid Position..!\n");
        return;
    }
    if(NULL == *ppHead2){
        return;
    }
    if(1 == iPos){
        ConcatLists(ppHead2 , ppTail2 , ppHead1 , ppTail1);
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;
        *ppHead2 = *ppTail2 = NULL;
        return;
    }
    if(iPos == iListSize+1){
        ConcatLists(ppHead1 , ppTail1 , ppHead2, ppTail2);
        *ppHead2 = *ppTail2 = NULL;
        return;
    }
    int iCounter = 1;
    struct node* pTemp1 = NULL;
    //struct node* pTemp2 = NULL;
    pTemp1 = *ppHead1;

    while(iCounter < iPos-1){
        iCounter++;
        pTemp1 = pTemp1->pNext;
    }

    (*ppTail2)->pNext = pTemp1->pNext;
    pTemp1->pNext = *ppHead2;

    *ppHead2 = *ppTail2 = NULL;
    return;
}

void PhysicalReverse(struct node** ppHead , struct node** ppTail){
    struct node* pPrev = *ppTail;
    struct node* pCurrent = *ppHead;
    struct node* pNext = NULL;
    if(NULL == *ppHead){
        return;
    }
    do{
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }while(pCurrent != *ppHead);
    *ppHead = pPrev;
    *ppTail = pCurrent;
    return;
}

void ReverseDisplay(struct node* pHead , struct node* pTail){
    if(NULL == pHead){
        return;
    }

    PhysicalReverse(&pHead , &pTail);
    Display(pHead , pTail);
    PhysicalReverse(&pHead , &pTail);
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