#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, int);
void Display(struct node *);
void DeleteAll(struct node **);
int CountNodes(struct node *);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node **, int);

int main(void)
{
    int iPosition = 5;
    struct node *pFirst = NULL;
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);

    Display(pFirst);
    int iDeletedData = DeleteAtPosition(&pFirst, iPosition);
    printf("The Data at %d position is %d", iPosition, iDeletedData);
    Display(pFirst);
    if (NULL != pFirst)
    {
        DeleteAll(&pFirst);
    }
    Display(pFirst);
    return 0;
}

void InsertFirst(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory Allocation Failed..!\n");
        return;
    }

    pNewNode->iData = iNo;
    pNewNode->pPrev = NULL;

    if (NULL == *ppHead)
    {
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }

    (*ppHead)->pPrev = pNewNode;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
    return;
}

void Display(struct node *pHead)
{
    if (NULL == pHead)
    {
        printf("The List is already empty..!\n");
        return;
    }
    printf("\nNULL");
    while (pHead != NULL)
    {
        printf("<-|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
    return;
}

int CountNodes(struct node *pHead)
{
    int iCount = 0;
    while (pHead != NULL)
    {
        iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
}

int DeleteFirst(struct node **ppHead)
{
    int iDeletedData;
    if (NULL == *ppHead)
    {
        return -1;
    }
    iDeletedData = (*ppHead)->iData;
    if (NULL == (*ppHead)->pNext)
    {
        free(*ppHead);
        *ppHead = NULL;
    }
    else
    {
        *ppHead = (*ppHead)->pNext;
        (*ppHead)->pPrev->pNext = NULL;
        free((*ppHead)->pPrev);
        (*ppHead)->pPrev = NULL;
    }
    return iDeletedData;
}

int DeleteLast(struct node **ppHead)
{
    struct node *pTemp = NULL;
    int iDeletedData = 0;
    if (NULL == *ppHead)
    {
        return -1;
    }

    pTemp = *ppHead;
    if (NULL == pTemp->pNext)
    {
        iDeletedData = pTemp->iData;
        free(pTemp);
        pTemp = NULL;
        return iDeletedData;
    }
    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    iDeletedData = pTemp->iData;
    pTemp->pPrev->pNext = NULL;
    pTemp->pPrev = NULL;
    free(pTemp);
    return iDeletedData;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
    int iListSize = CountNodes(*ppHead);
    int iDeletedData;
    struct node *pTemp = NULL;
    if (iPos <= 0 || iPos > iListSize)
    {
        printf("Invalid Position..!\n");
        return -1;
    }
    if (NULL == *ppHead)
    {
        return -1;
    }
    if (1 == iPos)
    {  
        return DeleteFirst(ppHead);
    }
    if (iPos == iListSize)
    {
        return DeleteLast(ppHead);
    }
    int iCount = 1;
    pTemp = *ppHead;
    while (iCount < iPos-1)
    {
        iCount++;
        pTemp = pTemp->pNext;
    }
    pTemp->pPrev->pNext = pTemp->pNext;
    // if(pTemp->pNext != NULL){
    //     pTemp->pNext->pPrev = pTemp->pPrev;
    // }
    pTemp->pNext->pPrev = pTemp->pPrev;
    iDeletedData = pTemp->iData;
    free(pTemp);
    pTemp = NULL;
    return iDeletedData;
}

void DeleteAll(struct node **ppHead)
{
    struct node *pTemp = NULL;
    if (NULL == *ppHead)
    {
        return;
    }
    while (*ppHead != NULL)
    {
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    return;
}
