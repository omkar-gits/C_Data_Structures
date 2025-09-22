#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , int);
void InsertLast(struct node** , int);
int DeleteFirst(struct node**);
int DeleteLast(struct node**);
void Display(struct node*);
int CountNodes(struct node*);
int SearchFirstOccurrence(struct node* , int);
int SearchLastOccurrence(struct node* , int);
int SearchAllOccurrences(struct node* , int);
void InsertAtPosition(struct node** , int , int);
int DeleteAtPosition(struct node** , int);
void ConcatLists(struct node** , struct node**);
void ConcatAtPosition(struct node** , struct node**,int);
void PhysicalReverse(struct node**);
void ReverseDisplay(struct node*);
void DeleteAll(struct node**);

int main(void){
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
    if(iData != -1)
        printf("Deleted data is %d", iData); // 10

    Display(pFirst); // 20 30 20 40 50 60

    iData = DeleteLast(&pFirst);
    if(iData != -1)
        printf("Deleted data is %d", iData); // 60

    Display(pFirst); // 20 30 20 40 50

    iData = DeleteAtPosition(&pFirst, 4);
    if(iData != -1)
        printf("Deleted data is %d", iData); // 40

    Display(pFirst); // 20 30 20 50

    iData = CountNodes(pFirst);
    printf("Total node count is %d", iData); // 4

    iData = SearchFirstOccurrence(pFirst, 20);
    if(iData != 0)
        printf("First occurrence of %d is at %d position" , 20, iData); // 1

    iData = SearchLastOccurrence(pFirst, 20);
    if(iData != 0)
        printf("Last occurrence of %d is at %d position" , 20, iData); // 3

    iData = SearchAllOccurrences(pFirst, 20);
    printf("%d found %d times", 20, iData); // 2

    // For any queries, swapnil.y.mane@gmail.com 7821909654

    Display(pFirst); // 20 30 20 50
    ReverseDisplay(pFirst); // 50 20 30 20
    Display(pFirst); // 20 30 20 50
    PhysicalReverse(&pFirst);
    Display(pFirst); // 50 20 30 20

    InsertLast(&pSecond, 100);
    InsertLast(&pSecond, 200);
    InsertLast(&pSecond, 300);

    Display(pFirst); // 50 20 30 20
    Display(pSecond); // 100 200 300
    ConcatLists(&pFirst, &pSecond);
    Display(pFirst); // 50 20 30 20 100 200 300
    Display(pSecond); // List is empty

    InsertLast(&pSecond, 400);
    InsertLast(&pSecond, 500);
    InsertLast(&pSecond, 600);

    Display(pFirst); // 50 20 30 20 100 200 300
    Display(pSecond); // 400 500 600
    ConcatAtPosition(&pFirst, &pSecond, 4);
    Display(pFirst); // 50 20 30 400 500 600 20 100 200 300
    Display(pSecond); // List is empty

    if(pFirst != NULL)
    {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    if(pSecond != NULL)
    {
        DeleteAll(&pSecond);
        pSecond = NULL;
    }

    Display(pFirst); // List is empty
    Display(pSecond); // List is empty

    return 0;
}

void InsertFirst(struct node** ppHead  , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory allocation Failed..!\n");
        return;
    }
    pNewNode->iData = iNo;
    // if(NULL == *ppHead){
    //     pNewNode->pNext = NULL;
    //     *pphead = pNewNode;
    // }
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
}

void InsertLast(struct node** ppHead  , int iNo){
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory allocation Failed..!\n");
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

int DeleteFirst(struct node** ppHead){
    int iDeletedData;
    struct node* pTemp = NULL;
    if(NULL == *ppHead){
        return -1;
    }
    pTemp = *ppHead;
    iDeletedData = pTemp->iData;
    *ppHead = pTemp->pNext;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;
    return iDeletedData;
}

int DeleteLast(struct node** ppHead){
    int iDeletedData;
    struct node* pTemp = NULL;
    if(NULL == *ppHead){
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
    return iDeletedData;

}

void Display(struct node*pHead){
    if(NULL == pHead){
        printf("The List is empty..!\n");
        return;
    }
    while(pHead != NULL){
        printf("|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

int CountNodes(struct node* pHead){
    int iCount = 0;
    while(NULL != pHead){
        iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
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
    int iLastPos = 0;

    while(pHead != NULL){
        iPos++;
        if(pHead->iData == iKey){
            iLastPos = iPos;
        }
        pHead = pHead->pNext;
    }
    return iLastPos;
}

int SearchAllOccurrences(struct node* pHead , int iKey){
    int iOccurenceCount = 0;
    
    while(pHead != NULL){
        if(pHead->iData == iKey){
            iOccurenceCount++;
        }
        pHead = pHead->pNext;
    }
    return iOccurenceCount;
}


void DeleteAll(struct node** ppHead){
    struct node* pTemp = NULL;
        if(NULL == *ppHead){
        return;
    }
    while(NULL == *ppHead){
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    pTemp = NULL;
    return;
}