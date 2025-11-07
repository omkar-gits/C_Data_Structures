#include<stdio.h>
#include<malloc.h>
#include"queue.h"

void PreOrder(struct TreeNode*);
void InOrder(struct TreeNode*);
void PostOrder(struct TreeNode*);
void LevelOrder(struct QueueNode**, struct TreeNode*);
void DeleteAll(struct TreeNode**);

int main(void){

    return 0;
}

void PreOrder(struct TreeNode* pRoot){
    if(NULL == pRoot){
        return;
    }
    printf("%d", pRoot->iData);
    PreOrder(pRoot->pLeft);
    PreOrder(pRoot->pRight);
}

void InOrder(struct TreeNode* pRoot){
    if(NULL == pRoot){
        return;
    }
    PreOrder(pRoot->pLeft);
    printf("%d", pRoot->iData);
    PreOrder(pRoot->pRight);
}

void PostOrder(struct TreeNode* pRoot){
    if(NULL == pRoot){
        return;
    }
    PreOrder(pRoot->pLeft);
    PreOrder(pRoot->pRight);
    printf("%d", pRoot->iData);
}

void LevelOrder(struct QueueNode** ppHead , struct TreeNode* pRoot){
    struct TreeNode *pPtr= NULL;
    Enqueue(ppHead , pRoot);
    while(!IsQueueEmpty(*ppHead)){
        pPtr = Dequeue(ppHead);
        printf(pPtr->iData);
        Enqueue(ppHead , pPtr->pLeft);
        Enqueue(ppHead , pPtr->pRight);
    }
}

void DeleteAll(struct TreeNode** ppRoot){
    if(NULL == *ppRoot){
        return;
    }
    DeleteAll(&((*ppRoot)->pLeft));
    DeleteAll(&((*ppRoot)->pRight));
    free(*ppRoot);
}

//Version 1 count nodes
int CountNodesVersion1(struct TreeNode* pRoot){
    static int iCounter = 0;
    if(NULL == pRoot){
        return 0;
    }
    iCounter++;
    CountNodesVersion1(pRoot->pLeft);
    CountNodesVersion1(pRoot->pRight);
    return iCounter;
}

//Version 2 count nodes

int CountNodesVersion2(struct TreeNode* pRoot){
    if(NULL == pRoot){
        return 0;
    }
    return CountNodesVersion2(pRoot->pLeft)+CountNodesVersion2(pRoot->pRight)+1;
}