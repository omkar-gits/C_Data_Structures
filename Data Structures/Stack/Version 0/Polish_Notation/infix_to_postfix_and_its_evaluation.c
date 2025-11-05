#include<stdio.h> 
#include<math.h>
#include"Stack.h"

#define MAX 50

void InfixToPostfix(const char* , char*);
long PostfixEvaluation(const char *);
int IsOperator(char);
int IsSpace(char);

int main(void){
    char  szInfix[MAX];
    char szPostfix[MAX];
    long int lResult;
    
    printf("Enter arithmetic expression :- \t");
    gets(szInfix);

    printf("\nInfix expression is :- \n%s", szInfix);
    InfixToPostfix(szInfix , szPostfix);
    printf("\nPostFix expression is :- \n%s", szPostfix);
    lResult = PostfixEvaluation(szPostfix);
    printf("\nResult is %ld\n",lResult);
    
    return 0;
}

int IsOperator(char chSymbol){
    switch(chSymbol){
        case '^':
            return 3;
        case '/':
        case '*':
        case '%':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return 0;
    }
}

int IsSpace(char chSymbol){
    if(chSymbol == ' ' || chSymbol == '\t'){
        return 1;
    }
    return 0;
}

void InfixToPostfix(const char* pszInfix , char * pszPostfix){
    char chSymbol;
    int iCounter1;
    int iCounter2;
    int iPriority;

    extern long int g_Stack[STACK_MAX];
    extern int g_iTop;

    iCounter2 = 0;
    for(iCounter1 = 0 ; pszInfix[iCounter1] != '\0'; iCounter1++){
        chSymbol = pszInfix[iCounter1];

        if(IsSpace(chSymbol)){
            continue;
        }

        if((iPriority = IsOperator(chSymbol)) > 0){ // If character is a Operator 
            while(!IsEmpty() && IsOperator(g_Stack[g_iTop]) >= iPriority){
                pszPostfix[iCounter2++] = Pop();
            }  
            Push(chSymbol);
        }
        else if(chSymbol == '('){
            Push(chSymbol);
        }
        else if(chSymbol == ')'){
            while((chSymbol = Pop()) != '('){
                pszPostfix[iCounter2++] = chSymbol;
            }
        }
        else{   //Character is an Operand
                pszPostfix[iCounter2++] ='[';
                do{
                    pszPostfix[iCounter2++] = chSymbol;
                    chSymbol = pszInfix[++iCounter1];
                }while(IsOperator(chSymbol) == 0 && !IsSpace(chSymbol) && chSymbol != ')' && chSymbol!='\0');
                pszPostfix[iCounter2++] = ']';
                iCounter1--;
        }
    }

    while(!IsEmpty()){
        pszPostfix[iCounter2++] = Pop();
    }
    pszPostfix[iCounter2] = '\0';
}


long int PostfixEvaluation(const char * pszPostfix){
    int iCounter;
    char chSymbol;

    long lResult;
    long lOperand1;
    long lOperand2;


    for(iCounter = 0; pszPostfix[iCounter] != '\0' ; iCounter++){
        chSymbol = pszPostfix[iCounter];
        if(IsOperator(chSymbol)){
            lOperand2 = Pop();
            lOperand1 = Pop();

            switch(chSymbol){
                case '+':
                    lResult = lOperand1 + lOperand2;
                    break;
                case '-':
                    lResult = lOperand1 - lOperand2;
                    break;
                case '*':
                    lResult = lOperand1 * lOperand2;
                    break;
                case '/':
                    lResult = lOperand1 / lOperand2;
                    break;
                case '%':
                    lResult = lOperand1 % lOperand2;
                    break;
                case '^':
                    lResult = pow(lOperand1,lOperand2);
                    break;
            }
            Push(lResult);
        }

        else{
            char chTemp[15];
            int iCounter2 = 0;

            while(pszPostfix[++iCounter] != ']'){
                chTemp[iCounter2++] = pszPostfix[iCounter];
            }
            chTemp[iCounter2] = '\0';
            Push(atof(chTemp));
        }
    }

    return Pop();
}