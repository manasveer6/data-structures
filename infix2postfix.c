#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 20

char stack[MAX_SIZE];
int top = -1;

void push(char);
char pop();
int priority(char);

int main() {

    char exp[20];
    char *c, temp;

    printf("\e[1;1H\e[2J");
    printf("Enter infix expression: ");
    scanf("%s", exp);
    c = exp;

    printf("Postfix expression: ");

    while(*c != '\0') {

        if(isalnum(*c))
            printf("%c", *c);

        else if(*c == '(')
            push(*c);

        else if(*c == ')') {
            while((temp = pop()) != '(')
                printf("%c", temp);
        }

        else {
            while(priority(stack[top]) >= priority(*c))
                printf("%c", pop());
            push(*c);
        }

        c++;
    }

    while(top != -1)
        printf("%c", pop());

    printf("\n");

    return 0;
}

void push(char ch) {
    if(top == MAX_SIZE-1) {
        printf("\033[1;31mError pushing, Stack overflow.\n");
        exit(1);
    }
    stack[++top] = ch;
}

char pop() {
    if(top == -1) {
        printf("\033[1;31mError popping, Stack underflow.\n");
        exit(1);
    }
    return stack[top--];
}

int priority(char ch) {

    if(ch == '(')
        return 0;

    if(ch == '+' || ch == '-')
        return 1;

    if(ch == '*' || ch == '/')
        return 2;

    else
        return 0;
}