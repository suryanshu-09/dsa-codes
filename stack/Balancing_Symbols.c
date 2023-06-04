#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *stack, *inp;
int isEmpty(), isFull(); 
void push(char), pop();
char *peak();
int top=-1, size=10, err = 0;
int main(){
    int i;
    inp = (char *)malloc(size*sizeof(char));
    stack = (char *)malloc(size*sizeof(char));
    scanf("%s", inp);
    for(i = 0; i<strlen(inp); i++){
        switch (*(inp+i)){
            case '(':
                push(*(inp+i));
                break;
            case ')':
                if(*(peak())!='('){
                    printf("(err\n");
                    err++;
                    break;
                }else{
                    pop();
                    break;
                }
            case '{':
                push(*(inp+i));
                break;
            case '}':
                if(*(peak())!='{'){
                    printf("{err\n");
                    err++;
                    break;
                }else{
                    pop();
                    break;
                }
            case '[':
                push(*(inp+i));
                break;
            case ']':
                if(*(peak())!='['){
                    printf("[err\n");
                    err++;
                    break;
                }else{
                    pop();
                    break;
                }
            default: 
                printf("deferr\n");
                err++;
                break;
        }
    }
    (isEmpty()&&(err==0))?printf("balanced\n"):
            printf("notemperr\n");
    return 0;
    
}
char *peak(){
    if(isEmpty()) return "peakerr\n";
    else
        return (stack+top);
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
void push(char x){
        (*(stack+(++top))=x);
}
void pop(){;
        top--;
}
