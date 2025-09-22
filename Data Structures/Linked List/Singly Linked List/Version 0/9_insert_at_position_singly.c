#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , int);
void InsertLast(struct node** , int);
void InsertAtPosition(struct node** , int , int);
void Display(struct node*);
void DeleteAll(struct node**);
int CountNodes(struct node*);

int main(void){
    struct node* pFirst = NULL;
    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);
    InsertLast(&pFirst , 40);
    InsertLast(&pFirst , 50);
    InsertLast(&pFirst , 60);
    InsertAtPosition(&pFirst,100,1);
    InsertAtPosition(&pFirst,200,2);
    InsertAtPosition(&pFirst,300,3);
    InsertAtPosition(&pFirst,400,4);
    Display(pFirst);
    InsertAtPosition(&pFirst,500,4);
    Display(pFirst);
    if(NULL != pFirst){
        DeleteAll(&pFirst);
    }
    Display(pFirst);
    return 0;
}
void InsertFirst(struct node** ppHead , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
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
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;
    while(pTemp->pNext != NULL){
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pNewNode;
    
}

void Display(struct node* pHead){
    if(pHead == NULL){
        printf("The List is empty..!\n");
        return;
    }
    while(pHead != NULL){
        printf("|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
    return;
}

void InsertAtPosition(struct node** ppHead , int iNo , int iPos){
    struct node* pTemp = NULL;
    int iCounter = CountNodes(*ppHead);
    if(iPos <= 0 || iPos > iCounter+1){
        printf("Position is Invalid.\n");
        return;
    }
    if(1 == iPos){ // if position First
        InsertFirst(ppHead , iNo);
        return;
    }
    if(iPos == iCounter+1){//if Position last
        InsertLast(ppHead , iNo);
        return;
    }
    else{
        struct node* pNewNode = NULL;
            pNewNode = (struct node*)malloc(sizeof(struct  node));
        if(NULL == pNewNode){
            printf("Memory Allocation Failed..\n");
            return;
        }
        pNewNode->iData = iNo;
        iCounter = 1;
        pTemp = *ppHead;
        while(iCounter != iPos-1){
            iCounter++;
            pTemp = pTemp->pNext;
        }
        pNewNode->pNext = pTemp->pNext;
        pTemp->pNext = pNewNode;
    }
}

int CountNodes(struct node* pHead){
    int iCount = 0;
    while(NULL != pHead){
        iCount ++;
        pHead = pHead->pNext;
    }
    return iCount;
}

void DeleteAll(struct node**ppHead){
    struct node* pTemp = NULL;
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