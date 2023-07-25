#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//All indexes start from 0

struct node {
    int data;
    struct node *next;
};

const char* setSuffixByNumber(int);
int sizeOfLinkedList(struct node *);
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
void showMenu();
bool isEmpty(struct node *);

struct node *head = NULL;

int main() {

    printf("\n\t\tHey mf");

    int choice = 1, data, index, insertChoice, deleteChoice, searchChoice;

    while(choice) {
        showMenu();
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                display();
                break;
            
            case 2:
                printf("\nChoose one option - \n\n\t1. Insert at start\n\t2. Insert at end\n\t3. Insert at any other position\n\nEnter[1-3]: ");
                scanf("%d", &insertChoice);

                switch(insertChoice) {
                    
                    case 1:
                        printf("Enter data: ");
                        scanf("%d", &data);

                        printf("List before insertion: ");
                        display();

                        insertAtStart(data);

                        printf("List after insertion: ");
                        display();

                        break;
                    
                    case 2:
                        printf("Enter data: ");
                        scanf("%d", &data);

                        printf("List before insertion: ");
                        display();

                        insertAtEnd(data);

                        printf("List after insertion: ");
                        display();

                        break;

                    case 3:
                        printf("Enter data: ");
                        scanf("%d", &data);
                        printf("Enter position of insertion [Index starts from 0]: ");
                        scanf("%d", &index);

                        printf("List before insertion: ");
                        display();

                        insertAfter_nthNode(index, data);

                        printf("List after insertion: ");
                        display();
                        
                        break;

                    default: printf("Invalid choice!\n");
                }
                break;
            
            case 3:
                printf("\nChoose one option - \n\n\t1. Delete first element\n\t2. Delete last element\n\t3. Delete at any other position\n\nEnter[1-3]: ");
                scanf("%d", &deleteChoice);

                switch(deleteChoice) {
                    
                    case 1:
                        printf("List before deletion: ");
                        display();

                        deleteAtStart();

                        printf("Successfully deleted element!\nList after deletion: ");
                        display();

                        break;
                    
                    case 2:
                        printf("List before deletion: ");
                        display();

                        deleteAtEnd();

                        printf("Successfully deleted element!\nList after deletion: ");
                        display();

                        break;

                    case 3:
                        printf("Enter position of deletion [Index starts from 0]: ");
                        scanf("%d", &index);

                        printf("List before deletion: ");
                        display();

                        delete_nthNode(index);

                        printf("Successfully deleted element!\nList after deletion: ");
                        display();

                        break;
                    
                    default: printf("Invalid choice!\n");
                }
                break;

            case 4:
                printf("\nChoose one option - \n\n\t1. Searching by value\n\t2. Searching by index\n\nEnter[1-2]: ");
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
                printf("Nice, now fk off.\n");
                exit(0);
                break;

            default: printf("Invlid option!\n");
        }
    }

return 0;
}

bool isEmpty(struct node *start) {
    if(start == NULL)
        return true;
    else return false;
}

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

int sizeOfLinkedList(struct node *start) {
    int n = 0;
    struct node *temp = start;

    while(temp) {
        temp = temp->next;
        n++;
    }

    return n;
}

void insertAtStart(int x) {
    struct node *new = malloc(sizeof(struct node));

    new->data = x;
    new->next = head;
    head = new;
}

void insertAfter_nthNode(int n, int x) {

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

void insertAtEnd(int x) {
    struct node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    struct node *new = malloc(sizeof(struct node));

    new->data = x;
    temp->next = new;
}

void deleteAtStart() {
    head = head->next;
}

void delete_nthNode(int n) {
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
}

void deleteAtEnd() {
    struct node *temp = head->next;
    struct node *prev = head;

    while(temp->next != NULL) {
        temp = temp->next;
        prev = prev->next;
    }
    prev->next = NULL;
}

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

void sortLinkedList(struct node *start) {
    //This function uses bubble sort method to sort the given linked list
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

void display() {

    if(isEmpty(head)) {
        printf("\nCannot display, list is empty.\n");
        return;
    }

    struct node *temp = head;

    while(temp->next != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void showMenu() {
   printf("\n\n____________________________________________________________");
   printf("\n\nChoose one - ");
   printf("\n\n\n\t1. DISPLAY the list");
   printf("\n\n\t2. INSERTING a node into the list");
   printf("\n\n\t3. DELETING a node from the list");
   printf("\n\n\t4. SEARCHING for an element in the list");
   printf("\n\n\t5. SORTING the list");
   printf("\n\n\t6. EXIT");

   printf("\n\nEnter the operation you'd like to perform [1-6] : ");
}