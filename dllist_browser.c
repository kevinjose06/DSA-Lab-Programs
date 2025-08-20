/*Implement backward and forward navigation of visited web pages in a web browser (i.e. back and forward buttons)
using doubly linked list operations.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    char data[100];
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;
struct node* current = NULL;

// Function to create and attach new node at the end
void addnode(char str[]) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) 
    {
        printf("Memory not allocated!\n");
        return;
    }
    strcpy(newnode->data, str);
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) 
    {
        head = newnode;
        current = newnode;
    } 
    else 
    {
        struct node* ptr = head;
        while (ptr->next != NULL) 
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
        current = newnode;   // move to new page
    }
    printf("Visited: %s\n", current->data);
}

// Backward navigation
void back() 
{
    if (current != NULL && current->prev != NULL) 
    {
        current = current->prev;
        printf("Back: %s\n", current->data);
    } 
    else 
    {
        printf("No previous page!\n");
    }
}

// Forward navigation
void forward() 
{
    if (current != NULL && current->next != NULL) 
    {
        current = current->next;
        printf("Forward: %s\n", current->data);
    } 
    else 
    {
        printf("No next page!\n");
    }
}

// Display current
void display() 
{
    if (current != NULL) 
    {
        printf("Current page: %s\n", current->data);
    } 
    else 
    {
        printf("No page visited yet!\n");
    }
}

int main() 
{
    int ch;
    char str[100];

    // preload 3 pages
    addnode("Hello there");
    addnode("Enter your website");
    addnode("Thank you, visit again");

    while (1) {
        printf("\n1. Visit new page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Display current\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        getchar();

        switch (ch) {
            case 1:
                printf("Enter page name: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = '\0';
                addnode(str);
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
