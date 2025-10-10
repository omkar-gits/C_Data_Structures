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

    int iPoppedData;
    
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);

    Display();

    iPoppedData = Pop();
    if(iPoppedData != -1){
        printf("Popped data is %d", iPoppedData);
    }
    Display();
}

void Enqueue(int iNo){
    if(IsQueueFull){
        printf("Queue already Full..\n");
        return;
    }
    if(g_iRear == MAX -1){
        g_iRear = 0;
    }
    g_Queue[g_iRear] = iNo;
}

int Dequeue(void){


}

int IsQueueFull(void){
    if((g_iRear == MAX -1 && g_iFront == 0) // Straight scenario 
    || g_iRear == g_iFront-1 && g_iFront != 0)//circled back scenario
    {
        return  1;
    }
    return 0;
}

int IsQueueEmpty(void){
    if(g_iRear == -1){
        return  1;
    }
    return 0;
}

void Display(void){

}