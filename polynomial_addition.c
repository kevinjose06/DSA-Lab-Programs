#include <stdio.h>

// Structure to represent a term in the polynomial
struct Term 
{
    int coeff;
    int exp;
};

void displayPolynomial(struct Term poly[], int n); //Function prototype

// Function to add two polynomials
void addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[]) 
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) 
    {
        if (poly1[i].exp == poly2[j].exp) 
        {
            result[k].coeff = poly1[i].coeff + poly2[j].coeff;
            result[k].exp = poly1[i].exp;
            i++;
            j++;
            k++;
        } else if (poly1[i].exp > poly2[j].exp) 
        {
            result[k].coeff = poly1[i].coeff;
            result[k].exp = poly1[i].exp;
            i++;
            k++;
        } else 
        {
            result[k].coeff = poly2[j].coeff;
            result[k].exp = poly2[j].exp;
            j++;
            k++;
        }
    }

    while(i<n1)
    {
        result[k].coeff = poly1[i].coeff;
        result[k].exp = poly1[i].exp;
        i++;
        k++;
    }

    while(j<n2)
    {
        result[k].coeff = poly2[j].coeff;
        result[k].exp = poly2[j].exp;
        j++;
        k++;
    }

    displayPolynomial(result,k); //The display function to print the result
}

// Function to display a polynomial
void displayPolynomial(struct Term poly[], int n) 
{
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if (i != n - 1) 
        {
            printf(" + ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    struct Term poly1[100], poly2[100], result[100];
    int n1, n2, n3;

    // Read first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter polynomial 1:\n");
    for (int i = 0; i < n1; i++) 
    {
        printf("Enter coefficient of term %d: ",i+1);
        scanf("%d", &poly1[i].coeff);
        printf("Enter exponent of term %d: ",i+1);
        scanf("%d", &poly1[i].exp);
    }

    // Read second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    printf("Enter polynomial 2:\n");
    for (int i = 0; i < n2; i++) 
    {
        printf("Enter coefficient of term %d: ",i+1);
        scanf("%d", &poly2[i].coeff);
        printf("Enter exponent of term %d: ",i+1);
        scanf("%d", &poly2[i].exp);
    }

    // Display all polynomials
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1, n1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, n2);

    // Add polynomials
    addPolynomials(poly1, n1, poly2, n2, result);

    return 0;
}