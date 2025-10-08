#include<stdio.h>

#define MAX 5


void Enqueue(int* ,int* ,int);
int Dequeue(int* ,int*, int*);
int IsQueueFull(int *);
int IsQueueEmpty(int*);
void Display(int* ,int , int);


int main(void){

    int Queue[MAX];
    int iFront = 0;
    int iRear = -1;

    Enqueue(Queue , &iRear, 10);
    Enqueue(Queue ,&iRear, 20);
    Enqueue(Queue ,&iRear, 30);

    Display(Queue , iFront , iRear);

    int iData = Dequeue(Queue , &iFront , &iRear);
    if(iData != -1){
        printf("Dequeued data is %d \n", iData);
    }
    Display(Queue , iFront , iRear);
    return 0;
}

void Enqueue(int* Queue , int* iRear , int iNo){
    if(IsQueueFull(iRear)){
        printf("Queue is Full..\n");
        return;
    }
    Queue[++(*iRear)] = iNo;
    return;
}

int Dequeue(int* Queue ,int* iFront , int* iRear){
    int iDequeuedData;
    if(IsQueueEmpty(iRear)){
        printf("Queue already empty..\n");
        return -1;
    }
    if(*iFront == *iRear){
        iDequeuedData = Queue[*iFront];
        *iFront = 0;
        *iRear = -1;
        return iDequeuedData;
    }
    return Queue[(*iFront)++];
}

int IsQueueFull(int* iRear){
    if(*iRear == MAX-1){
        return 1;
    }
    return 0;
}

int IsQueueEmpty(int* iRear){
    if(*iRear == -1){
        return 1;
    }
    return 0;
}

void Display(int* Queue , int iFront , int iRear){
    int iCounter;
    if(iRear == -1){
        printf("Queue is already empty..\n");
        return;
    }
    for(iCounter = iFront ; iCounter <= iRear ; iCounter++){
        printf("|%d|",Queue[iCounter]);
    }
    printf("\n");
}