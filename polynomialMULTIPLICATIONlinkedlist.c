// Single File Programming Question
// Problem Statement



// Lisa is studying polynomials in her class. She is learning about the multiplication of polynomials. 



// To practice her understanding, she wants to write a program that multiplies two polynomials and displays the result. Each polynomial is represented as a linked list, where each node contains the coefficient and exponent of a term.



// Example



// Input:

// 4 3

// y

// 3 1

// y

// 1 0

// n

// 2 2

// y

// 3 1

// y

// 2 0

// n



// Output:

// 8x^5 + 12x^4 + 14x^3 + 11x^2 + 9x + 2



// Explanation



// 1. Poly1: 4x^3 + 3x + 1

// 2. Poly2: 2x^2 + 3x + 2



// Multiplication Steps:



// 1. Multiply 4x^3 by Poly2:

//    -> 4x^3 * 2x^2 = 8x^5

//    -> 4x^3 * 3x = 12x^4

//    -> 4x^3 * 2 = 8x^3



// 2. Multiply 3x by Poly2:

//    -> 3x * 2x^2 = 6x^3

//    -> 3x * 3x = 9x^2

//    -> 3x * 2 = 6x



// 3. Multiply 1 by Poly2:

//    -> 1 * 2x^2 = 2x^2

//    -> 1 * 3x = 3x

//    -> 1 * 2 = 2



// Combine the results:  8x^5 + 12x^4 + (8x^3 + 6x^3) + (9x^2 + 2x^2) + (6x + 3x) + 2



// The combined polynomial is: 8x^5 + 12x^4 + 14x^3 + 11x^2 + 9x + 2

// Input format :
// The input consists of two sets of polynomial terms.

// Each polynomial term is represented by two integers separated by a space:

// The first integer represents the coefficient of the term.
// The second integer represents the exponent of the term.


// After entering a polynomial term, the user is prompted to input a character indicating whether to continue adding more terms to the polynomial.

// If the user inputs 'y' or 'Y', the program continues to accept more terms.

// If the user inputs 'n' or 'N', the program moves on to the next polynomial.

// Output format :
// The output consists of a single line representing the resulting polynomial after multiplying the two input polynomials.



// Each term of the resulting polynomial is formatted as follows:

// The coefficient and exponent are separated by 'x^' if the exponent is greater than 1.
// If the exponent is 1, only 'x' is displayed without the exponent.
// If the exponent is 0, only the coefficient is displayed.


// Refer to the sample output for the formatting specifications.

// Code constraints :
// The coefficients and exponents will be integers.

// The coefficients will be in the range [-10, 10].

// The exponents will be in the range [0, 10].

// The number of terms in each polynomial will be at most 10
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coeff, power;
    struct Node *next;
};
void insert(struct Node **head, int c, int p){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->coeff = c;
    temp->power = p;
    temp->next = *head;
    *head = temp;
}
void print(struct Node *head){
    struct Node *temp = head;
    printf("\nPolynomial: ");
    while(temp != NULL){
        if(temp->next != NULL){
            printf("%dx^%d + ", temp->coeff, temp->power);
        }
        else{
            printf("%dx^%d", temp->coeff, temp->power);
        }
        temp = temp->next;
    }
}
struct Node * find(struct Node *head, int power){
    struct Node *temp = head;
    while(temp != NULL){
        if(temp->power == power){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void multiply(struct Node *head1, struct Node *head2, struct Node **mainhead){
    struct Node *t1 = head1;
    struct Node *t2 = head2;
    while(t1 != NULL){
        t2 = head2;
        while(t2 != NULL){
            int coeff = (t1->coeff)*(t2->coeff);
            int power = (t1->power) + (t2->power);
            struct Node *temp = find(*mainhead, power);
            if(temp == NULL){
                insert(mainhead, coeff, power);
            }
            else{
                temp->coeff += coeff;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}
int main(){
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *result = NULL;
    char choice = 'y';
    int coeff, power;
    while(choice == 'y' || choice == 'Y'){
        printf("\nEnter term: ");
        scanf(" %d %d", &coeff, &power);
        insert(&head1, coeff, power);
        printf("\nEnter choice: ");
        scanf(" %c", &choice);
    }
    choice = 'y';
    print(head1);
    while(choice == 'y' || choice == 'Y'){
        printf("\nEnter term: ");
        scanf(" %d %d", &coeff, &power);
        insert(&head2, coeff, power);
        printf("\nEnter choice: ");
        scanf(" %c", &choice);
    }
    print(head2);
    multiply(head1, head2, &result);
    print(result);
    return 0;
}