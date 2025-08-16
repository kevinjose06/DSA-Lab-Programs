/*Implement a Double Ended Queue using arrays with the operations:
a.Insert elements into the queue (both front and rear)
b.Delete elements from the queue (both front and rear)
c.Display the contents of the queue after each operation*/

#include<stdio.h>
#define MAX 5

int front = -1,rear = -1;
int deque[MAX];

//Function to insert element at rear end
void inrear(int n)
{
    if(front == (rear + 1) % MAX)
    {
        printf("Deque Overflow! Cannot insert more elements.\n");
        return;
    }
    else if(front == -1 && rear == -1)//Empty deque
    {
        front = 0;
        rear = 0;
        deque[rear] = n;
    }
    /*If the rear pointer is present at the last index,since it's a circular array we have to come back to
    the front of the deque,since insertion,so we reassign rear as 0th index*/ 
    else if(rear == MAX - 1)
    {
        rear = 0;
        deque[rear] = n;
    }
    else
    {
        rear += 1;
        deque[rear] = n;
    }
    printf("Inserted %d at rear.\n",deque[rear]);
}

//Function to delete element from the rear end
void delrear()
{
    if(front == -1 && rear == -1)
    {
        printf("Deque Underflow! Cannot insert more elements.\n");
        return;
    }
    else if(front == rear)//Only single element present
    {
        printf("Deleted %d from rear.\n",deque[rear]);
        front = -1;
        rear = -1;
    }
    /*If the rear pointer is present at the first index,since it's a circular array we have to come to
    the last index of the deque,since it's a deletion,so we reassign rear as last index*/ 
    else if(rear == 0)
    {
        printf("Deleted %d from rear.\n",deque[rear]);
        rear = MAX -1;
    }
    else
    {
        printf("Deleted %d from rear.\n",deque[rear]);
        rear -= 1;
    }
}

//Function to insert element at the front position
void infront(int n)
{
    if(front == (rear + 1) % MAX)
    {
        printf("Deque Overflow! Cannot insert more elements.\n");
        return;
    }
    else if(front == -1 && rear == -1)//Only single element present
    {
        front = 0;
        rear = 0;
        deque[front] = n;
    }
    /*If the front pointer is present at the first index,since it's a circular array we have to come to
    the back of the deque,since insertion,so we reassign rear as last index*/ 
    else if(front == 0)
    {
        front = MAX - 1;;
        deque[front] = n;
    }
    else
    {
        front -= 1;
        deque[front] = n;
    }
    printf("Inserted %d at front.\n",deque[front]);
}

//Function to delete at front
void delfront()
{
    if(front == -1 && rear == -1)
    {
        printf("Deque Underflow! Cannot insert more elements.\n");
        return;
    }
    else if(front == rear)//Single element present
    {
        printf("Deleted %d from front.\n",deque[front]);
        front = -1;
        rear = -1;
    }
    /*If the front pointer is present at the last index,since it's a circular array we have to come to
    the first index of the deque,since it's a deletion,so we reassign rear as first index*/
    else if(front == MAX - 1)
    {
        printf("Deleted %d from front.\n",deque[front]);
        front = 0;
    }
    else
    {
        printf("Deleted %d from front.\n",deque[front]);
        front += 1;
    }
}

//Display function
void display()
{
    int i = front;

    printf("Queue contents: ");
    while(i != rear)
    {
        printf("%d ",deque[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n",deque[rear]);
}

int main()
{
    int n,op,i,el;

    printf("Enter the number of operations:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter your choice:\n1) Add at rear\n2) Add at front\n3) Display\n4) Delete at front\n5) Delete at rear\n6)Exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("Enter the element:");
            scanf("%d",&el);
            inrear(el);
            display();
            break;

            case 2:
            printf("Enter the element:");
            scanf("%d",&el);
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

            case 6:
            break;

            default:
            printf("Invalid input!");
            break;
        }
        break;
    }
    return 0;
}