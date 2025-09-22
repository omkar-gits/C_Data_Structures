#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , int);
void Display(struct node*);
int SearchFirstOccurence(struct node* , int);
int SearchLastOccurence(struct node* pHead , int);
void DeleteAll(struct node**);

int main(void){
    int iKey = 40;
    struct node* pFirst = NULL;
    InsertFirst(&pFirst , 50);
    InsertFirst(&pFirst , 40);
    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);
    Display(pFirst);
    int FirstOccurence = SearchFirstOccurence(pFirst , iKey);
    printf("The First occurence of %d is at node number %d",iKey,FirstOccurence);
    if(NULL != pFirst){
        DeleteAll(&pFirst);
    }
    return 0;
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

int SearchFirstOccurence(struct node* pHead , int iKey){
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
