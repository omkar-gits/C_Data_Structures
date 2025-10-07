#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define MAX_LENGTH   100
/**
 * Polish notation Programming
 * Functions required
 * 1) IsOperator ->check whether incoming char is operator or an operand
 *              Now considering operator preceence
 *              Function returs a priority number of all operators it encouters
 *              return 1 if '+'  / '-';
 *              returns 2 if '*' / '/';
 *              returns 3 if '**' ;
 * 
 * 2) infix to postfix converter function -> uses a Stack to store Polish notation 
 * 3) Result calculation functions->
 * 4)IsExpressionValid -> checks for any Alphabet Character and
 *                       whether if 2 operators are contiguous in input Expression or not
 * 5)Push-> operation to check IsExpressionValid Condition
 *          if IsExpression returns 0 then push that character onto Stack..!
*/

void Push(char* , int* , char);
char Pop(char* , int*);
int IsFull(int);
int IsEmpty(int);
int IsExpressionValid (char*);
int IsOperator(char);
int IsSpace(char);
char* InfixToPostfix(char*, char* , char* ,int*);
void PushInteger(int*, int* , int);
int PopInteger(int*, int*);
int PostFixToResult(char* , int* , int*);

int main(void){
    char cInputExpression[MAX_LENGTH];
    char PostFixStack[MAX_LENGTH] = {0};
    char ConvertedToPrefixExpression[MAX_LENGTH];
    int ResultStack[MAX_LENGTH] = {0};

    int iTop = -1;
    int iIntTop = -1;

    scanf("%s", cInputExpression);
    if(IsExpressionValid(cInputExpression) == -1){
        printf("Enter Valid Expression..!\n");
    }
    else{
        printf("Input Expression was %s \n", cInputExpression);
        printf("Converted Expression was %s \n", InfixToPostfix(cInputExpression ,ConvertedToPrefixExpression, PostFixStack , &iTop));
        printf("Result is %d \n", PostFixToResult(ConvertedToPrefixExpression , ResultStack , &iIntTop));
    }


    return 0;
}

int IsExpressionValid (char* ExpressionToBeChecked){
    char operator[2];
    //size_t ExpressionSize = strlen(ExpressionToBeChecked);
    int iCounter = 0;
    int iInternal = 0;

    if(IsOperator(ExpressionToBeChecked[iCounter]) > 0){
        return -1;
    }

    while(ExpressionToBeChecked[iCounter] != '\0'){
        if( IsOperator(ExpressionToBeChecked[iCounter]) > 0 && IsOperator(ExpressionToBeChecked[iCounter + 1])> 0){
            return -1;
        }
        iCounter++;
    }
    return 0;
}

/**
 * mala kay karaychay
 * 
 * mala string madhun iterate karaychay
 * 
*/

int IsOperator(char iSingle){
    if(iSingle == '+' || iSingle == '-'){
        return 1;
    }
    else if(iSingle == '*' || iSingle == '/'){
        return 2;
    }
    else if(iSingle == '^'){
        return 3;
    }
    else{
        return -1;
    }
}

int IsSpace(char iSingle){
    if(iSingle == ' '){
        return 1;
    }
    return 0;
}

int IsFull(int iTop){
        if(iTop == MAX_LENGTH-1){
        return 1;
    }
    return 0;
}

int IsEmpty(int iTop){
    if(iTop == -1){
        return 1;
    }
    return 0;
}

/**Push madhe kay karaychay 
 * 
 * Jo iSingle aahe to aplya cInputExpression cha ek character asnar aahe
 * 
 * tr aplyala inFix to Prefix karaychay
 * 
 * sadhya apan push madhe fakta Pushing chach logic thevu
 * 
 * karan apan push invoke karu jevha aplya infix to prefix che conditions miltil tevha
 * 
 * Operator pushing on stack
 * if  IsOperator(on Stack) < IsOperator(incoming) -> Push on Stack 
 * 
*/

void Push(char* Stack , int* iTop , char iSingle ){
        if(IsFull(*iTop)){
        printf("Stack Overflow..\n");
        return;
    }
    Stack[++ *iTop] = iSingle;
    return;
}

