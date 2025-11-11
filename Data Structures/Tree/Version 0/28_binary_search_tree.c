#include <stdio.h>
#include <malloc.h>
#include "queue.h"

void Preorder(struct TreeNode *);
void Inorder(struct TreeNode *);
void Postorder(struct TreeNode *);
void LevelOrder(struct QueueNode **, struct TreeNode *);
void DeleteAll(struct TreeNode **);
int CountNodesVersion1(struct TreeNode *);
int CountNodesVersion2(struct TreeNode *);
int CountLeafNodes(struct TreeNode *);
int CountNonLeafNodes(struct TreeNode *);
int SmallestElementBST(struct TreeNode *);
int LargestElementBST(struct TreeNode *);
int Height(struct TreeNode *);
struct TreeNode *SearchRecursiveBST(struct TreeNode *, int);
struct TreeNode *SearchNonRecursiveBST(struct TreeNode *, int);
void InsertBST(struct TreeNode **, int);
void DeleteBST(struct TreeNode **, int);

int main(void)
{
    struct TreeNode *pPtr = NULL;
    struct TreeNode *pRoot = NULL;

    struct QueueNode *pQueueHead = NULL;

    InsertBST(&pRoot, 100);
    InsertBST(&pRoot, 70);
    InsertBST(&pRoot, 143);
    InsertBST(&pRoot, 28);
    InsertBST(&pRoot, 77);
    InsertBST(&pRoot, 120);
    InsertBST(&pRoot, 150);
    InsertBST(&pRoot, 128);

    printf("Preorder is:\n");
    Preorder(pRoot); // 100 70 28 77 143 120 128 150
    printf("\n");
    printf("Inorder is:\n");
    Inorder(pRoot); // 28 70 77 100 120 128 143 150
    printf("\n");
    printf("Postorder is:\n");
    Postorder(pRoot); // 28 77 70 128 120 150 143 100
    printf("\n");
    printf("Level order is:\n");
    LevelOrder(&pQueueHead, pRoot); // 100 70 143 28 77 120 150 128
    printf("\n");

    printf("Total node count is %d\n", CountNodesVersion1(pRoot));  // 8
    printf("Total node count is %d\n", CountNodesVersion2(pRoot));  // 8
    printf("Leaf node count is %d\n", CountLeafNodes(pRoot));       // 4
    printf("NonLeaf node count is %d\n", CountNonLeafNodes(pRoot)); // 4
    printf("Height of tree is %d\n", Height(pRoot));                // 4
    printf("Smallest element is %d\n", SmallestElementBST(pRoot));  // 28
    printf("Largest element is %d\n", LargestElementBST(pRoot));    // 150

    pPtr = SearchRecursiveBST(pRoot, 120);
    if (NULL == pPtr)
        printf("%d not found\n", 120);
    else
        printf("%d found\n", 120);

    pPtr = SearchNonRecursiveBST(pRoot, 120);
    if (NULL == pPtr)
        printf("%d not found\n", 120);
    else
        printf("%d found\n", 120);

    DeleteBST(&pRoot, 28);
    LevelOrder(&pQueueHead, pRoot); // 100 70 143 77 120 150 128
    printf("\n");
    DeleteBST(&pRoot, 120);
    LevelOrder(&pQueueHead, pRoot); // 100 70 143 77 128 150
    printf("\n");
    DeleteBST(&pRoot, 143);
    LevelOrder(&pQueueHead, pRoot); // 100 70 150 77 128
    printf("\n");
    DeleteBST(&pRoot, 100);
    LevelOrder(&pQueueHead, pRoot); // 128 70 150 77
    printf("\n");

    printf("Total node count is %d\n", CountNodesVersion2(pRoot)); // 4

    if (pRoot != NULL)
    {
        DeleteAll(&pRoot);
        pRoot = NULL;
    }

    return 0;
}

