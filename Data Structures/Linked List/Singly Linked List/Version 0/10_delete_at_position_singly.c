#include <stdio.h>
#include <malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **, int);
void Display(struct node *);
int DeleteFirst(struct node **);
int DeleteLast(struct node **);
int DeleteAtPosition(struct node **ppHead, int iPos);
void DeleteAll(struct node **);
int CountNodes(struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    int iPosition = 3;
    int iDeletedData;
    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);
    InsertLast(&pFirst, 40);
    InsertLast(&pFirst, 50);
    Display(pFirst);
    iDeletedData = DeleteAtPosition(&pFirst, iPosition);
    Display(pFirst);
    printf("Deleted Data at Postion %d  is %d\n", iPosition, iDeletedData);
    if(NULL != pFirst){
        DeleteAll(&pFirst);
    }
    return 0;
}

void InsertLast(struct node **ppHead, int iNo)
{
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if (NULL == pNewNode)
    {
        printf("Memory Allocation Failed..!!\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
    if (NULL == *ppHead)
    {
        *ppHead = pNewNode;
        return;
    }
    pTemp = *ppHead;
    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;
    return;
}

int DeleteFirst(struct node **ppHead)
{
    struct node *pTemp = NULL;
    int DeletedData;
    if (NULL == *ppHead)
    {
        printf("List is already Empty..!\n");
        return -1;
    }
    pTemp = *ppHead;
    DeletedData = pTemp->iData;
    *ppHead = pTemp->pNext;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;
    return DeletedData;
}

int DeleteLast(struct node **ppHead)
{
    int iDeletedData;
    struct node *pTemp = NULL;
    if (NULL == *ppHead)
    {
        printf("The List is already empty..!\n");
        return -1;
    }
    pTemp = *ppHead;
    if (NULL == pTemp->pNext)
    {
        iDeletedData = pTemp->iData;
        free(pTemp);
        return iDeletedData;
    }

    while (pTemp->pNext->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }
    iDeletedData = pTemp->pNext->iData;
    free(pTemp->pNext);
    pTemp->pNext = NULL;
}

int CountNodes(struct node *pHead)
{
    int iCount = 0;
    while (NULL != pHead)
    {
        iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
}

void Display(struct node *pHead)
{
    if (pHead == NULL)
    {
        printf("The List is empty..!\n");
        return;
    }
    while (pHead != NULL)
    {
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
    return;
}

int DeleteAtPosition(struct node **ppHead, int iPos)
{
    int iDeletedData;
    int iSize = CountNodes(*ppHead);
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;

    if (iPos <= 0 || iPos > iSize)
    {
        printf("Position is Invalid ..!\n");
        return -1;
    }
    if (1 == iPos)
    {
        iDeletedData = DeleteFirst(ppHead);
        return iDeletedData;
    }
    if (iPos == iSize)
    {
        iDeletedData = DeleteLast(ppHead);
        return iDeletedData;
    }

    if (*ppHead == NULL)
    {
        return -1;
    }

    iSize = 1;
    pTemp1 = *ppHead;
    while (iSize < iPos - 1)
    {
        iSize++;
        pTemp1 = pTemp1->pNext;
    }
    pTemp2 = pTemp1->pNext;
    iDeletedData = pTemp2->iData;
    pTemp1->pNext = pTemp2->pNext;
    free(pTemp2);
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