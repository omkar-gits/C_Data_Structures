#include<stdio.h>
#include<malloc.h>

#define MAX 5 

struct node{
    int iData;
    int iPriority;
    struct node* pNext;
};


void InsertFirst(struct node** , int , int);
void Enqueue(struct node** , int , int);
int DeQueue(struct node**);                 //using DeleteFirst for DeQueue operation as we ditch the traversal
int CountNodes(struct node*);
int IsQueueFull(struct node*);
int IsQueueEmpty(struct node*);
void Display(struct node*);
void DeleteAll(struct node**);

int main(void){
    struct node* pPQueue = NULL;

    Enqueue(&pPQueue , 10 , 3);
    Enqueue(&pPQueue , 20 , 1);
    Enqueue(&pPQueue , 30 , 5);
    Enqueue(&pPQueue , 40 , 4);
    Enqueue(&pPQueue , 50 , 2);
    //Enqueue(&pPQueue , 60 , 6);

    Display(pPQueue);

    printf("Deleted Data is %d", DeQueue(&pPQueue));
    
    Display(pPQueue);

    if(pPQueue != NULL){
        DeleteAll(&pPQueue);
        pPQueue = NULL;
    }
    return 0;

}

void Enqueue(struct node** ppHead , int iNo , int iPri){
    struct node* pTemp = NULL;
    struct node* pNewNode = NULL;

    if(IsQueueFull(*ppHead)){
        printf("Queue Already Full !\n");
        return;
    }

    if(NULL == *ppHead || iPri > (*ppHead)->iPriority){
        InsertFirst(ppHead , iNo , iPri);
        return;
    }

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory Alllcation Failed..!\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->iPriority = iPri;
    pTemp = *ppHead;

    while(pTemp->pNext != NULL){
        if(iPri > pTemp->pNext->iPriority){
            break;
        }
        pTemp = pTemp->pNext;
    }
    pNewNode->pNext = pTemp->pNext;
    pTemp->pNext = pNewNode;
}

void InsertFirst(struct node**ppHead , int iNo , int iPri){
    struct node* pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
       printf("Memory Allocation Failed..!");
       return; 
    }
    pNewNode->iData = iNo;
    pNewNode->iPriority = iPri;
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
    return;
}

int DeQueue(struct node** ppHead){
    int iPoppedData;
    struct node* pTemp = NULL;
    if(IsQueueEmpty(*ppHead)){
        printf("queue already empty..1\n");
        return -1;
    }
    else{
        if(NULL == *ppHead){
            return -1;
        }
        iPoppedData = (*ppHead)->iData;
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
        pTemp = NULL;
        return iPoppedData;
    }
}

int IsQueueFull(struct node* pHead){
    if(CountNodes(pHead) == MAX){
        return 1;
    }
    return 0;
}

int IsQueueEmpty(struct node* pHead){
    if(NULL == pHead){
        return 1;
    }
    return 0;
}

void Display(struct node* pHead){
    if(NULL == pHead){
        printf("queue already Empty..!\n");
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
    int iQueueSize = 0;
    while(NULL != pHead){
        iQueueSize++;
        pHead = pHead->pNext;
    }
    return iQueueSize;
}

void DeleteAll(struct node** ppHead){
    struct node* pTemp = NULL;
    if(NULL == *ppHead){
        return;
    }
    while(NULL != *ppHead){
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    return;
}