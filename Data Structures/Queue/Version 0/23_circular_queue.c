// #include<stdio.h>

// #define MAX 5

// int g_Queue[MAX];
// int g_iFront = 0;
// int g_iRear = -1;

// void Enqueue(int);
// int Dequeue(void);
// int IsQueueFull(void);
// int IsQueueEmpty(void);
// void Display(void);

// int main(void){

//     int iPoppedData;
    
//     Enqueue(10);
//     Enqueue(20);
//     Enqueue(30);
//     Enqueue(40);
//     Enqueue(50);
//     Display();
//     iPoppedData = Dequeue();
//     // iPoppedData = Dequeue();
//     // iPoppedData = Dequeue();
//     if(iPoppedData != -1){
//         printf("\nPopped data is %d\n", iPoppedData);
//     }
//     Enqueue(60);


//     Display();
// }

// void Enqueue(int iNo){
//     if(IsQueueFull()){
//         printf("Queue already Full..\n");
//         return;
//     }
//     if(g_iRear == MAX -1){
//         g_iRear = 0;
//     }
//     else{
//         g_iRear++;
//     }
//     g_Queue[g_iRear] = iNo;
// }

// int Dequeue(void){
//     int iDeletedData;
//     if(IsQueueEmpty()){
//         printf("Queue in empty..!\n");
//         return -1;
//     }
//     iDeletedData = g_Queue[g_iFront];
//     if(g_iRear == g_iFront){
//         g_iRear = -1;
//         g_iFront = 0;
//     }
//     else if(g_iFront == MAX -1){
//         g_iFront = 0;
//     }
//     else{
//         g_iFront ++;
//     }
//     return iDeletedData;
// }

// int IsQueueFull(void){
//     if((g_iRear == MAX -1 && g_iFront == 0) // Straight scenario 
//     || (g_iRear == g_iFront-1 && g_iFront != 0))//circled back scenario
//     {
//         return  1;
//     }
//     return 0;
// }

// int IsQueueEmpty(void){
//     if(g_iRear == -1){
//         return  1;
//     }
//     return 0;
// }

// //Version 1
// void Display(void){
//     int iCounter;
//     if(g_iRear == -1){
//         printf("Queue is empty..!\n");
//         return;
//     }
//     if(g_iFront > g_iRear){ //Circular scenario
//         for(iCounter = g_iFront ; iCounter <= MAX-1 ; iCounter++){
//             printf("|%d|-" , g_Queue[iCounter]);
//         }
//         for(iCounter = 0 ; iCounter <= g_iRear ; iCounter++){
//             printf("|%d|-" , g_Queue[iCounter]);
//         }
//     }
//     else{
//         for(iCounter = g_iFront ; iCounter <= g_iRear ; iCounter++){
//             printf("|%d|-" , g_Queue[iCounter]);
//         }
//     }
// }

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
    Enqueue(Queue , 30 , &iRear , iFront);
    Enqueue(Queue , 40 , &iRear , iFront);
   

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

// void Display(int* iQueue , int iRear , int iFront){
//     int iCounter;
//     if(iRear == -1){
//         printf("Queue is empty..!\n");
//         return;
//     }
//     if(iFront > iRear){ //Circular scenario
//         for(iCounter = iFront ; iCounter <= MAX-1 ; iCounter++){
//             printf("|%d|-" , iQueue[iCounter]);
//         }
//         for(iCounter = 0 ; iCounter <= iRear ; iCounter++){
//             printf("|%d|-" , iQueue[iCounter]);
//         }
//     }
//     else{
//         for(iCounter = iFront ; iCounter <= iRear ; iCounter++){
//             printf("|%d|-" , iQueue[iCounter]);
//         }
//     }
// }

//Version 2

// void Display(int* iQueue , int iRear , int iFront){
//     int iCounter = iFront;
//     if(iRear == -1){
//         printf("Queue is empty..!\n");
//         return;
//     }
//     if(iFront > iRear){
//         for(; iCounter < MAX -1 ; iCounter++){
//             printf("|%d|-" , iQueue[iCounter]);
//             iCounter = 0;
//         }
//     }

//     for(; iCounter <= iRear ; iCounter++){
//          printf("|%d|-" , iQueue[iCounter]);
//     }
// }

//Version 3

void Display(int* iQueue , int iRear , int iFront){
    int iCounter = iFront;
    if(iRear == -1){
        printf("Queue is empty..!\n");
        return;
    }
    while(1){
        printf("|%d|-" , iQueue[iCounter]);
        if(iCounter == iRear){
            break;
        }
        if(iCounter == MAX-1){
            iCounter = -1;
        }
        iCounter++;
    }   
}
