#include "stdio.h"
#include "stdlib.h"
#define maxstack 10

struct stack{
    int data[maxstack];
    int top;
};

typedef struct stack st;

void createEmptyStack(st* myStack){
    myStack->top=-1;
}

int isStackisFull(st* myStack){
    if (myStack->top==maxstack-1){
        return 1;
    }else{
        return 0;
    }
}

int isStackisEmpty(st* mystack){
    if (mystack->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int pushToStack(st* myStack,int data){
    if (isStackisFull(myStack)){
        printf("Stack is full\n");
    }else{
        myStack->top++;
        myStack->data[myStack->top]=data;
    }
}

int popfromstack(st* myStack){
    if(isStackisEmpty(myStack)){
        printf("Stack is empty\n");
    }else{
        printf("%d\n",myStack->data[myStack->top]);
        myStack->top--;
    }
}
void dataFromstack(st* myStack){
    if (isStackisEmpty(myStack)){
        printf("Stack is Empty\n");
    }else{
        printf("There is %d data in stack\n",(myStack->top)+1);
        for (int i = myStack->top; i >-1 ; i--) {
            printf("Data at %d stack is %d\n",i,myStack->data[i]);
        }
    }
}

int main(){
    st* myStack= malloc(sizeof(st));
    createEmptyStack(myStack);
    pushToStack(myStack,10);
    pushToStack(myStack,20);
    pushToStack(myStack,30);
    pushToStack(myStack,40);
    pushToStack(myStack,50);
    pushToStack(myStack,60);
    pushToStack(myStack,70);
    pushToStack(myStack,80);
    pushToStack(myStack,90);
    pushToStack(myStack,100);
    dataFromstack(myStack);
    return 0;
}