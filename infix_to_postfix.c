#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define MAX 50

int top=-1,topval=-1;
char stack[MAX];//Stack to convert to postfix
int eval[MAX];//Stack for evaluating the  expression

void push(char c)//Pop function for the conversion
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

char pop()//Psuh function for the conversion
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

void pushval(int n)//Push function for the evaluation
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

int popval()//Pop function for the evaluation
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

int isp(char op)//In-stack precedence order of operators
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

int icp(char op)//Precedence of incoming operators
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

int result(int v1,int v2,char op)//Function to perform the evaluaion
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

    //Converts the expression to postfix
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
    postfix[p] = '\0';
    printf("%s\n",postfix);//Prints the postfix expression
    postfix[p++] = '#';//Set a delimiter
    i=0;
    while(postfix[i] != '#')
    {
        if(isdigit(postfix[i]))
        {
            pushval(postfix[i]-'0');//To find the numerical value of a charecter subtract ASCII value of charecter '0' from it
        }
        else
        {
            val2 = popval();
            val1 = popval();
            r = result(val1,val2,postfix[i]);
            pushval(r);
        }
        i++;
    }

    printf("Result: %d\n", popval());//Print the evaluated result
    return 0;
}