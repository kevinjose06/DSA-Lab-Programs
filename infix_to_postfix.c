#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define MAX 50

int top=-1,topval=-1;
char stack[MAX];
int eval[MAX];

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

void pushval(int n)
{
    if(topval>=MAX-1)
    {
        printf("Stack overflow!\n");
        return;
    }
    else
    {
        eval[++topval]=n;
    }
}

int popval()
{
    if(topval==-1)
    {
        printf("Stack underflow!\n");
        return 0;
    }
    else
    {
        return eval[topval--];
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

int result(int v1,int v2,int op)
{
    if(op=='+')
        return v1+v2;
    else if(op=='-')
        return v1-v2;
    else if(op=='*')
        return (v1*v2);
    else if(op=='/')
        return(v1/v2);
    else if(op=='^')
        return(pow(v1,v2));
    else
        return 0;
}

int main()
{
    char str[MAX],el,x,postfix[MAX];
    int l,i=0,val1,val2,p=0,r;

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

        if (isalnum(el)) 
        {
            postfix[p++]=el;
            push(x);
        }
        else if(el==')')
        {
            while(x!='(')
            {
                postfix[p++]=x;
                x=pop();
            }
        }
        else if(isp(x)>=icp(el))
        {
            while(isp(x)>=icp(el))
            {
                postfix[p++]=x;
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

    postfix[p]='\0';
    printf("Postfix expression:\n");
    printf("%s\n",postfix);

    for(i=0;i<p;i++)
    {
        if(isdigit(postfix[i]))
        {
            pushval(postfix[i]-'0');
        }
        else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^')
        {
            val2 = popval();
            val1 = popval();

            r = result(val1,val2,postfix[i]);
            pushval(r);
        }
    }

    printf("%d\n",eval[0]);
    
    return 0;
}