void Preorder(struct TreeNode *pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    printf("%d ", pRoot->iData);
    Preorder(pRoot->pLeft);
    Preorder(pRoot->pRight);
}

void Inorder(struct TreeNode *pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    Inorder(pRoot->pLeft);
    printf("%d ", pRoot->iData);
    Inorder(pRoot->pRight);
}

void Postorder(struct TreeNode *pRoot)
{
    if (NULL == pRoot)
    {
        return;
    }
    Postorder(pRoot->pLeft);
    Postorder(pRoot->pRight);
    printf("%d ", pRoot->iData);
}

void LevelOrder(struct QueueNode **ppHead, struct TreeNode *pRoot)
{
    struct TreeNode *pPtr = NULL;
    Enqueue(ppHead, pRoot);
    while (!IsQueueEmpty(*ppHead))
    {
        pPtr = Dequeue(ppHead);
        printf("%d ", pPtr->iData);
        Enqueue(ppHead, pPtr->pLeft);
        Enqueue(ppHead, pPtr->pRight);
    }
    DeleteAllQueue(ppHead);
    *ppHead = NULL;
}

void DeleteAll(struct TreeNode **ppRoot)
{
    if (NULL == *ppRoot)
    {
        return;
    }
    DeleteAll(&((*ppRoot)->pLeft));
    DeleteAll(&((*ppRoot)->pRight));
    free(*ppRoot);
}

// Version 1 count nodes
int CountNodesVersion1(struct TreeNode *pRoot)
{
    static int iCounter = 0;
    if (NULL == pRoot)
    {
        return 0;
    }
    iCounter++;
    CountNodesVersion1(pRoot->pLeft);
    CountNodesVersion1(pRoot->pRight);
    return iCounter;
}

// Version 2 count nodes

int CountNodesVersion2(struct TreeNode *pRoot)
{
    if (NULL == pRoot)
    {
        return 0;
    }
    return CountNodesVersion2(pRoot->pLeft) + CountNodesVersion2(pRoot->pRight) + 1;
}

int CountLeafNodes(struct TreeNode *pRoot)
{
    static int iCounter = 0;
    if (NULL == pRoot)
    {
        return 0;
    }
    if (NULL == pRoot->pLeft && NULL == pRoot->pRight)
    {
        iCounter++;
    }
    CountLeafNodes(pRoot->pLeft);
    CountLeafNodes(pRoot->pRight);
    return iCounter;
}

int CountNonLeafNodes(struct TreeNode *pRoot)
{
    static int iCounter = 0;
    if (NULL == pRoot)
    {
        return 0;
    }
    if (NULL != pRoot->pLeft || NULL != pRoot->pRight)
    {
        iCounter++;
    }
    CountNonLeafNodes(pRoot->pLeft);
    CountNonLeafNodes(pRoot->pRight);
    return iCounter;
}

int SmallestElementBST(struct TreeNode *pRoot)
{
    if (NULL == pRoot)
    {
        return -1;
    }
    while(NULL != pRoot->pLeft)
    {
        pRoot = pRoot->pLeft;
    }
    return pRoot->iData;
}

int LargestElementBST(struct TreeNode *pRoot)
{
    if (NULL == pRoot)
    {
        return -1;
    }
    while(NULL != pRoot->pRight)
    {
        pRoot = pRoot->pRight;
    }
    return pRoot->iData;
}

int Height(struct TreeNode *pRoot)
{
    int iLeftHeight;
    int iRightHeight;

    if (NULL == pRoot)
    {
        return 0;
    }
    iLeftHeight = Height(pRoot->pLeft);
    iRightHeight = Height(pRoot->pRight);

    if (iLeftHeight > iRightHeight)
    {
        return iLeftHeight + 1;
    }
    else
    {
        return iRightHeight + 1;
    }
}

