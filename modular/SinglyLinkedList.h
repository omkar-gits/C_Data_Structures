

#ifndef LINKEDLIST_H_  /* Include guard */
#define LINKEDLIST_H_

struct node{
    int iData;
    struct node* pNext;
};




void InsertFirst(struct node** , int);
void InsertLast(struct node **, int);
int DeleteFirst(struct node **);
void DeleteAll(struct node **);

#endif // LINKEDLIST_H_