#include<stdio.h>
#include<malloc.h>

struct node{
    struct node* pPrev;
    int iData;
    struct node* pNext;
};

void InsertLast(struct node** , int);
void Display(struct node*);
void ConcatLists(struct node** , struct node** );
void DeleteAll(struct node**);

int main(void){
    struct node* pFirst = NULL;
    struct node* pSecond = NULL;

    InsertLast(&pFirst , 100);
    InsertLast(&pFirst , 200);
    InsertLast(&pFirst , 300);
    InsertLast(&pFirst , 400);
    InsertLast(&pFirst , 500);

    InsertLast(&pSecond , 1111);
    InsertLast(&pSecond , 2222);
    InsertLast(&pSecond , 3333);
    InsertLast(&pSecond , 4444);
    InsertLast(&pSecond , 5555);

    Display(pFirst);
    Display(pSecond);
    ConcatLists(&pFirst , &pSecond);
    Display(pFirst);
    Display(pSecond);

    if(NULL != pFirst){
        DeleteAll(&pFirst);
    }
    Display(pFirst);
    return 0;
}

void InsertLast(struct node** ppHead , int iNo){
    struct node* pNewNode =  NULL;
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

void Display(struct node* pHead){
    if(NULL == pHead){
        printf("The List is already empty..!\n");
        return;
    }
    printf("\nNULL");
    while(pHead != NULL){
        printf("<-|%d|->", pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
    return;
}

void DeleteAll(struct node ** ppHead){
    struct node* pTemp = NULL;
    while(*ppHead != NULL){
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    return;
}
/**CONCAT SCENARIOS
 * 1st list empty  - make 2nd first and return 
 * 2nd list empty - return as it is
 * both empty - return as it is
 * both present - concat 2nd at first's end
*/

void ConcatLists(struct node** ppHead1 , struct node** ppHead2 ){
    //Dont know if both are present or not
    struct node* pTemp = NULL;
    if(NULL == *ppHead2){
        return;
    }
    //now surely 2nd is present
    if(NULL == *ppHead1){
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }
    //now surely both are present
    pTemp = *ppHead1;
    while(pTemp->pNext != NULL){
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp;
    *ppHead2 = NULL;
    pTemp = NULL;
    return;
}