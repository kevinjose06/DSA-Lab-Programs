/* Implement Stack using array.*/

#include<stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int n)
{
    if(top>=MAX-1)
    {
        printf("Stack overflow!\n");
        return;
    }
    else
    {
        top+=1;
        stack[top]=n;
    }
}

int pop()
{
    if(top==-1)
    {
        printf("Stack underflow!\n");
        return 0;
    }
    else
    {
        int element = stack[top];
        top-=1;
        return element;
    }
}

int main()
{
    int i;

    push(10);
    push(20);
    push(30);

    printf("Stack after pushing:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }

    pop();

    printf("Stack after pop 1:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }

    pop();

    printf("Stack after pop 2:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}