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
    else if (op == '(')
        return 0;
    else
        return -1;
}

int icp(char op) {
    if (op == '(')
        return 7;
    else if (op == '^')
        return 6;
    else if (op == '*' || op == '/')
        return 3;
    else if (op == '+' || op == '-')
        return 1;
    else if (op == ')')
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
    int l, i = 0, val1, val2, p = 0, r, temp;

    printf("Enter your expression: ");
    scanf("%s", str);

    l = strlen(str);

    // Reverse the infix expression
    for (i = 0; i < l / 2; i++) {
        temp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = temp;
    }

    // Swap parenthesis
    for (i = 0; i < l; i++) {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }

    // Add a ')' at the end
    str[l] = ')';
    str[l + 1] = '\0';

    i = 0;
    p = 0;
    push('('); // Initial push to start conversion

    while (top > -1) {
        el = str[i++];
        x = pop();

        if (isalnum(el)) {
            prefix[p++] = el;
            push(x);
        } else if (el == ')') {
            while (x != '(') {
                prefix[p++] = x;
                x = pop();
            }
        } else if (isp(x) >= icp(el)) {
            while (isp(x) >= icp(el)) {
                prefix[p++] = x;
                x = pop();
            }
            push(x);
            push(el);
        } else {
            push(x);
            push(el);
        }
    }

    // Reverse the result to get final prefix
    for (i = 0; i < p / 2; i++) {
        temp = prefix[i];
        prefix[i] = prefix[p - i - 1];
        prefix[p - i - 1] = temp;
    }

    prefix[p] = '\0';
    printf("Prefix expression: %s\n", prefix);

    // Evaluate the prefix expression
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
