#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , int);
void Display(struct node*);
void ConcatLists(struct node** , struct node**);
void DeleteAll(struct node**);

int main(void){
    struct node* pFirst = NULL;
    struct node* pSecond = NULL;
    InsertFirst(&pFirst , 50);
    InsertFirst(&pFirst , 40);
    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);

    InsertFirst(&pSecond , 500);
    InsertFirst(&pSecond , 400);
    InsertFirst(&pSecond , 300);
    InsertFirst(&pSecond , 200);
    InsertFirst(&pSecond , 100);

    Display(pFirst);
    Display(pSecond);

    ConcatLists(&pFirst , &pSecond);
    Display(pFirst);
    DeleteAll(&pFirst);
    Display(pFirst);
    Display(pSecond);

}

void InsertFirst(struct node** ppHead , int iNo){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed..\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
    return;
}

void Display(struct node* pHead){
    if(NULL == pHead){
        printf("The list is already empty..!\n");
        return;
    }

    while(pHead != NULL){
        printf("|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
    return;
}

/**
 * list 1   list2   result
 *  0       0       0 direct return
 *  1       0       0 direct return
 *  0       1       second becomes first , second is nulled
 *  1       1       Concat second at First's end    
*/

void ConcatLists(struct node** ppHead1 , struct node** ppHead2){
    struct node* pTemp = NULL;
    if(NULL == *ppHead2){
        return;
    }
    if(NULL == *ppHead1){
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    pTemp = *ppHead1;
    while(pTemp->pNext != NULL){
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = *ppHead2;
    *ppHead2 = NULL;

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