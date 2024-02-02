#include <stdio.h>
#include <conio.h>

#define MAX_DEGREE 100

// Function to add two polynomials
void addPolynomials(int poly1[], int degree1, int poly2[], int degree2, int result[]) {
    int i;

    // Initialize result array with zeros
    for (i = 0; i < MAX_DEGREE; ++i) {
        result[i] = 0;
    }

    // Add coefficients from the first polynomial
    for (i = 0; i <= degree1; ++i) {
        result[i] += poly1[i];
    }

    // Add coefficients from the second polynomial
    for (i = 0; i <= degree2; ++i) {
        result[i] += poly2[i];
    }
}

// Function to display a polynomial
void displayPolynomial(int poly[], int degree) {
    int i;

    for (i = degree; i >= 0; --i) {
        if (poly[i] != 0) {
            printf("%dx^%d", poly[i], i);
            if (i > 0 && poly[i - 1] != 0) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main() {
    int poly1[MAX_DEGREE + 1], poly2[MAX_DEGREE + 1], result[MAX_DEGREE + 1];
    int degree1, degree2, i;

    // Input for the first polynomial
    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);

    printf("Enter the coefficients of the first polynomial (from x^0 to x^%d):\n", degree1);
    for (i = 0; i <= degree1; ++i) {
        scanf("%d", &poly1[i]);
    }

    // Input for the second polynomial
    printf("\nEnter the degree of the second polynomial: ");
    scanf("%d", &degree2);

    printf("Enter the coefficients of the second polynomial (from x^0 to x^%d):\n", degree2);
    for (i = 0; i <= degree2; ++i) {
        scanf("%d", &poly2[i]);
    }

    // Add the polynomials
    addPolynomials(poly1, degree1, poly2, degree2, result);

    // Display the result
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1, degree1);

    printf("\nSecond Polynomial: ");
    displayPolynomial(poly2, degree2);

    printf("\nSum of the Polynomials: ");
    displayPolynomial(result, degree1 > degree2 ? degree1 : degree2);
    
    getch();
    return 0;
    
}
