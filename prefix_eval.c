#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 20

int stack[MAX_SIZE];
int top = -1;

void push(int);
int pop();
int operate(int, int, char);

int main() {

    char exp[MAX_SIZE];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int i = strlen(exp) - 1;

    while(i >= 0)  {

        char c = exp[i];

        if(isdigit(c)) {
            int val = c - '0';
            push(val);
        }

        else {
            char symbol = c;
            int b = pop();
            int a = pop();
            int result = operate(a, b, symbol);
            push(result);
        }

        i--;
    }

    printf("Result: %d\n", pop());

    return 0;
}

void push(int x) {

    if(top == MAX_SIZE-1) {
        printf("Stack overflow.\n");
        exit(1);
    }
    else {
        stack[++top] = x;
    }
}

int pop() {

    if(top == -1) {
        printf("Stack underflow.\n");
        exit(1);
    }

    return stack[top--];
}

int operate(int a, int b, char oprtr) {

    int result;

    switch(oprtr) {

        case '*':
            result = a*b;
            break;
        case '/':
            result = a/b;
            break;
        case '+':
            result = a+b;
            break;
        case '-':
            result = a-b;
            break;
        
        default: printf("Invalid operator -> (%c)\n", oprtr);
    }
    
    return result;
}