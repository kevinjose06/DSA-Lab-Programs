/*Implement a Queue using linked lists with the operations:
a.Insert elements into the queue
b.Delete elements from the queue
c.Display the contents of the queue after each operation*/

#include<stdio.h>
#include<stdlib.h>

/*Store the node as a structure with the data part storing the value and the link part storing the 
address to the next node.*/
struct node
{
    int data;
    struct node* link;
};

//Function to display the linked list
void display(struct node* h)
{
    struct node* ptr = h;
    if(ptr == NULL)
    {
        printf("Empty list!\n");
        return;
    }
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
        printf("%d ",ptr->data);
    }
    printf("\n");
}

//Insert new node at the end of the linked list.
void insert(struct node* h)
{
    struct node* newnode;
    int el;

    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory alocation failed!\n");
        return;
    }
    else
    //Receive the new input and create the new node
    printf("Enter the number:");
    scanf("%d",&el);
    {
        struct node* ptr = h;
        //Traversing till the end of the list
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = newnode;
        newnode->data = el;
        newnode->link = NULL;
    }
    display(h);
}

//Remove the first node connected to the head node
void delete(struct node* h)
{
    struct node* ptr = h->link;//Store the address of the second node to the Head node

    if(ptr == NULL)
    {
        printf("Empty list!\n");
        return;
    }
    //Connecting the head node the node after the deleted node
    h->link = ptr->link;
    free(ptr);
    display(h);
}

int main()
{
    struct node* head;
    int n,ch,i;

    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Memory alocation failed!\n");
        return 0;
    }
    else
    {
        head->link = NULL; 
    }
    printf("Enter the number of operations:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter your choice:\n1)Insertion\n2)Deletion\n3)Display\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            insert(head);
            break;

            case 2:
            delete(head);
            break;

            case 3:
            display(head);
            break;

            default:
            printf("Invalid input!\n");
            break;
        }
    }
    return 0;
}