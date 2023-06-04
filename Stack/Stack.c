#include<stdio.h>
#include<stdlib.h>
int isEmpty(), isFull(); 
void push(int), pop(), peak(), traversal();
int switchDo();
int top=-1, size=10, *stk;
int stack[10];
int main(){
    switchDo();
    return 0;
}
int switchDo(){
    int i, num;
    printf("1. isEmpty()\n2. isFull()\n3. push()\n4. pop()\n5. peak()\n6. traversal()\n7. Exit\n");
    scanf("%d", &i);
    switch (i){
        case 1:
            (isEmpty())?printf("Is Empty.\n"):
                printf("Is Not Empty.\n");
            printf("\n");
            switchDo();
            return 0;
        case 2:
            (isFull())?printf("Is Full.\n"):
                printf("Is Not Full.\n");
            printf("\n");
            switchDo();
            return 0;
        case 3:
            printf("Enter The Num to Push: ");
            scanf("%d", &num);
            push(num);
            printf("\n");
            switchDo();
            return 0;
        case 4:
            pop();
            printf("\n");
            switchDo();
            return 0;
        case 5:
            peak();
            printf("\n");
            switchDo();
            return 0;
        case 6:
            traversal();
            printf("\n");
            switchDo();
            return 0;
        case 7:
            printf("Exited\n");
            return 0;
        default:
            printf("Enter a Valid Option.\n");
            printf("\n");
            switchDo();
            return 0;
    }
    return 0;
}
void traversal(){
    int i;
    if (isEmpty()){
        printf("Is Empty.\n");
    }else{
        for(i=0; i<=top; i++){
            printf("%d: %d\n", i+1, stack[i]);
        }
    }
}
void peak(){
    (isEmpty())?printf("Is Empty\n"):
        printf("Peak: %d\n", stack[top]);
}
int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(){
    if(top==size-1){
        return 1;
    }else{
        return 0;
    }
}
void push(int x){
    (isFull())?printf("Full\n"):
        (stack[++top]=x);
}
void pop(){
    int r;
    (isEmpty())?printf("Empty\n"):
        (r=stack[top--], printf("Popped: %d\n", r));
}
