#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term
struct Term {
    int coeff;
    int expo;
    struct Term* next;
};

// Function to create a new node
struct Term* createNode(int coeff, int expo) {
    struct Term* newNode = (struct Term*)malloc(sizeof(struct Term));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

// Function to add a term to the polynomial
void addTerm(struct Term** poly, int coeff, int expo) {
    struct Term* newNode = createNode(coeff, expo);
    newNode->next = *poly;
    *poly = newNode;
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* last = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        int coeff, expo;
        
        if (poly1 == NULL) { // Only poly2 terms remain
            coeff = poly2->coeff;
            expo = poly2->expo;
            poly2 = poly2->next;
        } else if (poly2 == NULL) { // Only poly1 terms remain
            coeff = poly1->coeff;
            expo = poly1->expo;
            poly1 = poly1->next;
        } else if (poly1->expo > poly2->expo) { // poly1 has higher exponent
            coeff = poly1->coeff;
            expo = poly1->expo;
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) { // poly2 has higher exponent
            coeff = poly2->coeff;
            expo = poly2->expo;
            poly2 = poly2->next;
        } else { // Same exponent, add coefficients
            coeff = poly1->coeff + poly2->coeff;
            expo = poly1->expo;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (coeff != 0) { // Only add non-zero terms
            struct Term* newNode = createNode(coeff, expo);
            if (result == NULL) {
                result = newNode;
                last = result;
            } else {
                last->next = newNode;
                last = last->next;
            }
        }
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(struct Term* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->expo);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Main function to demonstrate polynomial addition
int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    // Example: Adding 3x^2 + 5x^1 + 6 with 6x^2 + 2x^1 + 4
    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 5, 1);
    addTerm(&poly1, 6, 0);

    addTerm(&poly2, 6, 2);
    addTerm(&poly2, 2, 1);
    addTerm(&poly2, 4, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    struct Term* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
