#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1, isEmpty(), isFull();
void traversal();
int *expSt;
void push(int ), pop();
int main(){
    //6523+ 8 * +3 + *
    char exp[100];
    expSt = (int*)malloc(50*sizeof(int));
    int i, temp;
    fgets(exp, 100, stdin);
    for(i=0;exp[i]!='\0';i++){
        if(48<=exp[i]&&exp[i]<=57){
            temp = exp[i] - 48;
            push(temp);
        }else{
            switch (exp[i]){
                case '+':
                    expSt[top-1] = expSt[top] + expSt[(top-1)];
                    pop();
                    break;
                case '-':
                    expSt[top-1] = expSt[top] - expSt[(top-1)];
                    pop();
                    break;
                case '/':
                    expSt[top-1] = expSt[top] / expSt[(top-1)];
                    pop();
                    break;
                case '*':
                    expSt[top-1] = expSt[top] * expSt[(top-1)];
                    pop();
                    break;
                case '%':
                    expSt[top-1] = expSt[top] % expSt[(top-1)];
                    pop();
                    break;
                default:
                break;
            }
        }
    }
    printf("%d\n", expSt[top]);
}
void traversal(){
    int i;
    if (isEmpty()){
        printf("Is Empty.\n");
    }else{
        for(i=0; i<=top; i++){
            printf("%d: %d\n", i+1, expSt[i]);
        }
    }
}
int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(){
    if(top==50-1){
        return 1;
    }else{
        return 0;
    }
}
void push(int x){
    expSt[++top] = x;
}
void pop(){
    expSt[top--];
}
