/*
Linked List-Based Stack Implementation:
i. Write a program to input an infix expression and convert into its equivalent
post fix form and display. Operands can be single characters.
ii. Evaluate a postfix expression using stack.
➤ Push operands, pop two for operator, and push result back.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 32

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void infixToPostfix(const char *infix, char *postfix);
int evaluatePostfix(const char *postfix);

int precedence(char op);

void initStack(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char data);
char pop(Stack *s);
char peek(Stack *s);

int main()
{
    char expression[MAX_SIZE], postfixExpr[MAX_SIZE];

    printf("--- Infix to Postfix Conversion & Evaluation ---\n");
    printf("\nEnter an infix expression: ");
    scanf("%s", expression);

    infixToPostfix(expression, postfixExpr);
    printf("\nPostfix Expression: %s\n", postfixExpr);

    int result = evaluatePostfix(postfixExpr);
    printf("\nResult of Postfix Evaluation: %d\n", result);
    printf("\n--- END ---\n");

    return 0;
}

int evaluatePostfix(const char *postfix)
{
    Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char token = postfix[i];

        if (token >= '0' && token <= '9')
        {
            push(&s, token - '0'); // Convert char to int
        }
        else
        {
            int val2 = pop(&s);
            int val1 = pop(&s);
            int result;

            switch (token)
            {
            case '+':
                result = val1 + val2;
                break;
            case '-':
                result = val1 - val2;
                break;
            case '*':
                result = val1 * val2;
                break;
            case '/':
                result = val1 / val2;
                break;
            default:
                printf("Invalid Operator: %c\n", token);
                exit(1);
            }

            push(&s, result);
        }
    }

    return pop(&s);
}

void infixToPostfix(const char *infix, char *postfix)
{
    Stack s;
    initStack(&s);

    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char token = infix[i];

        if (token >= '0' && token <= '9')
        {
            postfix[j++] = token;
        }
        else if (token >= 'a' && token <= 'z' || token >= 'A' && token <= 'Z')
        {
            continue;
        }
        else if (token == '(')
        {
            push(&s, token);
        }
        else if (token == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }

            // Remove '(' from stack
            pop(&s);
        }
        else
        {
            // Operator
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(token))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, token);
        }
    }

    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}

void initStack(Stack *s)
{
    s->top = NULL;
}

int isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = s->top;

    s->top = newNode;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        exit(1);
    }

    Node *temp = s->top;
    char poppedData = temp->data;
    s->top = s->top->next;
    free(temp);

    return poppedData;
}

char peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty\n");
        exit(1);
    }

    return s->top->data;
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}