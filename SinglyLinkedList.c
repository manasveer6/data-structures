/*
A program on implementation of Singly Linked List and various operations performed on it.
 
List of operations that can be performed on the Linked List in this program:

    1. Display the whole list
    2. Display the whole list in reverse order
    3. Insert an element at the start of the list
    4. Insert an element in a specific position in the list (Positioned relative to nth node instead of position)
    5. Insert an element at the end of the list
    6. Delete an element at the start of the list
    7. Delete an element present at a specified position
    8. Delete an element at the end of the list
    9. Reverse the list
    10. Sort the list in ascending order (I used bubble sort for now)

    All indexes and position counts start from 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Node declaration
struct node {
    int data;
    struct node *next;
};

//Helper functions:

const char* setSuffixByNumber(int);
int sizeOfLinkedList(struct node *);
void showMenu();
bool isEmpty(struct node *);

//Main linked list operation functions:

void insertAtStart(int);
void insertAfter_nthNode(int, int);
void insertAtEnd(int);

void deleteAtStart();
void delete_nthNode(int);
void deleteAtEnd();

void findNodeWithData(int);
void findNodeWithIndex(int);

void sortLinkedList(struct node *);

void display();
void displayInReverse(struct node *);

void reverseList(struct node *);


//Head pointer, always points to the first node/element of the Linked List.
struct node *head = NULL;

bool success;

int main() {

    printf("\n");
    printf("***************************************************************\n");
    printf("*                                                             *\n");
    printf("*            Welcome to Singly Linked List Program            *\n");
    printf("*                                                             *\n");
    printf("***************************************************************\n");

    int choice = 1, data, index, insertChoice, deleteChoice, searchChoice;

    while(true) {
        
        success = false;
        showMenu();
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                display();
                break;
            
            case 2:
                printf("\nChoose one option - \n\n\t1. Insert at start\n\t2. Insert at end\n\t3. Insert at any other position\n\nEnter [1-3]: ");
                scanf("%d", &insertChoice);

                switch(insertChoice) {
                    
                    case 1:
                        printf("Enter data: ");
                        scanf("%d", &data);

                        printf("\nList before insertion: ");
                        display();

                        insertAtStart(data);

                        printf("\nList after insertion: ");
                        display();

                        break;
                    
                    case 2:
                        printf("Enter data: ");
                        scanf("%d", &data);

                        printf("\nList before insertion: ");
                        display();

                        insertAtEnd(data);

                        printf("\nList after insertion: ");
                        display();

                        break;

                    case 3:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        printf("Enter position of insertion. New element will be added after the node present at given position [Index starts from 0]: ");
                        scanf("%d", &index);

                        printf("\nList before insertion: ");
                        display();

                        insertAfter_nthNode(index, data);

                        printf("\nList after insertion: ");
                        display();
                        
                        break;

                    default: printf("Invalid choice!\n");
                }
                break;
            
            case 3:
                printf("\nChoose one option - \n\n\t1. Delete first element\n\t2. Delete last element\n\t3. Delete at any other position\n\nEnter [1-3]: ");
                scanf("%d", &deleteChoice);

                switch(deleteChoice) {
                    
                    case 1:

                        printf("\nList before deletion: ");
                        display();

                        deleteAtStart();

                        if(success) {
                            printf("\nSuccessfully deleted element! List after deletion: ");
                            display();
                        }

                        break;
                    
                    case 2:

                        printf("\nList before deletion: ");
                        display();

                        deleteAtEnd();

                        if(success) {
                            printf("\nSuccessfully deleted element! List after deletion: ");
                            display();
                        }

                        break;

                    case 3:

                        printf("Enter position of deletion [Index starts from 0]: ");
                        scanf("%d", &index);

                        printf("\nList before deletion: ");
                        display();

                        delete_nthNode(index);

                        if(success) {
                            printf("\nSuccessfully deleted element! List after deletion: ");
                            display();
                        }

                        break;
                    
                    default: printf("Invalid choice!\n");
                }
                break;

            case 4:
                printf("\nChoose one option - \n\n\t1. Searching by value\n\t2. Searching by index\n\nEnter [1-2]: ");
                scanf("%d", &searchChoice);

                switch(searchChoice) {

                    case 1:
                        printf("Enter data to be searched: ");
                        scanf("%d", &data);

                        findNodeWithData(data);

                        break;

                    case 2:
                        printf("Enter position to be searched [Index starts from 0]: ");
                        scanf("%d", &index);

                        findNodeWithIndex(index);

                        break;
                }
                break;

            case 5:
                if(isEmpty(head)) {
                    printf("\nCannot sort because list is empty.\n");
                    break;
                }
                printf("List before sorting: ");
                display();

                sortLinkedList(head);

                printf("Successfully sorted Linked List!\nList after sorting: ");
                display();
                break;

            case 6:
                displayInReverse(head);
                break;

            case 7:
                reverseList(head);
                display();
                break;

            case 8:
                printf("\n");
                printf("*********************************************************\n");
                printf("*                                                       *\n");
                printf("*                      Goodbye!                         *\n");
                printf("*         Thank you for using the Linked List!          *\n");
                printf("*                                                       *\n");
                printf("*********************************************************\n\n");
                exit(0);
                break;

            default: printf("Invlid option!\n");
        }
    }

return 0;
}

//Checks whether the list is empty or not. Returns true if empty, false if not.
bool isEmpty(struct node *start) {
    if(start == NULL)
        return true;
    else return false;
}

//Sets the suffix for a given number. Ex: 1st, 2nd, 3rd, 4th, etc. Made purely for aesthetic purposes.
const char* setSuffixByNumber(int n) {
    int units_digit = n%10;
    static char str[3];
    switch(units_digit) {
        case 1: strcpy(str, "st");
                break;
        case 2: strcpy(str, "nd");
                break;
        case 3: strcpy(str, "rd");
                break;
        default: strcpy(str, "th");
    }
    return str;
}

//Calculates size of the Linked List i.e. total number of nodes/elements.
int sizeOfLinkedList(struct node *start) {
    int n = 0;
    struct node *temp = start;

    while(temp) {
        temp = temp->next;
        n++;
    }

    return n;
}

//Inserts a node/element at the start of the Linked List.
void insertAtStart(int x) {
    struct node *new = malloc(sizeof(struct node));

    new->data = x;
    new->next = head;
    head = new;
}

//Inserts a node/element in the middle of a Linked List, position is given relative to another node, 
//i.e new node is inserted after the node found at the given position.
void insertAfter_nthNode(int n, int x) {

    if(head == NULL) {
        printf("\nInserting node at index 0 because list is empty.\n");
        insertAtStart(x);
        return;
    }

    struct node *temp = head->next;
    struct node *prev = head;
    for(int i=0; i<n; i++) {
        if(temp == NULL) {
            printf("Could not insert %d as %d%s node doesn't exist.\n", x, n, setSuffixByNumber(n));
            return;
        }
        temp = temp->next;
        prev = prev->next;
    }

    struct node *new = malloc(sizeof(struct node));
    new->data = x;
    new->next = temp;
    prev->next = new;
}

//Inserts a node/element at the end of the Linked List.
void insertAtEnd(int x) {
    struct node *temp = head;
    struct node *new = malloc(sizeof(struct node));

    new->data = x;
    new->next = NULL;

    if(head == NULL) {
        head = new;
        return;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new;
}

//Deletes the first node of the Linked List.
void deleteAtStart() {

    if(isEmpty(head)) {
        printf("Cannot delete. List is empty.\n");
        return;
    }

    head = head->next;

    success = true;
}

//Deletes the nth element of the Linked list.
void delete_nthNode(int n) {

    if (isEmpty(head)) {
        printf("Cannot delete. List is empty.\n");
        return;
    }

   int size = sizeOfLinkedList(head);

    if(n > size-1 || n < 0) {
        printf("Index out of bounds, try again between [%d, %d]\n", 0, size-1);
        return;
    }

    n--;

    struct node *temp = head->next;
    struct node *prev = head;

    for(int i=0; i<n; i++) {
        if(temp == NULL) {
            printf("%d%s node doesn't exist.\n", n, setSuffixByNumber(n));
            return;
        }
        temp = temp->next;
        prev = prev->next;
    }

    prev->next = temp->next;

    success = true;
}

//Deletes the last element of the Linked List.
void deleteAtEnd() {

    if (isEmpty(head)) {
        printf("Cannot delete. List is empty.\n");
        return;
    }
    
    if (head->next == NULL) {
        // There is only one node in the list.
        free(head);
        head = NULL; // Set head to NULL to indicate an empty list.
        return;
    }

    struct node *temp = head->next;
    struct node *prev = head;

    while(temp->next != NULL) {
        temp = temp->next;
        prev = prev->next;
    }
    prev->next = NULL;

    success = true;
}

//Finds the node which contains the given data.
void findNodeWithData(int x) {
    struct node *temp = head;
    int position = 0;

    while(temp) {
        if(temp->data == x){
            printf("%d found at %d%s node.\n", x, position, setSuffixByNumber(position));
            return;
        }
        position++;
        temp = temp->next;
    }
        
    printf("%d not found.\n", x);
}

//Finds the node which is located at the given index/position.
void findNodeWithIndex(int position) {
    if(position < 0) {
        printf("Invalid index, list positions start from 0.\n");
        return;
    }
    struct node *temp = head;

    for(int i=0; i<position; i++) {
        if(temp->next == NULL) {
            printf("%d%s node not found.\n", position, setSuffixByNumber(position));
            return;
        }
        temp = temp->next;
    }

    printf("Data at %d%s node is: %d\n", position, setSuffixByNumber(position), temp->data);
}

//Sorts the Linked List in ascending order using bubble sort algorithm.
void sortLinkedList(struct node *start) {
    int size = sizeOfLinkedList(start);

    struct node *temp = start->next;
    struct node *prev = start;
    int buffer;

    for(int i=0; i<size; i++) {
        for(int j=0; j<size-i-1; prev = prev->next, temp = temp->next, j++) {
            if(prev->data > temp->data) {
                buffer = prev->data;
                prev->data = temp->data;
                temp->data = buffer;
            }
        }
        temp = start->next;
        prev = start;
    }
}

//Displays each element of the Linked List.
void display() {

    if(isEmpty(head)) {
        printf("\nList is empty.\n");
        return;
    }

    struct node *temp = head;

    printf("\n");
    while(temp->next != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

//DIsplays each element of the Linked List but in reverse order.
void displayInReverse(struct node *temp) {

    if(isEmpty(head)) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\n");
    if(temp->next != NULL) {
        displayInReverse(temp->next);
    }
    printf("%d", temp->data);

    if(temp != head) {
        printf(" -> ");
    }
}

//Reverses the Linked List.
void reverseList(struct node *temp) {
    //Reversing using recursion method but this was not efficient.
    // if(temp->next != NULL) {
    //     reverseList(temp->next);
    // }
    //
    // insertAtEnd(temp->data);
    // if(temp->next->next == NULL) {
    //     head = temp->next;
    // }

    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

//Shows user menu.
void showMenu() {

    printf("\n____________________________________________________________");
    printf("\n\nChoose one - ");
    printf("\n\n\n\t1. DISPLAY the list");
    printf("\n\n\t2. INSERTING a node into the list");
    printf("\n\n\t3. DELETING a node from the list");
    printf("\n\n\t4. SEARCHING for an element in the list");
    printf("\n\n\t5. SORTING the list");
    printf("\n\n\t6. DISPLAY the list in reverse");
    printf("\n\n\t7. REVERSE the list");
    printf("\n\n\t8. EXIT");

    printf("\n\nEnter the operation you'd like to perform [1-8] : ");
}