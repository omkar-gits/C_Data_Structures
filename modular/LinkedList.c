#include<stdio.h>
#include<malloc.h>
#include "SinglyLinkedList.h"

#include<stdio.h>
#include<malloc.h>

void InsertFirst(struct node** ppHeader , int iNo){
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory Allocation Failed \n");
        return;
    }
    
    pNewNode->iData = iNo;

    if(NULL == *ppHeader){
        pNewNode->pNext = NULL;
        *ppHeader = pNewNode;
        return;
    }
    pNewNode->pNext = *ppHeader;
    *ppHeader = pNewNode;
}

void InsertLast(struct node **ppHeader , int iNo){
    struct node* pNewNode = NULL;
    struct node* pTemp = NULL; 
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode){
        printf("Memory Allocation Failed \n");
        return;
    }
    pNewNode->iData = iNo;
    pNewNode->pNext = NULL;
    if(NULL == *ppHeader){
        *ppHeader = pNewNode;
        return;
    }
    pTemp = *ppHeader;
    while(pTemp->pNext != NULL){
        pTemp = pTemp->pNext;
    }

    pTemp->pNext = pNewNode;
    return;
}

int DeleteFirst(struct node **ppHeader){
    int iDelData;
    struct node* pTemp = NULL;

    if(NULL == *ppHeader){
        return -1 ;
    }
    pTemp =  *ppHeader;
    *ppHeader = pTemp->pNext;
    iDelData = pTemp->iData;
    pTemp->pNext = NULL;
    free(pTemp);
    pTemp = NULL;
    return iDelData;
}

void DeleteAll(struct node **ppHeader){
    struct node *pTemp = NULL;
    pTemp = *ppHeader;
    while(pTemp->pNext != NULL){
        pTemp = pTemp->pNext;
    }
}
