/*
A program on implementation of Queues and various operations performed on it.
 
List of operations that can be performed on the Queue in this program:

    1. Display the whole queue
    2. Peek the front of the queue
    3. Enqueue an integer into the queue
    4. Dequeue an integer from the queue
    5. Empty out the entire queue
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Maximum size of the queue
#define MAX_SIZE 5

//Helper functions:

void showMenu();
bool isEmpty();
bool isFull();

//Main queue operation functions:

void enqueue(int x);

void dequeue();
void clearQueue();

void peek();
void displayQueue();

//Required declarations for queues.

int queue[MAX_SIZE];
int front = 0;
int rear = -1;
int size = 0; //Not really essential but makes getting size easier.

int main() {

    printf("\n");
    printf("***************************************************\n");
    printf("*                                                 *\n");
    printf("*            Welcome to Queues Program            *\n");
    printf("*                                                 *\n");
    printf("***************************************************\n");


    int choice, num;

    while(true) {
        
        showMenu();
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                displayQueue();
                break;

            case 2:
                peek();
                break;

            case 3:
                printf("Enter number to be enqueued: ");
                scanf("%d", &num);
                enqueue(num);
                break;

            case 4:
                dequeue();
                break;

            case 5:
                clearQueue();
                break;

            case 6:
                printf("\n");
                printf("**************************************************\n");
                printf("*                                                *\n");
                printf("*                   Goodbye!                     *\n");
                printf("*         Thank you for using the queue!         *\n");
                printf("*                                                *\n");
                printf("**************************************************\n\n");

                exit(0);
                break;

            default: printf("\nInvalid option! Try again.\n");
        }
    }

    return 0;    
}

//Checks whether the queue is empty or not. Returns true if empty, false if not.
bool isEmpty() {
    return (size == 0);
}

//Checks whether the queue is full or not. Returns true if full, false if not.
bool isFull() {
    return (size == MAX_SIZE);
}

//Enqueues an element into the rear of the queue.
void enqueue(int x) {
    if(isFull())
        printf("\nQueue overflow.\n");
    else {

        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = x;
        size++;
        printf("\nEnqueued %d into the queue succesfully.\n", x);
    }
}

//Dequeues an element from front of the queue.
void dequeue() {
    if(isEmpty())
        printf("\nQueue underflow.\n");
    else {
        front = (front + 1) % MAX_SIZE;
        size--;
        printf("\nDequeued succesfully.\n");
    }
}

//Empties out the queue.
void clearQueue() {
    if(isEmpty()) {
        printf("\nQueue is already empty.\n");
        return;
    }
    front = -1;
    rear = -1;
    size = 0;

    printf("\nQueue succesfully emptied.\n");
}

//Displays the element present at the front of the queue.
void peek() {
    if(isEmpty()) {
        printf("\nQueue is empty. Nothing to peek.\n");
        return;
    }
    printf("\n%d\n", queue[front]);
}

//Displays the entire queue.
void displayQueue() {
    if(isEmpty()) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nCurrent Queue: ");
    for (int count = 0, i = front; count < size; count++, i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

//Shows user menu.
void showMenu() {

    printf("\n____________________________________________________________");
    printf("\n\nChoose one - ");
    printf("\n\n\n\t1. DISPLAY the queue");
    printf("\n\n\t2. PEEK the queue");
    printf("\n\n\t3. ENQUEUE into the queue");
    printf("\n\n\t4. DEQUEUE from the queue");
    printf("\n\n\t5. CLEAR the queue");
    printf("\n\n\t6. EXIT");

    printf("\n\nEnter the operation you'd like to perform [1-6] : ");
}