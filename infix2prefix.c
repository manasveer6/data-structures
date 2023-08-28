//DOESNT WORK YET AAAHHHHH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 20

char stack[MAX_SIZE];
int top = -1;

void push(char);
char pop();
int priority(char);
char* reverse_exp(char*);
void append_str(char*, char ch);

int main() {

    char input[MAX_SIZE], exp[MAX_SIZE+2];
    char result[MAX_SIZE];
    char *c, temp;

    printf("\e[1;1H\e[2J");
    printf("Enter infix expression: ");
    scanf("%s", input);
    snprintf(exp, sizeof(exp), "(%s)", input);

    c = exp;

    strcpy(exp, reverse_exp(exp));
    printf("Reversed infix: %s\n", exp);

    printf("Postfix expression: ");

    while(*c != '\0') {

        if(isalnum(*c))
            append_str(result, *c);

        else if(*c == '(')
            append_str(result, *c);

        else if(*c == ')') {
            while((temp = pop()) != '(')
                append_str(result, temp);
        }

        else {
            while(priority(stack[top]) >= priority(*c))
                append_str(result, pop());
            push(*c);
        }

        c++;
    }

    while(top != -1)
        append_str(result, pop());

    printf("%s", result);
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

char* reverse_exp(char* str) {
    int size = strlen(str);
    char* result = malloc((size+1)*sizeof(char));

    for(int i=0; i < size; i++) {
        if(str[size-i-1] == '(')
            result[i] = ')';

        else if(str[size-i-1] == ')')
            result[i] = '(';

        else
            result[i] = str[size-i-1];
    }

    result[size] = '\0';

    return result;
}

void append_str(char* str, char ch) {
    int len = strlen(str);
    str[len] = ch;
    str[len + 1] = '\0'; // Null-terminate the string after appending
}