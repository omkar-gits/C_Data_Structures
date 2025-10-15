#include<stdio.h>

#define MAX 5



void Enqueue(int* , int, int* ,int);
int Dequeue(int* , int* , int*);
int IsQueueFull(int , int);
int IsQueueEmpty(int);
void Display(int* , int , int);

int main(void){

    int Queue[MAX];
    int iFront = 0;
    int iRear = -1;   
    int iPoppedData;
    
    Enqueue(Queue , 10 , &iRear , iFront);
    Enqueue(Queue , 20 , &iRear , iFront);
   

    Display(Queue , iRear , iFront);
    
    iPoppedData = Dequeue(Queue , &iRear , &iFront);
    if(iPoppedData != -1){
        printf("\nPopped data is %d\n", iPoppedData);
    }
    Enqueue(Queue , 60 , &iRear , iFront);
    Display(Queue , iRear , iFront);
    return 0;
}

void Enqueue(int* iQueue , int iNo , int* iRear , int iFront){
    if(IsQueueFull(*iRear , iFront)){
        printf("Queue already Full..\n");
        return;
    }
    if(*iRear == MAX -1){
        *iRear = 0;
    }
    else{
        (*iRear)++;
    }
    iQueue[*iRear] = iNo;
}

int Dequeue(int* iQueue , int* iRear , int* iFront){
    int iDeletedData;
    if(IsQueueEmpty(*iRear)){
        printf("Queue in empty..!\n");
        return -1;
    }
    iDeletedData = iQueue[*iFront];
    if((*iRear) == (*iFront)){
        *iRear = -1;
        *iFront = 0;
    }
    else if(*iFront == MAX -1){
        *iFront = 0;
    }
    else{
        (*iFront)++;
    }
    return iDeletedData;
}

int IsQueueFull(int iRear , int iFront){
    if((iRear == MAX -1 && iFront == 0) // Straight scenario 
    || (iRear == iFront-1 && iFront != 0))//circled back scenario
    {
        return  1;
    }
    return 0;
}

int IsQueueEmpty(int iRear){
    if(iRear == -1){
        return  1;
    }
    return 0;
}

//Version 1
void Display(int* iQueue , int iRear , int iFront){
    int iCounter;
    if(iRear == -1){
        printf("Queue is empty..!\n");
        return;
    }
    if(iFront > iRear){ //Circular scenario
        for(iCounter = iFront ; iCounter <= MAX-1 ; iCounter++){
            printf("|%d|-" , iQueue[iCounter]);
        }
        for(iCounter = 0 ; iCounter <= iRear ; iCounter++){
            printf("|%d|-" , iQueue[iCounter]);
        }
    }
    else{
        for(iCounter = iFront ; iCounter <= iRear ; iCounter++){
            printf("|%d|-" , iQueue[iCounter]);
        }
    }
}
