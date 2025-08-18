/*Write a program to convert an infix expression to a prefix expression using stack.*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAX 50

int top = -1, topval = -1;
char stack[MAX];   // Stack to convert to prefix
int eval[MAX];     // Stack for evaluating prefix

void push(char c) {
    if (top >= MAX - 1)
        printf("Stack overflow!\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    } else
        return stack[top--];
}

void pushval(int n) {
    if (topval >= MAX - 1)
        printf("Stack overflow!\n");
    else
        eval[++topval] = n;
}

int popval() {
    if (topval == -1) {
        printf("Stack underflow!\n");
        return 0;
    } else
        return eval[topval--];
}

int isp(char op) {
    if (op == '^')
        return 5;
    else if (op == '*' || op == '/')
        return 4;
    else if (op == '+' || op == '-')
        return 2;
    else if (op == ')') // when scanning right-to-left, ) acts like (
        return 0;
    else
        return -1;
}

int icp(char op) {
    if (op == ')')
        return 7;  // high precedence to push onto stack
    else if (op == '^')
        return 6;
    else if (op == '*' || op == '/')
        return 3;
    else if (op == '+' || op == '-')
        return 1;
    else if (op == '(') // when scanning right-to-left, ( acts like )
        return 0;
    else
        return -1;
}

int result(int v1, int v2, char op) {
    if (op == '+')
        return v1 + v2;
    else if (op == '-')
        return v1 - v2;
    else if (op == '*')
        return v1 * v2;
    else if (op == '/')
        return v1 / v2;
    else if (op == '^')
        return pow(v1, v2);
    else
        return 0;
}

int main() {
    char str[MAX], el, x, prefix[MAX];
    int l, i, val1, val2, p = 0, r;

    printf("Enter your expression: ");
    scanf("%s", str);

    l = strlen(str);

    // Start with ')' on stack for right-to-left scan
    push(')');

    // Scan from right to left
    i = l - 1;
    while (top > -1) {
        el = (i >= 0) ? str[i--] : '\0';
        x = pop();

        if (isalnum(el)) { // operand
            prefix[p++] = el;
            push(x);
        }
        else if (el == '(') { // acts like ')' in normal L->R
            while (x != ')') {
                prefix[p++] = x;
                x = pop();
            }
        }
        else if (isp(x) > icp(el)) {
            while (isp(x) > icp(el)) {
                prefix[p++] = x;
                x = pop();
            }
            push(x);
            push(el);
        }
        else {
            push(x);
            if (el != '\0') push(el);
        }
    }

    // Reverse prefix array to get correct order
    for (i = 0; i < p / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[p - i - 1];
        prefix[p - i - 1] = temp;
    }
    prefix[p] = '\0';

    printf("Prefix expression: %s\n", prefix);

    // Evaluate prefix expression
    for (i = p - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            pushval(prefix[i] - '0');
        } else {
            val1 = popval();
            val2 = popval();
            r = result(val1, val2, prefix[i]);
            pushval(r);
        }
    }

    printf("Result: %d\n", popval());
    return 0;
}
