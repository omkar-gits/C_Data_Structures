#include<stdio.h>
#include<malloc.h>
#include"queue.h"



void Enqueue(struct QueueNode** ppHead , struct TreeNode* TreeNode){
    struct QueueNode* pNewNode = NULL;
    struct QueueNode* pTemp = NULL;

    if(IsQueueFull(*ppHead)){
        printf("Queue is Full ..!\n");
        return;
    }
    if(TreeNode == NULL){
        return;
    }
    pNewNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
        return;
    }
    pNewNode->pCurrentNode = TreeNode;
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
    return;
}

struct TreeNode* Dequeue(struct QueueNode** ppHead){
    struct TreeNode* DequeuedTreeNode = NULL;
    struct QueueNode* pTemp = NULL;

    if(IsQueueEmpty(*ppHead)){
        printf("Queue already Empty..!\n");
        return NULL;
    }
    else{
        DequeuedTreeNode = (*ppHead)->pCurrentNode;
        pTemp =*ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
        pTemp = NULL;
        return DequeuedTreeNode;
    }
}

int IsQueueEmpty(struct QueueNode* pHead){
    if(pHead == NULL){
        return 1;
    }
    return 0;
}

int IsQueueFull(struct QueueNode* pHead){
    if(CountNodes(pHead) == QUEUE_MAX){
        return 1;
    }
    return 0;
}

int CountNodes(struct QueueNode* pHead){
    int iCounter = 0;
    while(pHead != NULL){
        iCounter++;
        pHead = pHead->pNext;
    }
    return iCounter;
}

void DeleteAllQueue(struct QueueNode** ppHead){
    struct QueueNode* pTemp = NULL;
    if(*ppHead == NULL){
        //printf("Queue already empty..!\n");
        return;
    }
    while((*ppHead)->pNext != NULL){
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    return;
}