/*Using stack, convert an infix expression to a postfix expression and evaluate the postfix expression.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 50

char stack[MAX];
int eval[MAX];
int top = -1, topval = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

void pushval(int n) {
    if (topval == MAX - 1)
        printf("Value Stack Overflow\n");
    else
        eval[++topval] = n;
}

int popval() {
    if (topval == -1)
        printf("Value Stack Underflow\n");
    else
        return eval[topval--];
    return 0;
}

int isp(char op) {
    switch (op) {
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        default: return -1;
    }
}

int icp(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '^': return 6;
        case '(': return 7;
        case ')': return 0;
        default: return -1;
    }
}

void reverse(char *exp) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

int iresult(int v1, int v2, char op) {
    switch (op) {
        case '+': return v1 + v2;
        case '-': return v1 - v2;
        case '*': return v1 * v2;
        case '/': return v1 / v2;
        case '^': return pow(v1, v2);
        default: return 0;
    }
}

void infixToPrefix(char E[], char prefix[]) {
    char item, x;
    int i = 0, k = 0;

    reverse(E); // Step 1: Reverse infix

    // Step 2: Swap '(' and ')'
    for (i = 0; E[i] != '\0'; i++) {
        if (E[i] == '(')
            E[i] = ')';
        else if (E[i] == ')')
            E[i] = '(';
    }

    strcat(E, ")");  // Append closing bracket
    push('(');
    i = 0;

    while (top > -1) {
        item = E[i++];

        if (item == '\0') break;

        if (isalnum(item)) {
            prefix[k++] = item;
        }
        else if (item == ')') {
            x = pop();
            while (x != '(') {
                prefix[k++] = x;
                x = pop();
            }
        }
        else {
            x = pop();
            if (isp(x) >= icp(item)) {
                while (isp(x) >= icp(item)) {
                    prefix[k++] = x;
                    x = pop();
                }
                push(x);
                push(item);
            } else {
                push(x);
                push(item);
            }
        }
    }

    prefix[k] = '\0';
    reverse(prefix); // Final prefix
}

int evaluatePrefix(char prefix[]) {
    int i, n1, n2, r;
    int len = strlen(prefix);

    // Evaluate from right to left
    for (i = len - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            pushval(prefix[i] - '0');
        } else {
            n1 = popval();
            n2 = popval();
            r = result(n1, n2, prefix[i]);
            pushval(r);
        }
    }
    return popval();
}

int main() 
{
    char expr[MAX], prefix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", expr);

    infixToPrefix(expr, prefix);
    printf("Prefix Expression: %s\n", prefix);

    int ans = evaluatePrefix(prefix);
    printf("Evaluated Result: %d\n", ans);

    return 0;
}
