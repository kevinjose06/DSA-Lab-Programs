//Create a binary tree for a given simple arithmetic expression and find the prefix / postfix equivalent.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(char c) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = c;
    node->left = node->right = NULL;
    return node;
}

#define MAX 100

struct Node* operandStack[MAX];
char operatorStack[MAX];
int topOperand = -1, topOperator = -1;

void pushOperand(struct Node* node) { operandStack[++topOperand] = node; }
struct Node* popOperand() { return operandStack[topOperand--]; }

void pushOperator(char c) { operatorStack[++topOperator] = c; }
char popOperator() { return operatorStack[topOperator--]; }
int isOperatorStackEmpty() { return topOperator == -1; }

int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

int isOperator(char c) { return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'; }

// Build tree from infix without parentheses and without peek()
struct Node* buildTree(char expr[]) {
    for(int i=0; expr[i]!='\0'; i++){
        char c = expr[i];
        if(isspace(c)) continue;

        if(!isOperator(c)) { // operand
            pushOperand(newNode(c));
        } else { // operator
            // Pop operators with higher or equal precedence
            while(topOperator != -1) {
                char topOp = popOperator();
                if(precedence(topOp) >= precedence(c)) {
                    struct Node* right = popOperand();
                    struct Node* left = popOperand();
                    struct Node* node = newNode(topOp);
                    node->left = left;
                    node->right = right;
                    pushOperand(node);
                } else {
                    // If we popped it but it has lower precedence, push it back
                    pushOperator(topOp);
                    break;
                }
            }
            pushOperator(c);
        }
    }

    while(topOperator != -1) {
        char op = popOperator();
        struct Node* right = popOperand();
        struct Node* left = popOperand();
        struct Node* node = newNode(op);
        node->left = left;
        node->right = right;
        pushOperand(node);
    }

    return popOperand(); // root
}

// Traversals
void printPrefix(struct Node* root){
    if(!root) return;
    printf("%c ", root->data);
    printPrefix(root->left);
    printPrefix(root->right);
}

void printPostfix(struct Node* root){
    if(!root) return;
    printPostfix(root->left);
    printPostfix(root->right);
    printf("%c ", root->data);
}

// Test
int main() {
    char expr[MAX];

    printf("Enter the expression : ");
    scanf("%s",expr);
    
    struct Node* root = buildTree(expr);

    printf("Prefix: ");
    printPrefix(root);
    printf("\nPostfix: ");
    printPostfix(root);
    printf("\n");
    return 0;
}