// Recursive
struct TreeNode *SearchRecursiveBST(struct TreeNode *pRoot, int iKey)
{
    if (NULL == pRoot)
    {
        return NULL;
    }
    if (iKey < pRoot->iData)
    {
        return SearchRecursiveBST(pRoot->pLeft, iKey);
    }
    else if (iKey > pRoot->iData)
    {
        return SearchRecursiveBST(pRoot->pRight, iKey);
    }
    else
    {
        return pRoot;
    }
}

// Non Recursive
struct TreeNode *SearchNonRecursiveBST(struct TreeNode *pRoot, int iKey)
{
    while (pRoot != NULL)
    {
        if (iKey < pRoot->iData)
        {
            pRoot = pRoot->pLeft;
        }
        else if (iKey > pRoot->iData)
        {
            pRoot = pRoot->pRight;
        }
        else
        {
            return pRoot;
        }
    }
}

void InsertBST(struct TreeNode **ppRoot, int iNo)
{
    struct TreeNode *pTemp = NULL;
    struct TreeNode *pParent = NULL;
    struct TreeNode *pNewNode = NULL;

    pTemp = *ppRoot;
    while (pTemp != NULL)
    {
        pParent = pTemp;
        if (iNo < pTemp->iData)
        {
            pTemp = pTemp->pLeft;
        }
        else if (iNo > pTemp->iData)
        {
            pTemp = pTemp->pRight;
        }
        else
        {
            printf("Duplicate Data..!\n");
            return;
        }
    }

    // if pParent remains unchanged(NULL) that means tree is empty

    pNewNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (NULL == pNewNode)
    {
        printf("Memory Allocation Failed..!\n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pLeft = NULL;
    pNewNode->pRight = NULL;

    if (NULL == *ppRoot)
    {
        *ppRoot = pNewNode;
    }
    else if (pParent->iData > iNo)
    {
        pParent->pLeft = pNewNode;
    }
    else
    {
        pParent->pRight = pNewNode;
    }
}

void DeleteBST(struct TreeNode **ppRoot, int iKey)
{
    struct TreeNode *pTemp = NULL;
    struct TreeNode *pParent = NULL;
    struct TreeNode *pChild = NULL;
    struct TreeNode *pSuccessor = NULL;

    pTemp = *ppRoot;

    while (pTemp != NULL)
    {
        if (iKey == pTemp->iData)
        {
            break;
        }
        pParent = pTemp;
        if (iKey < pTemp->iData)
        {
            pTemp = pTemp->pLeft;
        }
        else
        {
            pTemp = pTemp->pRight;
        }
        if (NULL == pTemp)
        {
            return;
        }
    }

    // If pParent remains unchanged that means data is found at root itself

    /***
     * if Data is not found at root then successor for the deleting node can be determined by
     * pTemp stores the deleting node
     * if both the childs are present(pLeft is not NULL and pRight is not NULL)
     * then go the right child of deleting node and
     * then go to leftmost child or grandchild of the right child is present
     */
    if (pTemp->pLeft != NULL && pTemp->pRight != NULL)
    {
        pParent = pTemp;
        pSuccessor = pTemp->pRight;
        while (pSuccessor->pLeft != NULL)
        {
            pParent = pSuccessor;
            pSuccessor = pSuccessor->pLeft;
        }
        pTemp->iData = pSuccessor->iData;
        pTemp = pSuccessor;
    }

    /**
     * The Deleting Nodes data was replaced by pSuccessor
     * Now pParent holds the pSuccessor (and pTemp as well)as its left child
     */
    // If only one child present..
    if (pTemp->pLeft != NULL)
    {
        pChild = pTemp->pLeft;
    }
    else
    {
        pChild = pTemp->pRight;
    }

    if (NULL == pParent)
    {
        *ppRoot = pChild;
    }
    else if (pTemp == pParent->pLeft)
    {
        pParent->pLeft = pChild;
    }
    else
    {
        pParent->pRight = pChild;
    }
    free(pTemp);
}