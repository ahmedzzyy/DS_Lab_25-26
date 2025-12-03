#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createPolynomialNode(int coeff, int exp);
Node *insertTerm(Node *head, int coeff, int exp);
Node *addPolynomials(Node *poly1, Node *poly2);
void displayPolynomial(Node *head);
void freePolynomial(Node *head);

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    Node *sumPoly = NULL;

    // first polynomial: 5x^3 + 4x^2 + 2
    poly1 = insertTerm(poly1, 5, 3);
    poly1 = insertTerm(poly1, 4, 2);
    poly1 = insertTerm(poly1, 2, 0);

    // second polynomial: 3x^3 + 2x + 1
    poly2 = insertTerm(poly2, 3, 3);
    poly2 = insertTerm(poly2, 2, 1);
    poly2 = insertTerm(poly2, 1, 0);

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    sumPoly = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(sumPoly);

    // Free allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sumPoly);

    return 0;
}

Node *createPolynomialNode(int coeff, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

Node *insertTerm(Node *head, int coeff, int exp)
{
    Node *newNode = createPolynomialNode(coeff, exp);
    if (head == NULL)
    {
        return newNode;
    }

    Node *current = head;
    Node *prev = NULL;

    while (current != NULL && current->exp > exp)
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->exp == exp)
    {
        current->coeff += coeff;
        free(newNode);

        // If coefficient becomes zero, remove the node
        if (current->coeff == 0)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                head = current->next;
            }

            // Adjust the prev pointer of the next node
            if (current->next)
            {
                current->next->prev = prev;
            }

            free(current);
        }
    }
    else
    {
        newNode->next = current;
        newNode->prev = prev;

        if (prev)
        {
            prev->next = newNode;
        }
        else
        {
            head = newNode;
        }

        if (current)
        {
            current->prev = newNode;
        }
    }

    return head;
}

Node *addPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *p1 = poly1;
    Node *p2 = poly2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0)
            {
                result = insertTerm(result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void displayPolynomial(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->coeff > 0 && current != head)
        {
            printf(" + ");
        }
        else if (current->coeff < 0)
        {
            printf(" - ");
        }

        printf("%dx^%d", abs(current->coeff), current->exp);
        current = current->next;
    }
    printf("\n");
}

void freePolynomial(Node *head)
{
    Node *current = head;
    Node *nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}