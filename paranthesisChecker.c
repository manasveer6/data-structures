#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 20

void push(char);
bool checkPair();
bool isPar(char);
bool isOpenPar(char);
bool parType(char, char);
bool checkParanthesis(char*);

char stack[MAX_SIZE];
int top = -1;

int main() {

    char exp[MAX_SIZE];

    printf("Enter an expression: ");
    scanf("%s", exp);

    bool result = checkParanthesis(exp);

    printf( (result) ? "Balanced expression.\n" : "Unbalanced Expression.\n" );

    return 0;
}

void push(char ch) {
    
    if(top == MAX_SIZE-1) {
        printf("\033[1;31mError pushing, Stack overflow.\n");
        exit(1);
    }

    stack[++top] = ch;
}

bool isPar(char ch) {
    return (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}');
}

bool isOpenPar(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

bool parType(char open, char close) {
    
    if(open == '(' && close == ')')
        return true;
    else if(open == '[' && close == ']')
        return true;
    else if(open == '{' && close == '}')
        return true;
    else return false;
}

bool checkPair() {

    if(top <= 0) {
        return false;
    }

    char closePar = stack[top--];
    char openPar = stack[top--];

    if(parType(openPar, closePar)) {
        return true;
    }
    else return false;
}

bool checkParanthesis(char* exp) {

    char *c = exp;
    bool result = true;

    while(*c != '\0' && result) {

        if(isPar(*c)) {

            if(isOpenPar(*c)) {
                push(*c);
            }
            else {
                push(*c);
                result = checkPair();
            }
        }

        c++;
    }

    if(top != -1)
        result = false;

    return result;
}