/*Implement a Queue using arrays with the operations:
a.Insert elements into the queue
b.Delete elements from the queue
c.Display the contents of the queue after each operation*/

#include<stdio.h>
#define MAX 20

int front = -1, rear = -1;
int queue[MAX];

//Function to add elements to the queue
void enqueue(int n) 
{
    if(rear >= MAX-1) 
    {
        printf("Queue is full!\n");
        return;
    }
    if(front == -1) 
    {
        front = 0; //Value of front is set to 0 when element 1 is stored
    }
    queue[++rear] = n;
}

//Function to remove elements from the queue
int dequeue() {
    if(front == -1) 
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = queue[front];//If only 1 element is presen in the queue
    if(front == rear) 
    {
        front = rear = -1;
    } else 
    {
        front++;
    }
    return item;
}

//Function to display the elements
void display() {
    if(front == -1) 
    {
        printf("Queue is empty!\n");
        return;
    }
    for(int i = front; i <= rear; i++) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() 
{
    int op, val;
    
    while(1) 
    {
        printf("1) Add\n2) Remove\n3) Display\n4) Exit\n");
        printf("Choice: ");
        scanf("%d", &op);
        
        switch(op) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                display();
                break;
                
            case 2:
                val = dequeue();
                if(val != -1) {
                    printf("Removed: %d\n", val);
                }
                display();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                return 0;
                
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}