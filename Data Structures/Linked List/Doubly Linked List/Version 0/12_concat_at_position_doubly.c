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
int CountNodes(struct node*);
void ConcatAtPosition(struct node** , struct node** , int);
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
    ConcatAtPosition(&pFirst , &pSecond , 2);
    Display(pFirst);
    Display(pSecond);

    if(NULL != pFirst){
        DeleteAll(&pFirst);
    }
     if(NULL != pSecond){
        DeleteAll(&pSecond);
    }
    
    Display(pFirst);
    Display(pSecond);
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

int CountNodes(struct node* pHead){
    int iListSize = 0;
    while(NULL != pHead){
        iListSize ++;
        pHead = pHead->pNext;
    }
    return iListSize;
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
    return;
}

/**CONCAT AT POSITION SCENARIOS
 * POSITION SCENARIOS
 * pos can be < 0
 * pos can be = 0
 * pos can be =  list size 
 * pos can be = list size + 1 i.e at the end
 * pos can greate that list size +1
 * 
 * CONCAT SCENARIOS
 * 1st list not present - make 2nd as first and return
 * 2nd list not present - return as it is
 * none present - return as it is 
 * both present - concat at position given
 * 
*/
void ConcatAtPosition(struct node** ppHead1 , struct node** ppHead2 , int iPos){
    int iListSize = CountNodes(*ppHead1);
    struct node* pTemp1 = NULL;
    struct node* pTemp2 = NULL;    
    if(iPos <= 0 || iPos > iListSize+1){
        printf("Position invalid..!\n");
        return;
    }

    //Position is surely valid
    //but dont know whether 1st and 2nd list are present or not
    if(NULL == *ppHead2){
        return;
    }
    if(1 == iPos){
        ConcatLists(ppHead2 , ppHead1);
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }
    // if(iPos == iListSize +1){
    //     ConcatLists(ppHead1 , ppHead2);
    //     return;
    // }
    iListSize = 1;
    pTemp1 = *ppHead1;
    while(iListSize < iPos -1){
        iListSize++;
        pTemp1 = pTemp1->pNext;
    }//pTemp1p points to one node before the given position

    //now we need to take the last of list2

    pTemp2 = *ppHead2;
    while(pTemp2->pNext != NULL){
        pTemp2 = pTemp2->pNext;
    }//pTemp2 point to the last node
    //now concat at the position
    pTemp2->pNext = pTemp1->pNext;
    if(pTemp1->pNext != NULL){
        pTemp1->pNext->pPrev = pTemp2;
    }
    pTemp1->pNext = *ppHead2;
    (*ppHead2)->pPrev = pTemp1;
    *ppHead2 = NULL;
    return;
}