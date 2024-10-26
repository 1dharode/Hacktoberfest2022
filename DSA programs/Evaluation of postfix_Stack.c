#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define max 50
int stack[max];
char postfix[max];
int top = -1;
void pushstack(int tmp);
void calculator(char c);
void main()
{
    int i;
    printf("\nEnter the postfix expression\n");
    scanf("%s", postfix);
    for (i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            pushstack(i);
        }
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {
            calculator(postfix[i]);
        }
    }
    printf("result is %d", stack[top]);
}
void pushstack(int tmp)
{
    top++;
    stack[top] = (int)(postfix[tmp] - 48);
}
void calculator(char c)
{
    int a, b, ans;
    a = stack[top];
    stack[top] = '\0';
    top--;
    b = stack[top];
    stack[top] = '\0';
    top--;

    switch (c)
    {
    case '+':
        ans = b + a;
        break;
    case '-':
        ans = b - a;
        break;
    case '*':
        ans = b * a;
        break;
    case '/':
        ans = b / a;
        break;
    case '^':
        ans = pow(b, a);
        break;
    default:
        ans = 0;
    }
    top++;
    stack[top] = ans;
}