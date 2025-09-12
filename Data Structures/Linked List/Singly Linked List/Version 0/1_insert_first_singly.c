#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , int);
void Display(struct node*);
void DeleteAll(struct node **);

int main(void){
    struct node* pFirst = NULL;
    InsertFirst(&pFirst , 50);
    InsertFirst(&pFirst , 40);
    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);
    Display(pFirst);
    //DeleteAll(&pFirst);
    //Display(pFirst);
}

void InsertFirst(struct node**ppHead , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
       printf("Memory Allocation Failed..!");
       return; 
    }
    pNewNode->iData = iNo;
    //Commented for Optimisation
    // if(NULL == *ppHead){
    //     pNewNode->pNext = NULL;
    //     *ppHead = pNewNode;
    // }
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


