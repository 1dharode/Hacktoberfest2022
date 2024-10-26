#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define size 50
char s[size];
int top = -1;
void push(char elem)
{
    s[++top] = elem;
}
char pop()
{
    return s[top--];
}
int precedence(char elem)
{
    switch (elem)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
    case '%':
        return 3;
    case '^':
        return 4;
    }
}

void main()
{
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;
    printf("Read the input expression\n");
    scanf("%s", infix);
    push('#');
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')

        {
            push(ch);
        }
        else if (isalnum(ch))

        {
            postfix[k++] = ch;
        }
        else if (ch == ')')

        {
            while (s[top] != '(')
                postfix[k++] = pop();
            elem = pop();
        }
        else
        {
            while (precedence(s[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("%s", postfix);
}
