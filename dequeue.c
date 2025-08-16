/*Implement a Double Ended Queue using arrays with the operations:
a.Insert elements into the queue (both front and rear)
b.Delete elements from the queue (both front and rear)
c.Display the contents of the queue after each operation*/

#include<stdio.h>
#define MAX 5

int main()
{
    int n,op,i,el;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("%d",&el);
            inrear(el);
            display();
            break;

            case 2:
            printf("%d",&el);
            infront(el);
            display();
            break;

            case 3:
            display();
            break;

            case 4:
            delfront();
            display();
            break;

            case 5:
            delrear();
            display();
            break;

            default:
            printf("Invalid input!");
            break;
        }
    }
    return 0;
}