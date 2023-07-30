/*
A program on implementation of Stacks and various operations performed on it.
 
List of operations that can be performed on the Stack in this program:

    1. Display the whole stack
    2. Peek the top of the stack
    3. Push an integer into the stack
    4. Pop an integer from the stack
    5. Empty out the entire stack
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Maximum size of the stack
#define MAX_SIZE 100

//Helper functions:

void showMenu();
bool isEmpty();
bool isFull();

//Main stack operation functions:

void push(int x);

void pop();
void clearStack();

void peek();
void displayStack();

int stack[MAX_SIZE];
int top = -1;

int main() {

    printf("\n");
    printf("**************************************************\n");
    printf("*                                                *\n");
    printf("*            Welcome to Stack Program            *\n");
    printf("*                                                *\n");
    printf("**************************************************\n");


    int choice, num;

    while(true) {

        showMenu();
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                displayStack();
                break;

            case 2:
                peek();
                break;

            case 3:
                printf("Enter number to be pushed: ");
                scanf("%d", &num);
                push(num);
                break;

            case 4:
                pop();
                break;

            case 5:
                clearStack();
                break;

            case 6:
                printf("\n");
                printf("**************************************************\n");
                printf("*                                                *\n");
                printf("*                   Goodbye!                     *\n");
                printf("*         Thank you for using the stack!         *\n");
                printf("*                                                *\n");
                printf("**************************************************\n\n");

                exit(0);
                break;

            default: printf("\nInvalid option! Try again.\n");
        }
    }

    return 0;    
}

//Checks whether the stack is empty or not. Returns true if empty, false if not.
bool isEmpty() {
    return (top < 0);
}

//Checks whether the stack is full or not. Returns true if full, false if not.
bool isFull() {
    return (top >= MAX_SIZE - 1);
}

//Pushes an element into the top of the stack.
void push(int x) {
    if(isFull())
        printf("\nStack overflow.\n");
    else {
        stack[++top] = x;
        printf("\nPushed %d into the stack succesfully.\n", x);
    }
}

//Pops an element from the top of the stack.
void pop() {
    if(isEmpty())
        printf("\nStack underflow.\n");
    else {
        top--;
        printf("\nPopped succesfully.\n");
    }
}

//Empties out the stack.
void clearStack() {
    if(isEmpty()) {
        printf("\nStack is already empty.\n");
        return;
    }
    top = -1;
    printf("\nStack succesfully emptied.\n");
}

//Displays the element present at the top of the stack.
void peek() {
    if(isEmpty()) {
        printf("\nStack is empty. Nothing to peek.\n");
        return;
    }
    printf("\n%d\n", stack[top]);
}

//Displays the entire stack.
void displayStack() {
    if(isEmpty()) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nCurrent Stack:\n");
    for(int i=top; i >= 0; i--) {
        printf("\t%d\n", stack[i]);
    }
}

//Shows user menu.
void showMenu() {

    printf("\n____________________________________________________________");
    printf("\n\nChoose one - ");
    printf("\n\n\n\t1. DISPLAY the stack");
    printf("\n\n\t2. PEEK the stack");
    printf("\n\n\t3. PUSH into the stack");
    printf("\n\n\t4. POP from the stack");
    printf("\n\n\t5. CLEAR the stack");
    printf("\n\n\t6. EXIT");

    printf("\n\nEnter the operation you'd like to perform [1-6] : ");
}