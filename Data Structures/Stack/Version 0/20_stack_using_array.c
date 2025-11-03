#include<stdio.h>

#define MAX 5

void Push(int* , int* , int);
int Pop(int* , int*);
int IsFull(int);
int IsEmpty(int);

void Display(int* , int);

int main(void){
    int Stack[MAX];
    int iTop = -1;

    Push(Stack , &iTop , 10);
    Push(Stack , &iTop , 20);
    Push(Stack , &iTop , 30);
    Push(Stack , &iTop , 40);

    Display(Stack , iTop);
    
    int iDeletedData = Pop(Stack , &iTop);
    if(iDeletedData != -1){
        printf("Popped Data is %d\n", iDeletedData);
    }
    Display(Stack , iTop);

    return 0;
}

void Push(int* Stack , int* iTop , int iNo){
    if(IsFull(*iTop)){
        printf("Stack Overflow..\n");
        return;
    }
    Stack[++ *iTop] = iNo;
    return;
}

int Pop(int* Stack , int *iTop){
    if(IsEmpty(*iTop)){
        return -1;
    }
    return Stack[(*iTop)--];
}

int IsFull(int iTop){
        if(iTop == MAX-1){
        return 1;
    }
    return 0;
}

int IsEmpty(int iTop){
    if(iTop == -1){
        return 1;
    }
    return 0;
}

void Display(int* Stack , int iTop){
    int iCounter;
    if(-1 == iTop){
        printf("Stack already Empty..\n");
        return;
    }
    for(iCounter = 0 ; iCounter <= iTop ; iCounter++){
        printf("|%d| ", Stack[iCounter]);
    }
    printf("\n");
    return;
}