char Pop(char* Stack , int *iTop){
    if(IsEmpty(*iTop)){
        return -1;
    }
    return Stack[(*iTop)--];
}

void PushInteger(int* Stack , int* iTop , int iSingle ){

    if(IsFull(*iTop)){
        printf("Stack Overflow..\n");
        return;
    }
    Stack[++ (*iTop)] = iSingle;
    return;
}

int PopInteger(int* Stack , int *iTop){
    if(IsEmpty(*iTop)){
        return -1;
    }
    return Stack[(*iTop)--];
}

/**
 * Ata infix to postfix madhe
 * aplya purna expression through iterate karavi lagel
 * 
 * Jr ek element number asla tr tyala eka string madhe append kar
 * Jr ek element operator ala tr
 *      NC -> jr stack full nasel tr -> ha check already stack kartoy so no need to do it..!
 *          NC-> jr stack varch itop chi Priority < Operator of incoming string
 *                              DO - pop until stack varchi iTop chi Priority is < Operator of incoming string 
 *                                   AND append it to result String in the sequence of POP
 *         else -> Push Operator on Stack
 * 
 * 
 *  He sagla jhalahyavar Stack varceh sagle operator pop karayche ani tasech String vr push karayche
 * 
 * 
 * 
*/

char* InfixToPostfix(char* InputExpression ,char* OutputExpression , char* OperatorStack, int* iTop){
    OutputExpression[0] = '\0';
    int iCounter = 0;
    char cPoppedOperator;
    //int iOutPutLen;
    
    for( ; iCounter < strlen(InputExpression) ; iCounter++){
        if(IsOperator(InputExpression[iCounter]) < 0){
            int iOutPutLen = strlen(OutputExpression);
            OutputExpression[iOutPutLen] = InputExpression[iCounter];
            OutputExpression[iOutPutLen + 1] = '\0';
            printf("Output of if: %s\n", OutputExpression);
            // OutputExpression[iCounter] = InputExpression[iCounter];
            // printf("Output of if %s \n", OutputExpression);
        }
        else{
            while(!IsEmpty(*iTop) && IsOperator(OperatorStack[*iTop]) >= IsOperator(InputExpression[iCounter])){
                cPoppedOperator = Pop(OperatorStack,iTop);
                int iOutPutLen = strlen(OutputExpression);
                OutputExpression[iOutPutLen] = cPoppedOperator;
                OutputExpression[iOutPutLen+1] = '\0';
                printf("Output of else %s \n", OutputExpression);
            }  
            Push(OperatorStack , iTop , InputExpression[iCounter]);
        }
    }

    while(!IsEmpty(*iTop)){
        cPoppedOperator = Pop(OperatorStack, iTop);
        int iOutPutLen = strlen(OutputExpression);
        OutputExpression[iOutPutLen] = cPoppedOperator;
        OutputExpression[iOutPutLen + 1] = '\0';
        printf("After loop pop: %s\n", OutputExpression);
    }

    return OutputExpression;
}

/**
 * Post to Result Conversion cha logic
 * post fixed expression gheycha
 * if postfixed expression[i] is number -> push on stack
 * if postfixed expression[i] is operator , tr pop itop ,again pop itop2 retrun itop1 operator itop2
 * 
*/

int PostFixToResult(char* PostFixedExpression, int* ResultStack, int* iTop){ 
    int iCounter = 0;
    int Operand1 , Operand2 , Result;

    for( ; iCounter < strlen(PostFixedExpression) ; iCounter++){
        if(IsOperator(PostFixedExpression[iCounter]) < 0){
            PushInteger(ResultStack , iTop , (PostFixedExpression[iCounter] - '0'));
        }
        else{
            Operand2 = PopInteger(ResultStack , iTop);
            Operand1 = PopInteger(ResultStack , iTop);
            switch (PostFixedExpression[iCounter]){
                case '+' : Result = Operand1 + Operand2;
                break;
                case '-' : Result = Operand1 - Operand2;
                break;
                case '*' : Result = Operand1 * Operand2;
                break;
                case '/' : Result = Operand1 / Operand2;
                break;
            }
            PushInteger(ResultStack , iTop , Result);
        }
    }
    return PopInteger(ResultStack , iTop);
}
