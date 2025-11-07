#define QUEUE_MAX   25

struct TreeNode{
    struct TreeNode* pLeft;
    int iData;
    struct TreeNode* pRight;
};

struct QueueNode{
    struct TreeNode *pCurrentNode;
    struct QueueNode *pNext;
};

void Enqueue(struct QueueNode**, struct TreeNode*);
struct Treenode* Dequeue(struct QueueNode**);
int IsQueueEmpty(struct QueueNode*);
int IsQueueFull(struct QueueNode*);
int CountNodes(struct QueueNode*);
