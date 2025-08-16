/*Implement a Circular Queue using arrays with the operations:
a.Insert elements into the queue
b.Delete elements from the queue
c.Display the contents of the queue after each operation*/

#include<stdio.h>
#define MAX 5

int front = -1, rear = -1;
int queue[MAX];

//Function to add elements
void enqueue(int n)
{
    if(front == (rear + 1) % MAX)
    {
        printf("Queue overflow!\n");
        return;
    }
    else if(front == -1 && rear == -1)//Only 1 element in the queue
    {
        front = 0;
        rear = 0;
        queue[rear] = n;
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = n;
    }
    printf("Inserted %d into the queue.\n",queue[rear]);
}

//Delete element from the queue
void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue underflow\n");
        return;
    }
    else if(front == rear)//Only 1 element in the queue
    {
        printf("Deleted %d from the queue.\n",queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deleted %d from the queue.\n",queue[front]);
        front = (front + 1) % MAX;
    }
}

void display()
{
    int i = front;
    /*We start from the front of the Queue.Since its a circular queue 
    we can't do i++ to move to the next position.So we use the modulus operator.
    And after the loop since only the element at the rear position is left out
    we print it separately.*/
    if(front == -1 && rear == -1)
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        printf("Queue contents: ");
        while(i != rear)
        {
            printf("%d ",queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n",queue[rear]);
    }
}

int main()
{
    int n,op,el,i;

    printf("Enter the number of operations:");
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        printf("Enter your choice:\n1) Add\n2) Remove\n3) Display\n4) Exit\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            printf("Enter the number:");
            scanf("%d",&el);
            enqueue(el);
            display();
            break;

            case 2:
            dequeue();
            display();
            break;

            case 3:
            display();
            break;

            case 4:
            break;

            default:
            printf("Invalid input!");
            break;
        }
        if(op == 4)
        {
            break;
        }
    }
    return 0;
}