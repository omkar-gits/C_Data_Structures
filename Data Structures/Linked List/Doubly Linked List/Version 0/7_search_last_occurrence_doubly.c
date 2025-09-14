#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , int);
void Display(struct node*);
int SearchLastOccurence(struct node*  , int);

int main(void){
    int iKey = 40;
    struct node* pFirst = NULL;
    InsertFirst(&pFirst , 40);
    InsertFirst(&pFirst , 40);
    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);
    Display(pFirst);
    int LastOccurence = SearchLastOccurence(pFirst , iKey);
    printf("The First occurence of %d is at node number %d",iKey,LastOccurence);
}

void InsertFirst(struct node**ppHead , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed\n");
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

int SearchLastOccurence(struct node* pHead , int iKey){
    int iPos = 0;
    int iLastOccurence = 0;

    while(pHead != NULL){
        iPos++;
        if(pHead->iData == iKey){
            iLastOccurence = iPos;
        }
        pHead = pHead->pNext;
    }
    return iLastOccurence;
}