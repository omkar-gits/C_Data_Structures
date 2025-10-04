#include<stdio.h>

#define MAX 5

int g_Stack[MAX];
int g_iTop = -1;

void Push(int);
int Pop();
int IsEmpty(void);
int IsFull(void);

void Display(void);

int main(void){
    int iPoppedData;
    Push(10);
    Push(20);
    Push(30);

    Display();

    iPoppedData = Pop();
    if(iPoppedData != -1){
        printf("Popped Data is %d\n", iPoppedData);
    }
    Display();
    return 0;
}

/**
 * TO BE IMPLEMENTED BY TAKING ARRAY AND TOP AS LOCAL
 * 
*/

void Push(int iNo){
    if(IsFull()){
        printf("Stack Overflow..\n");
        return;
    }
    g_Stack[++g_iTop] = iNo;
    return;
}

int Pop(){
    if(IsEmpty()){
        return -1;
    }
    return g_Stack[g_iTop--];
}

int IsFull(void){
    if(g_iTop == MAX-1){
        return 1;
    }
    return 0;
}

int IsEmpty(void){
    if(g_iTop == -1){
        return 1;
    }
    return 0;
}

void Display(){
    int iCounter;
    if(-1 == g_iTop){
        printf("Stack already Empty..\n");
        return;
    }
    for(iCounter = 0 ; iCounter <= g_iTop ; iCounter++){
        printf("|%d| ", g_Stack[iCounter]);
    }
    printf("\n");
    return;
}