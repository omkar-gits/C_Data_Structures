#include<stdio.h>

#define MAX 5

int g_Queue[MAX];
int g_iFront = 0;
int g_iRear = -1;

void Enqueue(int);
int Dequeue(void);
int IsQueueFull(void);
int IsQueueEmpty(void);
void Display(void);


int main(void){
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);

    Display();

    int iData = Dequeue();
    if(iData != -1){
        printf("Dequeued data is %d \n", iData);
    }

    Display();

    return 0;
}

/**TO  BE  TRIED BY TAKING STACK , FRONT AND REAR LOCAL
 * 
 * 
*/
void Enqueue(int iNo){
    if(IsQueueFull()){
        printf("Queue is Full..\n");
        return;
    }

    g_Queue[++g_iRear] = iNo;
    return;
}

int Dequeue(void){
    int iDequeuedData;
    if(IsQueueEmpty()){
        printf("Queue already empty..\n");
        return -1;
    }
    if(g_iFront == g_iRear){
        iDequeuedData = g_Queue[g_iFront];
        g_iFront = 0;
        g_iRear = -1;
        return iDequeuedData;
    }
    return g_Queue[g_iFront++];
}

int IsQueueFull(void){
    if(g_iRear == MAX-1){
        return 1;
    }
    return 0;
}

int IsQueueEmpty(void){
    if(g_iRear == -1){
        return 1;
    }
    return 0;
}

void Display(void){
    int iCounter;
    if(g_iRear == -1){
        printf("Queue is already empty..\n");
        return;
    }
    for(iCounter = g_iFront ; iCounter <= g_iRear ; iCounter++){
        printf("|%d|",g_Queue[iCounter]);
    }
    printf("\n");
}