#include"queue.h"
#include<stdio.h>



int g_iFront = 0; 
int g_iRear = -1;
int g_iQueue[MAX] = {0};



void Enqueue(int iData){
    if(IsQueueFull()){
        printf("Queue is already Full..\n!");
        return;
    }
    g_iQueue[++g_iRear] = iData;
}

int IsQueueFull(void){
    if(g_iRear == MAX-1){
        return 1;
    }
    return 0;
}

/**
 * 10 20 30 40 50
 *  
*/
int IsQueueEmpty(void){
    if(g_iRear == -1){
        return 1;
    }
    return 0;
}

int Dequeue(void){
    int iDequeuedData;
    if(g_iRear == g_iFront){
        iDequeuedData = g_iQueue[g_iRear];
        g_iFront = 0;
        g_iRear = -1;
        return iDequeuedData;
    }
    return g_iQueue[g_iFront++];
}

