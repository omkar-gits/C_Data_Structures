#include<stdio.h>
#include<malloc.h>

struct node{
    struct node* pPrev;
    int iData;
    struct node* pNext;
};

void InsertLast(struct node** , int);
void Display(struct node*);
void ConcatLists(struct node** , struct node** );
void DeleteAll(struct node**);

int main(void){
    return 0;
}