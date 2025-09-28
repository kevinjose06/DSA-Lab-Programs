#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int exp;
    struct node* link;
};

// Create a new node
struct node* getnode(int coef, int exp) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->coef = coef;
    n->exp = exp;
    n->link = NULL;
    return n;
}

// Insert node at end
struct node* insertEnd(struct node* head, int coef, int exp) {
    struct node* n = getnode(coef, exp);
    if(head == NULL) {
        return n;
    }
    struct node* ptr = head;
    while(ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = n;
    return head;
}

// Combine like terms
void combineLikeTerms(struct node* head) {
    struct node* ptr = head;
    while(ptr != NULL) {
        struct node* runner = ptr;
        while(runner->link != NULL) {
            if(ptr->exp == runner->link->exp) {
                ptr->coef += runner->link->coef;
                struct node* temp = runner->link;
                runner->link = runner->link->link;
                free(temp);
            } else {
                runner = runner->link;
            }
        }
        ptr = ptr->link;
    }
}

// Display polynomial
void display(struct node* head) {
    if(head == NULL) { printf("0\n"); return; }
    struct node* ptr = head;
    while(ptr != NULL) {
        printf("%dx^%d", ptr->coef, ptr->exp);
        if(ptr->link != NULL) printf(" + ");
        ptr = ptr->link;
    }
    printf("\n");
}

// Create polynomial
struct node* create() {
    struct node* head = NULL;
    int n, coef, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i+1);
        scanf("%d %d", &coef, &exp);
        head = insertEnd(head, coef, exp);
    }
    combineLikeTerms(head);
    return head;
}

// Addition
struct node* addition(struct node* h1, struct node* h2) {
    struct node* result = NULL;
    struct node* ptr1 = h1;
    struct node* ptr2 = h2;

    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1->exp > ptr2->exp) {
            result = insertEnd(result, ptr1->coef, ptr1->exp);
            ptr1 = ptr1->link;
        } else if(ptr1->exp < ptr2->exp) {
            result = insertEnd(result, ptr2->coef, ptr2->exp);
            ptr2 = ptr2->link;
        } else {
            result = insertEnd(result, ptr1->coef + ptr2->coef, ptr1->exp);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL) {
        result = insertEnd(result, ptr1->coef, ptr1->exp);
        ptr1 = ptr1->link;
    }
    while(ptr2 != NULL) {
        result = insertEnd(result, ptr2->coef, ptr2->exp);
        ptr2 = ptr2->link;
    }
    combineLikeTerms(result);
    return result;
}

// Multiplication
struct node* product(struct node* h1, struct node* h2) {
    struct node* result = NULL;
    struct node* ptr1 = h1;
    struct node* ptr2;

    while(ptr1 != NULL) {
        ptr2 = h2;
        while(ptr2 != NULL) {
            result = insertEnd(result, ptr1->coef * ptr2->coef, ptr1->exp + ptr2->exp);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }

    combineLikeTerms(result);
    return result;
}

int main() {
    struct node* h1 = create();
    struct node* h2 = create();

    printf("\nPolynomial 1: ");
    display(h1);
    printf("Polynomial 2: ");
    display(h2);

    struct node* sum = addition(h1, h2);
    printf("\nAddition Result: ");
    display(sum);

    struct node* prod = product(h1, h2);
    printf("Multiplication Result: ");
    display(prod);

    return 0;
}
