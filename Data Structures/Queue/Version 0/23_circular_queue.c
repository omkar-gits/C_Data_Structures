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
    Enqueue(40);
    Enqueue(50);
    Display();
    iPoppedData = Dequeue();
    // iPoppedData = Dequeue();
    // iPoppedData = Dequeue();
    if(iPoppedData != -1){
        printf("\nPopped data is %d\n", iPoppedData);
    }
    Enqueue(60);


    Display();
}

void Enqueue(int iNo){
    if(IsQueueFull()){
        printf("Queue already Full..\n");
        return;
    }
    if(g_iRear == MAX -1){
        g_iRear = 0;
    }
    else{
        g_iRear++;
    }
    g_Queue[g_iRear] = iNo;
}

int Dequeue(void){
    int iDeletedData;
    if(IsQueueEmpty()){
        printf("Queue in empty..!\n");
        return -1;
    }
    iDeletedData = g_Queue[g_iFront];
    if(g_iRear == g_iFront){
        g_iRear = -1;
        g_iFront = 0;
    }
    else if(g_iFront == MAX -1){
        g_iFront = 0;
    }
    else{
        g_iFront ++;
    }
    return iDeletedData;
}

int IsQueueFull(void){
    if((g_iRear == MAX -1 && g_iFront == 0) // Straight scenario 
    || (g_iRear == g_iFront-1 && g_iFront != 0))//circled back scenario
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

//Version 1
void Display(void){
    int iCounter;
    if(g_iRear == -1){
        printf("Queue is empty..!\n");
        return;
    }
    if(g_iFront > g_iRear){ //Circular scenario
        for(iCounter = g_iFront ; iCounter <= MAX-1 ; iCounter++){
            printf("|%d|-" , g_Queue[iCounter]);
        }
        for(iCounter = 0 ; iCounter <= g_iRear ; iCounter++){
            printf("|%d|-" , g_Queue[iCounter]);
        }
    }
    else{
        for(iCounter = g_iFront ; iCounter <= g_iRear ; iCounter++){
            printf("|%d|-" , g_Queue[iCounter]);
        }
    }
}
