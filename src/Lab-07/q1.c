/*
Array-Based Stack implementation
i. Check whether a given string is a palindrome using stack.
➤ Use character stack to compare original and reversed string.
ii. Check for matching parentheses in each expression.
➤ Push opening brackets, pop for matching closing brackets.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 32

typedef struct Stack
{
    char items[MAX_SIZE];
    int top;
} Stack;

bool isPalindrome(const char *str);
bool areParenthesesBalanced(const char *expr);

void initStack(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
bool push(Stack *s, char item);
char pop(Stack *s);
char peek(Stack *s);

int main()
{
    printf("--- Palindrome ---\n");

    char inputStr[MAX_SIZE];
    printf("Enter a string to check if it is a palindrome: ");
    scanf("%s", inputStr);
    inputStr[strcspn(inputStr, "\n")] = '\0'; // Remove trailing newline

    if (isPalindrome(inputStr))
        printf("\"%s\" is a palindrome.\n", inputStr);
    else
        printf("\"%s\" is not a palindrome.\n", inputStr);

    printf("--- END ---\n");

    printf("\n--- Matching Parentheses ---\n");

    printf("Enter an expression to check for balanced parentheses: ");
    char expr[MAX_SIZE];
    scanf("%s", expr);

    if (areParenthesesBalanced(expr))
        printf("The expression \"%s\" has balanced parentheses.\n", expr);
    else
        printf("The expression \"%s\" does not have balanced parentheses.\n", expr);

    printf("--- END ---\n");

    return 0;
}

bool isPalindrome(const char *str)
{
    Stack characterStack;
    initStack(&characterStack);
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        push(&characterStack, str[i]);
    }

    for (int i = 0; i < len; i++)
    {
        if (str[i] != pop(&characterStack))
            return false;
    }
    return true;
}

// Matching Parentheses Function
bool areParenthesesBalanced(const char *expr)
{
    Stack parenStack;
    initStack(&parenStack);

    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
        {
            push(&parenStack, expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']')
        {
            if (isEmpty(&parenStack))
                return false;

            char top = pop(&parenStack);
            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == '}' && top != '{') ||
                (expr[i] == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return isEmpty(&parenStack);
}

void initStack(Stack *s)
{
    s->top = -1;
}

bool isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

bool isEmpty(Stack *s)
{
    return s->top == -1;
}

bool push(Stack *s, char item)
{
    if (isFull(s))
        return false;

    s->items[++(s->top)] = item;
    return true;
}

char pop(Stack *s)
{
    if (isEmpty(s))
        return '\0';

    return s->items[(s->top)--];
}

char peek(Stack *s)
{
    if (isEmpty(s))
        return '\0';

    return s->items[s->top];
}
