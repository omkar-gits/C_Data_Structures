#include<stdio.h>
#include<malloc.h>

#define MAX 5

struct node{
    int iData;
    struct node* pNext;
};

void Push(struct node** , int);         //using InsertFirst for Push operation as we ditch the traversal
int Pop(struct node**);                 //using DeleteFirst for Pop operation as we ditch the traversal
int CountNodes(struct node*);
int IsFull(struct node*);
int IsEmpty(struct node*);
void Display(struct node*);
void DeleteAll(struct node**);

int main(void){
    int iPoppedData;

    struct node* pStack = NULL;
    Push(&pStack , 10);
    Push(&pStack , 20);
    Push(&pStack , 30);

    Display(pStack);

    iPoppedData = Pop(&pStack);
    if(-1 != iPoppedData){
        printf("Popped data is %d\n", iPoppedData);
    }
    Display(pStack);
    if(NULL != pStack){
        DeleteAll(&pStack);
    }
    Display(pStack);
    return 0;
}

void Push(struct node** ppHead , int iNo){
    struct node* pNewNode = NULL;
    if(IsFull(*ppHead)){
        printf("stack overflow..!\n");
        return;
    }
    else{
        pNewNode = (struct node*)malloc(sizeof(struct node));
        if(NULL == pNewNode){
            printf("Memory Allocation Failed..!\n");
            return;
        }
        pNewNode->iData = iNo;
        pNewNode->pNext = *ppHead;
        *ppHead = pNewNode;
        return;
    }
}


int Pop(struct node** ppHead){
    int iPoppedData;
    struct node* pTemp = NULL;
    if(IsEmpty(*ppHead)){
        printf("Stack already empty..1\n");
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


int IsFull(struct node* pHead){
    if(CountNodes(pHead) == MAX){
        return 1;
    }
    return 0;
}

int IsEmpty(struct node* pHead){
    if(NULL == pHead){
        return 1;
    }
    return 0;
}

void Display(struct node* pHead){
    if(NULL == pHead){
        printf("Stack already Empty..!\n");
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
    int iStackSize = 0;
    while(NULL != pHead){
        iStackSize++;
        pHead = pHead->pNext;
    }
    return iStackSize;
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
}
