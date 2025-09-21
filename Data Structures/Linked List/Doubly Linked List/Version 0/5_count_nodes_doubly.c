#include<stdio.h>
#include<malloc.h>

struct node{
    struct node* pPrev;
    int iData;
    struct node* pNext;
};

void InsertLast(struct node** , int);
void Display(struct node*);
int CountNodes(struct node*);
void DeleteAll(struct node**);

int main(void){
    struct node* pFirst = NULL;

    InsertLast(&pFirst , 10);
    InsertLast(&pFirst , 20);
    InsertLast(&pFirst , 30);
    InsertLast(&pFirst , 40);
    InsertLast(&pFirst , 50);
    InsertLast(&pFirst , 60);
    InsertLast(&pFirst , 70);
    InsertLast(&pFirst , 80);
    Display(pFirst);
    printf("Number of Nodes in the Linked List = %d\n", CountNodes(pFirst));
    
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
    int iCount = 0;
    while(pHead != NULL){
        iCount++;
        pHead = pHead->pNext;
    }
    return iCount;
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