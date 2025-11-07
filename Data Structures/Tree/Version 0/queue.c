#include<stdio.h>
#include<malloc.h>
#include"queue.h"



void Enqueue(struct QueueNode** ppHead , struct TreeNode* TreeNode){
    struct QueueNode* pNewNode = NULL;
    if(IsQueueFull(*ppHead)){
        printf("Queue is Full ..!\n");
        return;
    }
    pNewNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed..!\n");
        return;
    }
    if(TreeNode != NULL){
        return;
    }
    pNewNode->pCurrentNode = TreeNode;
    if(NULL == *ppHead){
        pNewNode->pNext = NULL;
        *ppHead = pNewNode;
        return;
    }
    pNewNode->pNext = *ppHead;
    *ppHead = pNewNode;
    return;
}

struct TreeNode* Dequeue(struct QueueNode** ppHead){
    struct TreeNode* DequeuedTreeNode = NULL;
    struct QueueNode* pTemp = NULL;
    if(NULL == *ppHead || IsQueueEmpty(*ppHead)){
        printf("Queue already Empty..!\n");
        return;
    }
    DequeuedTreeNode = (*ppHead)->pCurrentNode;
    if((*ppHead)->pNext == NULL){
        (*ppHead)->pCurrentNode = NULL;
        free(*ppHead);
        *ppHead = NULL;
    }
    pTemp = *ppHead;
    *ppHead = pTemp->pNext;
    free(pTemp);
    pTemp = NULL;
    return DequeuedTreeNode;
}

int IsQueueEmpty(struct QueueNode* pHead){
    if(CountNodes(pHead) == 0){
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
    if(pHead == NULL){
        printf("Queue is empty..!\n");
        return -1;
    }
    while(pHead != NULL){
        iCounter++;
        pHead = pHead->pNext;
    }
    return iCounter;
}

void DeleteAllQueue(struct QueueNode** ppHead){
    struct QueueNode* pTemp = NULL;
    if(*ppHead == NULL){
        printf("Queue already empty..!\n");
        return;
    }
    while((*ppHead)->pNext != NULL){
        pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        free(pTemp);
    }
    return;
}