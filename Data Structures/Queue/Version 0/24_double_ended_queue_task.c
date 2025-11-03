#include <stdio.h>

#define MAX 5

void EnqueueAtFront(int* , int , int , int*);
int DequeueFromRear(int* , int* , int*);

void EnqueueFromRear(int* Queue , int iNo , int* iRear , int iFront);
int DequeueAtFront(int *Queue , int* iRear , int* iFront);

int IsQueueFull(int iRear , int iFront);
int IsQueueEmpty(int);

void Display(int* , int , int);

int main(void){

    int iQueue[MAX]= {0};

    int DeletedData;

    int iFront = 0;
    int iRear = -1;

    Display(iQueue , iRear , iFront);


    EnqueueAtFront(iQueue , 10 , iRear , &iFront);
    EnqueueAtFront(iQueue , 20 , iRear , &iFront);
    EnqueueAtFront(iQueue , 30 , iRear , &iFront);
    EnqueueFromRear(iQueue , 40 , &iRear , iFront);
    EnqueueFromRear(iQueue , 50 , &iRear , iFront);

    Display(iQueue , iRear , iFront);

    DeletedData = DequeueAtFront(iQueue , &iRear , &iFront);
    if(-1 != DeletedData){
        printf("\nDeleted data is %d \n", DeletedData);
    }

    DeletedData = DequeueFromRear(iQueue , &iRear , &iFront);
    if(-1 != DeletedData){
        printf("\nDeleted data is %d \n", DeletedData);
    }

   Display(iQueue , iRear , iFront);
    
}


void EnqueueAtFront(int* Queue , int iNo , int iRear , int* iFront){
    if(IsQueueFull(iRear , *iFront)){
        printf("Queue is Full..!\n");
        return;
    }
    if((*iFront) == 0){
        (*iFront) = MAX -1;
    }
    else{
        (*iFront)--;
    }
    Queue[(*iFront)] = iNo;
}

int DequeueFromRear(int *Queue , int* iRear , int* iFront){
    int iDeletedData;
    if(IsQueueEmpty(*iRear)){
        printf("Queue Already Empty..!\n");
        return -1;
    }
    iDeletedData = Queue[*iRear];
    Queue[*iRear] = 0;
    if((*iFront)  == (*iRear)){
        *iFront = 0;
        *iRear = -1;
    }
    else{
        --(*iRear);
    }
    return iDeletedData;
}

void EnqueueFromRear(int* Queue , int iNo , int* iRear , int iFront){
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
    Queue[*iRear] = iNo;
}

int DequeueAtFront(int* Queue , int* iRear , int* iFront){
    int iDeletedData;
    if(IsQueueEmpty(*iRear)){
        printf("Queue in empty..!\n");
        return -1;
    }
    iDeletedData = Queue[*iFront];
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
    if((iRear == MAX - 1 && iFront  == 0) || (iRear == iFront -1 && iFront != 0 )){
        return 1;
    }
    return 0;

}

int IsQueueEmpty(int iRear){
    if(iRear == - 1)
        return 1;
    return 0;
}

void Display(int* iQueue , int iRear , int iFront){
    int iCounter;
    if(iRear == -1){
        printf("Queue is empty..!\n");
        return;
    }
    printf("\n");
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
    printf("\n");
}