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

/*#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coef;
	int exp;
	struct node* link;
};

struct node* getnode(struct node* h)
{
	struct node* n;
	struct node* ptr = h;

	n = (struct node*)malloc(sizeof(struct node);

	if(n == NULL)
	{
		printf("Couldn't add node!\n");
		return;
	}
	else
	{
		while(ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = n;
		n->link = NULL;
	}
	return n;
}

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
		printf("%d+x^%d ",ptr->coef,ptr->exp);
	}
	printf("\n");
}

void insert(struct node* h)
{
	struct node* newnode;
   	int coef,exp;

    	newnode = (struct node*)malloc(sizeof(struct node));
    	if(newnode == NULL)
    	{
        	printf("Memory alocation failed!\n");
        	return;
    	}
    	else
	{

    		printf("Enter the cofficent:");
    		scanf("%d",&coef);
		newnode->coef = coef;
		printf("Enter the exponent:");
                scanf("%d",&exp);
		newnode->exp = exp;

        	struct node* ptr = h;

        	while(ptr->link != NULL)
        	{
            		ptr = ptr->link;
        	}
        	ptr->link = newnode;
        	newnode->link = NULL;
    	}

}

void sum(struct node* h1,struct node* h2,struct node* h3)
{
	struct node* ptr1 = h1;
	struct node* ptr2 = h2;
	struct node* ptr3;


	printf("Enter the number of terms in polynomial 1:");
	while((ptr1 != NULL)&&(ptr2 != NULL));
	{
		if(ptr1->exp == ptr2->exp)
		{
			ptr3->link = getnode(head3);
			ptr3->coef = ptr1->coef + ptr2->coef;
			ptr3->exp = ptr1->exp;
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
	}
}

int main()
{
	struct node* head1;
	struct node* head2;
	struct node* head3;

	int n1,n2,i;

	if(head1 == NULL)
	{
		printf("Memory allocation failed!");
		return 0;
	}
	else
	{
		head1->link = NULL;
	}
	if(head2 == NULL)
        {
                printf("Memory allocation failed!");
                return 0;
        }
	else
        { 
                head2->link = NULL;
        }
	if(head3 == NULL)
        {
                printf("Memory allocation failed!");
                return 0;
        }
        else
        { 
                head3->link = NULL;
        }

	printf("Enter the number of terms of polynomial 1:");
	for(i = 0;i < n1;i++)
	{
		insert(head1);
	}
	printf("Enter the number of terms of  polynomial 2:");
        for(i = 0;i < n1;i++)
        {
                insert(head2);
        }

	printf("Polynomial 1: ");
	display(head1);
	printf("Polynomial 2: ");
        display(head2);

	printf("Sum of the polynoials:\n");
	sum(head1,head2,head3);
	printf("Product of the polynomials:\n");
	//product(head1,head2,head3);

	return 0;
}
*/
