//Bracket Validation 
/**
 * 1. Get a string with expression
 * 2. 
 * 
 * 
*/
#include<stdio.h>
#include"queue.h"

#define STRINGMAX   50

int main(void){
    char cInputexpression[100];
    printf("Enter a String -\t");
    fgets(cInputexpression , sizeof(cInputexpression),stdin);

    printf("The expression is %s" , cInputexpression);
    return 0;
}

int BracketValidation(char* StringToBeValidated){
    extern int g_iFront;
    extern int g_iRear;
    extern int g_iQueue[MAX];
    char chSymbol;

    int iCounter = 0;
    for(; StringToBeValidated[iCounter] != '\0' ; iCounter++){
        chSymbol = StringToBeValidated[iCounter];
        
    }
}

