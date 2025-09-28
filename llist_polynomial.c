/* Write a program to read two polynomials and store them in an array. Calculate the sum of the 
two polynomials and display the first polynomial, second polynomial and the resultant polynomial.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
void insertTerm(struct Node** head, int coef, int exp) {
    struct Node* newNode = createNode(coef, exp);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
}

// Function to display polynomial
void displayPolynomial(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%dx^%d", ptr->coef, ptr->exp);
        if (ptr->next != NULL) printf(" + ");
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    struct Node* ptr1 = p1;
    struct Node* ptr2 = p2;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exp > ptr2->exp) {
            insertTerm(&result, ptr1->coef, ptr1->exp);
            ptr1 = ptr1->next;
        } else if (ptr1->exp < ptr2->exp) {
            insertTerm(&result, ptr2->coef, ptr2->exp);
            ptr2 = ptr2->next;
        } else {
            insertTerm(&result, ptr1->coef + ptr2->coef, ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL) {
        insertTerm(&result, ptr1->coef, ptr1->exp);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
        insertTerm(&result, ptr2->coef, ptr2->exp);
        ptr2 = ptr2->next;
    }
    return result;
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    for (struct Node* ptr1 = p1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (struct Node* ptr2 = p2; ptr2 != NULL; ptr2 = ptr2->next) {
            insertTerm(&result, ptr1->coef * ptr2->coef, ptr1->exp + ptr2->exp);
        }
    }

    // Combine like terms
    struct Node* ptr = result;
    while (ptr != NULL) {
        struct Node* runner = ptr;
        while (runner->next != NULL) {
            if (runner->next->exp == ptr->exp) {
                ptr->coef += runner->next->coef;
                struct Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        ptr = ptr->next;
    }
    return result;
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    int n, coef, exp;

    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coef, &exp);
        insertTerm(&poly1, coef, exp);
    }

    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coef, &exp);
        insertTerm(&poly2, coef, exp);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);
    printf("\nAddition Result: ");
    displayPolynomial(sum);

    struct Node* product = multiplyPolynomials(poly1, poly2);
    printf("Multiplication Result: ");
    displayPolynomial(product);

    return 0;
}