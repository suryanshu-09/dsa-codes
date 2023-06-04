#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1;
char *expSt;
void push(char ), pop();
int peakpre();
char peak();
int main(){
    char exp[100];
    char output[100];
    expSt = (char*)malloc(50*sizeof(int));
    int i, j=0, k;
    fgets(exp, 100, stdin);
    for(i=0;exp[i]!='\0';i++){
        if(48<=exp[i]&&exp[i]<=57){
            output[j++] = exp[i];
        }else{
            switch (exp[i]){
                case '+':
                    (peak()=='0'||peak()=='('||peak()==')')?push('+'):
                        (1 <= peakpre())?(output[j++]=peak(), pop(), push('+')):
                            (printf("%d", top), push('+'));
                    break;
                case '-':
                    (peak()=='0'||peak()=='('||peak()==')')?push('-'):
                        (1 <= peakpre())?(output[j++]=peak(), pop(), push('-')):
                            push('-');
                    break;
                case '/':
                    (peak()=='0'||peak()=='('||peak()==')')?push('/'):
                        (2 <= peakpre())?(output[j++]=peak(), pop(), push('/')):
                            push('/');
                    break;
                case '*':
                    (peak()=='0'||peak()=='('||peak()==')')?push('*'):
                        (2 <= peakpre())?(output[j++]=peak(), pop(), push('*')):
                            push('*');
                    break;
                case '%':
                    (peak()=='0'||peak()=='('||peak()==')')?push('%'):
                        (2 <= peakpre())?(output[j++]=peak(), pop(), push('%')):
                            push('%');
                    break;
                case '(':
                    push('(');
                    break;
                case ')':
                    while(expSt[top]!='('){
                        output[j++]=expSt[top--];
                    }
                    pop();
                    break;
                default:
                break;
            }
        }
    }
    for(i=top; i>=0; i--){
        (expSt[i]!=')'||expSt[i]!=')')?output[j++]=expSt[i]:
            printf("");
    }
    printf("%s\n", output);
}
void push(char x){
    expSt[++top] = x;
}
void pop(){
    expSt[top--];
}
int peakpre(){
    if (top==-1){
        return '0';
    }else{
        if (expSt[top]=='+'){
            return 1;
        }else if (expSt[top]=='-'){
            return 1;
        }else if (expSt[top]=='*'){
            return 2;
        }else if (expSt[top]=='/'){
            return 2;
        }else if (expSt[top]=='%'){
            return 2;
        }
    }
}
char peak(){
    if (top==-1){
        return '0';
    }else{
        return expSt[top];
    }
}
