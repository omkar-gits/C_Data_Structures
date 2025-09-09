#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertLast(struct node** , int);
void Display(struct node*);
int SearchAllOccurences(struct node* , int);

int main(void){
    struct node* pFirst = NULL;
    int iToBeSearched = 10;
    InsertLast(&pFirst , 10);
    InsertLast(&pFirst , 20);
    InsertLast(&pFirst , 10);
    InsertLast(&pFirst , 30);
    InsertLast(&pFirst , 10);
    InsertLast(&pFirst , 40);
    InsertLast(&pFirst , 10);
    InsertLast(&pFirst , 50);
    InsertLast(&pFirst , 10);
    InsertLast(&pFirst , 60);
    Display(pFirst);
    int iAllOccurences = SearchAllOccurences(pFirst , iToBeSearched);
    printf("All Occurences of %d in the list are %d",iToBeSearched , iAllOccurences);
}

void InsertLast(struct node** ppHead , int iNo){
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
    if(*ppHead == NULL){
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

void Display(struct node* pHead){
    if(NULL == pHead){
        printf("The List is already empty..!\n");
        return;
    }
    while(pHead != NULL){
        printf("|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
    return;
}

int SearchAllOccurences(struct node* pHead , int iKey){
    int iCount = 0;
    while(pHead != NULL){
        if(pHead->iData == iKey){
            iCount++;
        }
        pHead = pHead->pNext;
    }
    return iCount;
}