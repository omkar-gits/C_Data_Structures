#include<stdio.h>
#include<malloc.h>
#include"queue.h"

void PreOrder(struct TreeNode*);
void InOrder(struct TreeNode*);
void PostOrder(struct TreeNode*);
void LevelOrder(struct QueueNode**, struct TreeNode*);
void DeleteAll(struct TreeNode**);
int CountNodesVersion1(struct TreeNode*);
int CountNodesVersion2(struct TreeNode*);
int CountLeafNodes(struct TreeNode*);
int CountNonLeafNodes(struct TreeNode*);
int SmallestElement(struct TreeNode*);
int LargestElement(struct TreeNode*);
int Height(struct TreeNode*);
struct TreeNode* SearchRecursiveBST(struct TreeNode* , int);
struct TreeNode* SearchNonRecursiveBST(struct TreeNode* , int);



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

int CountLeafNodes(struct TreeNode* pRoot){
    static int iCounter = 0;
    if(NULL == pRoot){
        return 0;
    }
    if(NULL == pRoot->pLeft && NULL == pRoot->pRight){
        iCounter++;
    }
    CountLeafNodes(pRoot->pLeft);
    CountLeafNodes(pRoot->pRight);
    return iCounter;
}

int CountNonLeafNodes(struct TreeNode* pRoot){
    static int iCounter = 0;
    if(NULL == pRoot){
        return 0;
    }
    if(NULL != pRoot->pLeft || NULL != pRoot->pRight){
        iCounter++;
    }
    CountNonLeafNodes(pRoot->pLeft);
    CountNonLeafNodes(pRoot->pRight);
    return iCounter;
}

int SmallestElement(struct TreeNode* pRoot){
    int iSmallest;
    if(NULL == pRoot){
        return -1;
    }
    if(NULL == pRoot->pLeft){
        iSmallest = pRoot->iData;
    }
    SmallestElement(pRoot->pLeft);
    return iSmallest;
}

int LargestElement(struct TreeNode* pRoot){
    int iLargest;                       
    if(NULL == pRoot){
        return -1;
    }
    if(NULL == pRoot->pRight){
        iLargest = pRoot->iData;
    }
    LargestElement(pRoot->pRight);
    return iLargest;
}

int Height(struct TreeNode* pRoot){
    int iLeftHeight;
    int iRightHeight;

    if(NULL == pRoot){
        return 0;
    }
    iLeftHeight = Height(pRoot->pLeft);
    iRightHeight = Height(pRoot->pRight);

    if(iLeftHeight > iRightHeight){
        return iLeftHeight+1;
    }
    else{
        return iRightHeight+1;
    }
}

//Recursive
struct TreeNode* SearchRecursiveBST(struct TreeNode* pRoot , int iKey){
    if(NULL == pRoot){
        return NULL;
    }
    if(iKey < pRoot->iData){
        return SearchRecursiveBST(pRoot->pLeft , iKey);
    }
    else if(iKey > pRoot->iData){
        return SearchRecursiveBST(pRoot->pRight, iKey);
    }
    else{
        return pRoot;
    }
}

//Non Recursive
struct TreeNode* SearchNonRecursiveBST(struct TreeNode* pRoot , int iKey){
    while(pRoot != NULL){
        if(iKey < pRoot->iData){
            pRoot = pRoot->pLeft;
        }
        else if(iKey > pRoot->iData){
            pRoot = pRoot->pRight;
        }
        else{
            return pRoot;
        }
    }
}

void InsertBST(struct TreeNode* ppRoot , int iNo){
 
}