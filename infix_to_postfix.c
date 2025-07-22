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
        stack[++top]=c;
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

int isp(char op)
{
    if(op=='^')
    {
        return 5;
    }
    else if(op=='*'||op=='/')
    {
        return 4;
    }
    else if(op=='+'||op=='-')
    {
        return 2;
    }
    else if(op=='(')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int icp(char op)
{
    if(op=='(')
    {
        return 7;
    }
    else if(op=='^')
    {
        return 6;
    }
    else if(op=='*'||op=='/')
    {
        return 3;
    }
    else if(op=='+'||op=='-')
    {
        return 1;
    }
    else if(op==')')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char str[MAX],el,x;
    int l,i=0;

    printf("Enter your expression:");
    scanf("%s",str);

    l=strlen(str);
    str[l]=')';
    str[l+1]='\0';

    push('(');
    
    while(top>-1)
    {
        el = str[i++];
        x=pop();

        if (el != '+' && el != '-' && el != '*' && el != '/' && el != '^' && el != '(' && el != ')') 
        {
            printf("%c\n",el);
            push(x);
        }
        else if(el==')')
        {
            while(x!='(')
            {
                printf("%c\n",x);
                x=pop();
            }
        }
        else if(isp(x)>=icp(el))
        {
            while(isp(x)>=icp(el))
            {
                printf("%c\n",x);
                x=pop();
            }
            push(x);
            push(el);

        }
        else if(isp(x)<icp(el))
        {
            push(x);
            push(el);
        }
    }
    
    return 0;
}