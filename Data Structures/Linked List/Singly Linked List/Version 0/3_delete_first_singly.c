#include<stdio.h>
#include<malloc.h>

struct node{
    int iData;
    struct node* pNext;
};

void InsertFirst(struct node** , int);
void Display(struct node*);
int DeleteFirst(struct node**);
void DeleteAll(struct node**);

int main(void){
    struct node *pFirst = NULL;

    InsertFirst(&pFirst , 40);
    InsertFirst(&pFirst , 30);
    InsertFirst(&pFirst , 20);
    InsertFirst(&pFirst , 10);
    Display(pFirst);
    int iDeletedData = DeleteFirst(&pFirst);
    printf("Deleted Data is = %d\n",iDeletedData);
    Display(pFirst);
    if(NULL != pFirst){
        DeleteAll(&pFirst);
    }
    return 0;
}

void InsertFirst(struct node **ppHead , int iNo){
    struct node* pNewNode = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed \n");
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
    return;
}

void Display(struct node* pHead){
    if(pHead == NULL){
        printf("The List is empty..!\n");
        return;
    }

    while(pHead->pNext != NULL){
        printf("|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }
    printf("NULL\n");
}

int DeleteFirst(struct node **ppHead){
    struct node*pTemp = NULL;
    int DeletedData;
    if(NULL == *ppHead){
        printf("List is already Empty..!\n");
        return -1;
    }
    pTemp = *ppHead;
    DeletedData = pTemp->iData;
    *ppHead = pTemp->pNext;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;
    return DeletedData;
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