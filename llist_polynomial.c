/* Write a program to read two polynomials and store them in an array. Calculate the sum of the 
two polynomials and display the first polynomial, second polynomial and the resultant polynomial.*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int coef;
    int exp;
    struct node* link;
};

// ------------------ GETNODE ------------------
struct node* getnode(struct node* h) 
{
    struct node* n;
    struct node* ptr = h;

    n = (struct node*)malloc(sizeof(struct node));

    if (n == NULL) 
    {
        printf("Couldn't add node!\n");
        return 0;
    } else
    {
        while (ptr->link != NULL) 
        {
            ptr = ptr->link;
        }
        ptr->link = n;
        n->link = NULL;
    }
    return n;
}

// ------------------ DISPLAY ------------------
void display(struct node* h) 
{
    struct node* ptr = h;

    if (ptr == NULL || ptr->link == NULL) 
    {
        printf("Empty polynomial!\n");
        return;
    }

    ptr = ptr->link;
    while (ptr != NULL) 
    {
        printf("%dx^%d", ptr->coef, ptr->exp);
        if (ptr->link != NULL)
            printf(" + ");
        ptr = ptr->link;
    }
    printf("\n");
}

// ------------------ COMBINE LIKE TERMS ------------------
void combineLikeTerms(struct node* h) 
{
    struct node* ptr = h->link;   
    struct node* ptr1, *prev, *temp;

    while (ptr != NULL) 
    {
        prev = ptr;
        ptr1 = ptr->link;        

        while (ptr1 != NULL) 
        {
            if (ptr->exp == ptr1->exp) 
            {
                ptr->coef += ptr1->coef;

                prev->link = ptr1->link;
                temp = ptr1;
                ptr1 = ptr1->link;
                free(temp);
            } 
            else 
            {
                prev = ptr1;
                ptr1 = ptr1->link;
            }
        }   
        ptr = ptr->link;
    }
}

// ------------------ POLYNOMIAL CREATION ------------------
void create(struct node* h) 
{
    int n, coef, exp, i;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d%d", &coef, &exp);
        struct node* newnode = getnode(h);
        newnode->coef = coef;
        newnode->exp = exp;
    }
}

// ------------------ ADDITION ------------------
void addition(struct node* h1, struct node* h2, struct node* h3) 
{
    struct node* ptr1 = h1->link;
    struct node* ptr2 = h2->link;
    struct node* ptr3;

    while (ptr1 != NULL && ptr2 != NULL) 
    {
        ptr3 = getnode(h3);

        if (ptr1->exp > ptr2->exp) 
        {
            ptr3->coef = ptr1->coef;
            ptr3->exp = ptr1->exp;
            ptr1 = ptr1->link;
        } 
        else if (ptr1->exp < ptr2->exp) 
        {
            ptr3->coef = ptr2->coef;
            ptr3->exp = ptr2->exp;
            ptr2 = ptr2->link;
        } 
        else 
        {
            ptr3->coef = ptr1->coef + ptr2->coef;
            ptr3->exp = ptr1->exp;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
    }

    while (ptr1 != NULL) 
    {
        ptr3 = getnode(h3);
        ptr3->coef = ptr1->coef;
        ptr3->exp = ptr1->exp;
        ptr1 = ptr1->link;
    }

    while (ptr2 != NULL) 
    {
        ptr3 = getnode(h3);
        ptr3->coef = ptr2->coef;
        ptr3->exp = ptr2->exp;
        ptr2 = ptr2->link;
    }
}

// ------------------ MULTIPLICATION ------------------
void product(struct node* h1, struct node* h2, struct node* h4) 
{
    struct node* ptr1 = h1->link;
    struct node* ptr2;
    struct node* ptr4;

    while (ptr1 != NULL) 
    {
        ptr2 = h2->link;
        while (ptr2 != NULL) 
        {
            ptr4 = getnode(h4);
            ptr4->coef = ptr1->coef * ptr2->coef;
            ptr4->exp = ptr1->exp + ptr2->exp;
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }

    combineLikeTerms(h4);
}

int main() 
{
    struct node* h1 = (struct node*)malloc(sizeof(struct node));
    struct node* h2 = (struct node*)malloc(sizeof(struct node));
    struct node* h3 = (struct node*)malloc(sizeof(struct node));
    struct node* h4 = (struct node*)malloc(sizeof(struct node));

    h1->link = NULL;
    h2->link = NULL;
    h3->link = NULL;
    h4->link = NULL;

    printf("Enter Polynomial 1:\n");
    create(h1);
    printf("Enter Polynomial 2:\n");
    create(h2);

    printf("\nPolynomial 1: ");
    display(h1);
    printf("Polynomial 2: ");
    display(h2);

    addition(h1, h2, h3);
    printf("\nAddition Result: ");
    display(h3);

    product(h1, h2, h4);
    printf("Multiplication Result: ");
    display(h4);

    return 0;
}
