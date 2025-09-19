#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , int);
void Display(struct node*);
void ConcatLists(struct node** , struct node**);
void ConcatAtPosition(struct node**,struct node**, int);
int CountNodes(struct node*);
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

    ConcatAtPosition(&pFirst , &pSecond , 4);
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

int CountNodes(struct node* pHead){
    int iCount = 0;
    while(pHead != NULL){
        iCount ++;
        pHead = pHead->pNext;
    }
    return iCount;
}


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
/**
 * List Scenarios
 * list 1   list2   result
 *  0       0       0 direct return -DOne
 *  1       0       0 direct return -Done
 *  0       1       second becomes first , second is nulled -D0ne
 *  1       1       Concat second at First's end 
 * 
 * Position Scenarios
 * Position <=0 -- Invalid pos Done
 * Position > size+1 -- Invalid pos Done
 * position in between two nodes
 * 
 *
 * iPos=4
 * ic  = 3
 *       pt   
 * 10->20->30->40->50->NULL  
 * 100->200->300->400->500->NULL   
*/

void ConcatAtPosition(struct node** ppHead1 , struct node** ppHead2 , int iPos){
    int iListSize = CountNodes(*ppHead1);
    int iCount = 0;
    struct node* pTemp1 = NULL;
    struct node* pTemp2 = NULL;
    if(iPos <= 0 || iPos > iListSize + 1 ){
        return;
    }
    if(NULL == *ppHead2 ){
        return;
    }
    if(1 == iPos){
        ConcatLists(ppHead1 , ppHead2);
        return;
    }
    else{
        pTemp1 = *ppHead1;
        iCount = 1;
        while(iCount < iPos-1){
            iCount++;
            pTemp1 = pTemp1->pNext;
        }

        pTemp2 = *ppHead2;
        while(pTemp2->pNext != NULL){
            pTemp2 = pTemp2->pNext;
        }
 
        pTemp2->pNext = pTemp1->pNext;
        pTemp1->pNext = *ppHead2;
        *ppHead2 = NULL;
        return;



    }
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

