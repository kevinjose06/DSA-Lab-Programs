#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define MAX 50

int top=-1, topval=-1;
char stack[MAX];    // Operator stack for conversion
int eval[MAX];      // Stack for evaluation (prefix)

void push(char c) { if(top<MAX-1) stack[++top]=c; else printf("Stack overflow!\n"); }
char pop() { return (top==-1) ? '\0' : stack[top--]; }
char peek() { return (top==-1) ? '\0' : stack[top]; }

void pushval(int n) { if(topval<MAX-1) eval[++topval]=n; else printf("Stack overflow!\n"); }
int popval() { return (topval==-1) ? 0 : eval[topval--]; }

// In-stack precedence
int isp(char op){
    if(op=='^') return 5;
    if(op=='*'||op=='/') return 4;
    if(op=='+'||op=='-') return 2;
    if(op=='(') return 0;
    return -1;
}

// Incoming precedence
int icp(char op){
    if(op=='(') return 7;
    if(op=='^') return 6;
    if(op=='*'||op=='/') return 3;
    if(op=='+'||op=='-') return 1;
    if(op==')') return 0;
    return -1;
}

// Evaluate a single operation
int result(int v1,int v2,char op){
    switch(op){
        case '+': return v1+v2;
        case '-': return v1-v2;
        case '*': return v1*v2;
        case '/': return v1/v2;
        case '^': return pow(v1,v2);
        default: return 0;
    }
}

int main(){
    char str[MAX], el, x, prefix[MAX][MAX];
    int i=0, p=0, topPre=-1;
    char temp[MAX], op1[MAX], op2[MAX];

    printf("Enter your expression: ");
    scanf("%s", str);

    int l = strlen(str);
    str[l] = ')'; str[l+1] = '\0';
    push('(');  // Initial '('

    // Convert infix to prefix using stack
    while(top>-1){
        el = str[i++];
        x = pop();

        if(isalnum(el)){  // Operand
            strcpy(prefix[++topPre], (char[]){el,'\0'});
            push(x);
        }
        else if(el==')'){ // Pop until '('
            while(x!='('){
                popval(); // unused, just mimic postfix style
                push(x);  // restore?
                x = pop(); 
            }
        }
        else if(isp(x)>=icp(el)){
            while(isp(x)>=icp(el)){
                // Pop two prefix strings
                if(topPre<1){ push(x); break; }
                strcpy(op2, prefix[topPre--]);
                strcpy(op1, prefix[topPre--]);
                sprintf(temp, "%c%s%s", x, op1, op2);
                strcpy(prefix[++topPre], temp);
                x = pop();
            }
            push(x);
            push(el);
        }
        else{
            push(x);
            push(el);
        }
    }

    // Process remaining operators
    while(top>-1){
        x = pop();
        if(x=='(') break;
        strcpy(op2, prefix[topPre--]);
        strcpy(op1, prefix[topPre--]);
        sprintf(temp, "%c%s%s", x, op1, op2);
        strcpy(prefix[++topPre], temp);
    }

    printf("Prefix Expression: %s\n", prefix[topPre]);

    // Evaluate prefix if numeric
    int numeric = 1;
    for(i=0; prefix[topPre][i]; i++){
        if(isalpha(prefix[topPre][i])){
            numeric = 0;
            break;
        }
    }

    if(numeric){
        // Evaluate prefix expression
        char *exp = prefix[topPre];
        int stackVal[MAX], topE=-1, op1v, op2v, res;
        for(i=strlen(exp)-1; i>=0; i--){
            if(isdigit(exp[i]))
                stackVal[++topE] = exp[i]-'0';
            else{
                op1v = stackVal[topE--];
                op2v = stackVal[topE--];
                stackVal[++topE] = result(op1v, op2v, exp[i]);
            }
        }
        printf("Evaluated Result: %d\n", stackVal[topE]);
    } else {
        printf("Contains variables — skipping evaluation.\n");
    }

    return 0;
}
