/*Implement a Circular Queue using arrays with the operations:
a.Insert elements into the queue
b.Delete elements from the queue
c.Display the contents of the queue after each operation*/

#include<stdio.h>
#define MAX 20

int front = -1, rear = -1;
int queue[MAX];

void enque(int n)
{
    if(front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = n;
    }
    if(front == (front + 1) % MAX)
    {
        printf("Queue is full!");
        return;
    }
    if(rear == (rear + 1) % MAX)
    {
        rear = 0;
    }
    else
    {
        queue[++rear] = n;
    }
}