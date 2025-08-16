/*Write a program in C to check whether a string is palindrome or not, using stack.*/

#include<stdio.h>
#include<string.h>
#define MAX 50

int top=-1;
char stack[MAX];

void push(char c)
{
    if(top>=MAX-1)
    {
        printf("Stack overflow!\n");
        return;
    }
    else
    {
        top+=1;
        stack[top]=c;
    }
}

char pop()
{
    if(top==-1)
    {
        printf("Stack underflow!\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

void main()
{
    char str[50];
    int i,flag=1;

    printf("Enter the string:");
    scanf("%s",str);

    for(i=0;i<strlen(str);i++)
    {
        push(str[i]);
    }

    for(i=0;i<strlen(str);i++)
    {
        if(str[i]!=pop())
        {
            flag=0;
            break;
        }
    }

    if(flag==1)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome!");
    }
}