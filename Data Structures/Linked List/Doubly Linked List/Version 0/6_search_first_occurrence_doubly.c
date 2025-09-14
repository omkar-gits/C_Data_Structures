#include<stdio.h>
#include<malloc.h>

struct node{
    struct node* pPrev;
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , int);
void Display(struct node*);
int SearchFirstOccurence(struct node* , int);

int main(void){
    int iToBeSearched = 20;
    struct node* pFirst = NULL;
    InsertFirst(&pFirst , 40);
    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);
    Display(pFirst);
    printf("The first occurence of %d is at position %d \n",iToBeSearched ,SearchFirstOccurence(pFirst , iToBeSearched));
    return 0;
}

void InsertFirst(struct node**ppHead , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
       printf("Memory Allocation Failed..!");
       return; 
    }
    pNewNode->iData = iNo;

    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
    return;
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

int SearchFirstOccurence(struct node*pHead , int iKey){
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