#include<stdio.h>
#include<malloc.h>

#define MAX 5

struct node{
    int iData;
    struct node* pNext;
};

void EnQueue(struct node** , int);         //using InsertFirst for Push operation as we ditch the traversal
int DeQueue(struct node**);                 //using DeleteFirst for DeQueue operation as we ditch the traversal
int CountNodes(struct node*);
int IsQueueFull(struct node*);
int IsQueueEmpty(struct node*);
void Display(struct node*);
void DeleteAll(struct node**);

int main(void){
    int iPoppedData;

    struct node* pQueue = NULL;
    EnQueue(&pQueue , 10);
    EnQueue(&pQueue , 20);
    EnQueue(&pQueue , 30);
    EnQueue(&pQueue , 40);

    Display(pQueue);

    iPoppedData = DeQueue(&pQueue);
    
    if(-1 != iPoppedData){
        printf("Popped data is %d\n", iPoppedData);
    }
    Display(pQueue);
    if(NULL != pQueue){
        DeleteAll(&pQueue);
    }
    Display(pQueue);
    return 0;
}

void EnQueue(struct node** ppHead , int iNo){
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL;
    if(IsQueueFull(*ppHead)){
        printf("queue is FUll..!\n");
        return;
    }
    else{
        pNewNode = (struct node*)malloc(sizeof(struct node));
        if(NULL == pNewNode){
            printf("Memory Allocation Failed..!\n");
            return;
        }
        pNewNode->iData = iNo;
        pNewNode->pNext = NULL;
        if(NULL == *ppHead){
            *ppHead = pNewNode;
            return;
        }
        pTemp = *ppHead;
        while(pTemp->pNext != NULL){
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNewNode;
    }
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
