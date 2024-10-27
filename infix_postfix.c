#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
char stack[MAX];
int top = 0;
char pop() {
    return stack[top--];
}
void push(char item) {
    stack[++top] = item;
}
int precedence(char symbol) {
    switch(symbol) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 6;
        case '(':
        case ')':
        case '#': return 1;
    }
    return -1; // Handle unrecognized symbols
}
int isOperator(char symbol) {
    switch(symbol) {
        case '+':
        case '*':
        case '-':
        case '/':
        case '^':
        case '(':
        case ')': return 1;
    }
    return 0;
}
void convertToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    stack[top] = '#';

    for(i = 0; i < strlen(infix); i++) {
        char symbol = infix[i];

        if(!isOperator(symbol)) {
            postfix[j++] = symbol;
        } else {
            if(symbol == '(') {
                push(symbol);
            } else if(symbol == ')') {
                while(stack[top] != '(') {
                    postfix[j++] = pop();
                }
                pop(); // Pop '('
            } else {
                while(precedence(symbol) <= precedence(stack[top])) {
                    postfix[j++] = pop();
                }
                push(symbol);
            }
        }
    }
    while (stack[top] != '#') {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null terminate string
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter a valid infix string:\n");
    fgets(infix, sizeof(infix), stdin);
    convertToPostfix(infix, postfix);
    printf("The corresponding postfix string is:\n%s\n", postfix);
    return 0;
}
