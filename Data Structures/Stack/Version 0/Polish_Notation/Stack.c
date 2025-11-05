#include<stdio.h>
#include"Stack.h"

#define STACK_MAX   50

/**
 * Creating Stack library of long int
*/
long int g_Stack[STACK_MAX];
int g_iTop = -1;

int IsEmpty(){
    if(g_iTop == -1){
        return 1;
    }
    return 0;
}

int IsFull(){
    if(g_iTop == STACK_MAX-1){
        return 1;
    }
    return 0;
}

void Push(long int chSymbol){
    if(IsFull()){
        printf("Stack  Overflow..\n");
        return;
    }
    g_Stack[++g_iTop] = chSymbol;
}

long int Pop(){
    if(IsEmpty()){
        printf("Stack already Empty..\n");
        return -1;
    }
    return g_Stack[g_iTop--];
}