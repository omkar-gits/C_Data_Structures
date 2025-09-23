#include<stdio.h>
#include<malloc.h>

struct node{
    struct node* pPrev;
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node **, int);
void InsertLast(struct node **, int);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
void Display(struct node *);
int CountNodes(struct node *);
int SearchFirstOccurrence(struct node *, int);
int SearchLastOccurrence(struct node *, int);
int SearchAllOccurrences(struct node *, int);
void InsertAtPosition(struct node **, int, int);
int DeleteAtPosition(struct node **, int);
void ConcatLists(struct node **, struct node **);
void ConcatAtPosition(struct node **, struct node **, int);
void PhysicalReverse(struct node **);
void ReverseDisplay(struct node *);
void DeleteAll(struct node **);

int main(void)
{
    int iData;
    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    Display(pFirst); // List is empty

    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);

    Display(pFirst); // 10 20 30

    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    InsertLast(&pFirst, 60);

    Display(pFirst); // 10 20 30 40 50 60

    InsertAtPosition(&pFirst, 20, 4);

    Display(pFirst); // 10 20 30 20 40 50 60

    iData = DeleteFirst(&pFirst);
    if (iData != -1)
        printf("Deleted data is %d\n", iData); // 10

    Display(pFirst); // 20 30 20 40 50 60

    iData = DeleteLast(&pFirst);
    if (iData != -1)
        printf("Deleted data is %d\n", iData); // 60

    Display(pFirst); // 20 30 20 40 50

    iData = DeleteAtPosition(&pFirst, 4);
    if (iData != -1)
        printf("Deleted data is %d\n", iData); // 40

    Display(pFirst); // 20 30 20 50

    iData = CountNodes(pFirst);
    printf("Total node count is %d\n", iData); // 4

    iData = SearchFirstOccurrence(pFirst, 20);
    if (iData != 0)
        printf("First occurrence of %d is at %d position\n", 20, iData); // 1

    iData = SearchLastOccurrence(pFirst, 20);
    if (iData != 0)
        printf("Last occurrence of %d is at %d position\n", 20, iData); // 3

    iData = SearchAllOccurrences(pFirst, 20);
    printf("%d found %d times\n", 20, iData); // 2

    Display(pFirst);        // 20 30 20 50
    ReverseDisplay(pFirst); // 50 20 30 20
    Display(pFirst);        // 20 30 20 50
    PhysicalReverse(&pFirst);
    Display(pFirst); // 50 20 30 20

    InsertLast(&pSecond, 100);
    InsertLast(&pSecond, 200);
    InsertLast(&pSecond, 300);

    Display(pFirst);  // 50 20 30 20
    Display(pSecond); // 100 200 300
    ConcatLists(&pFirst, &pSecond);
    Display(pFirst);  // 50 20 30 20 100 200 300
    Display(pSecond); // List is empty

    InsertLast(&pSecond, 400);
    InsertLast(&pSecond, 500);
    InsertLast(&pSecond, 600);

    Display(pFirst);  // 50 20 30 20 100 200 300
    Display(pSecond); // 400 500 600
    ConcatAtPosition(&pFirst, &pSecond, 4);
    Display(pFirst);  // 50 20 30 400 500 600 20 100 200 300
    Display(pSecond); // List is empty
    if (pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }
    if (pSecond != NULL)
    {
        DeleteAll(&pSecond);
        pSecond = NULL;
    }
    Display(pFirst);  // List is empty
    Display(pSecond); // List is empty
    return 0;
}

void InsertFirst(struct node**ppHead , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory Allocation Failed .!\n");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    // if(NULL == *ppHead){
    //     pNewNode->pNext = NULL;
    //     *ppHead = pNewNode;
    //     return;
    // }
    pNewNode->pNext = *ppHead;
    (*ppHead)->pPrev = pNewNode;
    *ppHead = pNewNode;
    return;
}

void InsertLast(struct node**ppHead , int iNo){
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
        return;
    }
    pNewNode ->iData = iNo;
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
    pTemp->pNext = pNewNode;
    pNewNode->pPrev = pTemp;
    return;
}

int DeleteFirst(struct node** ppHead){
    int iDeletedData;
    if(NULL == *ppHead){
        return -1;
    }
    iDeletedData = (*ppHead)->iData;
    if(NULL == (*ppHead)->pNext){
        free(*ppHead);
        *ppHead = NULL;
    }
    else{
        *ppHead = (*ppHead)->pNext;
        free((*ppHead)->pPrev);
        (*ppHead)->pPrev = NULL;
    }
    return iDeletedData;
}

int DeleteLast(struct node** ppHead){
    int iDeletedData;
    struct node* pTemp = NULL;
    if(NULL == *ppHead){
        return -1;
    }
    if((*ppHead)->pNext == NULL){
        iDeletedData = (*ppHead)->iData;
        free(*ppHead);
        *ppHead = NULL;
    }
    else{
        pTemp = *ppHead;
        while(pTemp->pNext != NULL){
            pTemp = pTemp->pNext;
        }
        iDeletedData = pTemp->iData;
        free(pTemp->pNext);
        pTemp->pNext = NULL;
    }
    return iDeletedData;
}

void Display(struct node *pHead){
    if(NULL == pHead){
        printf("List is already empty..!\n");
        return;
    }
    printf("NULL");
    while(pHead != NULL){
        printf("<-|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
    return;
}

int CountNodes(struct node* pHead){
    int iListSize = 0;
    while(pHead != NULL){
        iListSize++;
        pHead = pHead->pNext;
    }
    return iListSize;
}

int SearchFirstOccurrence(struct node* pHead , int iKey){
    int iPos = 0;
    while(pHead != NULL){
        iPos++;
        if(pHead->iData == iKey){
            return iPos;
        }
        pHead = pHead->pNext;
    }
    return iPos;
}

int SearchLastOccurrence(struct node* pHead , int iKey){
    int iPos = 0;
    int iLastFoundPos = 0;
    while(pHead != NULL){
        iPos++;
        if(pHead->iData == iKey){
            iLastFoundPos = iPos;
        }
        pHead = pHead->pNext;
    }
    return iLastFoundPos;
}

int SearchAllOccurrences(struct node* pHead , int iKey){
    int iPos = 0;
    int iAllOccurrenceCount = 0;
    while(pHead != NULL){
        iPos++;
        if(pHead->iData == iKey){
            iAllOccurrenceCount++;
        }
        pHead = pHead->pNext;
    }
    return iAllOccurrenceCount;
}

void InsertAtPosition(struct node** ppHead , int iNo , int iPos){
    
}


void DeleteAll(struct node** ppHead){
    struct node * pTemp = NULL;
    if(NULL == *ppHead){
        return;
    }
    while(*ppHead != NULL){
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    return;
}