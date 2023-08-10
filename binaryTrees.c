#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;

struct queue_node {
    struct node* ptr;
    struct queue_node* next;
};

struct Queue {
    struct queue_node* front;
    struct queue_node* rear;
};

struct node* newNode(int);
void display(struct node*);
struct Queue* createQueue();
void enqueue(struct Queue*, struct node*);
void dequeue(struct Queue*);

int main() {

    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
 
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);

    display(root);

    return 0;
}

struct node* newNode(int x) {

    struct node* new = malloc(sizeof(struct node));

    new->data = x;
    new->left = new->right = NULL;

    return new;
}

void inorder(struct node* root) {

    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d -> ", root->data);

    inorder(root->right);
}

void preorder(struct node* root) {

    if(root == NULL)
        return;

    printf("%d -> ", root->data);

    preorder(root->left);

    preorder(root->right);
}

void postorder(struct node* root) {

    if(root == NULL)
        return;

    postorder(root->left);

    postorder(root->right);

    printf("%d -> ", root->data);
}

struct Queue* createQueue() {
    struct Queue *queue = malloc(sizeof(struct Queue));

    queue->front = queue->rear = NULL;

    return queue;
}

void enqueue(struct Queue* queue, struct node* root) {

    struct queue_node* new = malloc(sizeof(struct queue_node));
    new->next = NULL;
    new->ptr = root;

    if(queue->rear == NULL) {
        queue->front = queue->rear = new;
        return;
    }

    queue->rear->next = new;
    queue->rear = new;
}

void dequeue(struct Queue* queue) {

    if(queue->front == NULL)
        return;
    
    struct queue_node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
}

void moveNext(struct Queue* queue, struct node* root) {

    struct queue_node* temp = queue->front;

    while(temp) {
        printf("%d ", temp->ptr->data);

        if(temp->ptr->left != NULL)
            enqueue(queue, temp->ptr->left);
        if(temp->ptr->right != NULL)
            enqueue(queue, temp->ptr->right);

        dequeue(queue);
        temp = temp->next;
    }
    printf("\n");

    free(temp);
}

void levelorder(struct node* root) {

    if(root == NULL)
        return; 

    struct Queue* queue = createQueue();

    enqueue(queue, root);

    while(queue->front != NULL)
        moveNext(queue, root);
}

void display(struct node* root) {

    int choice;
    printf("Choose traversal method:\n");
    printf("1. Inorder\n2. Preoder\n3. Postorder\n4. Level order\n: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            inorder(root);
            break;

        case 2:
            preorder(root);
            break;

        case 3:
            postorder(root);
            break;

        case 4:
            levelorder(root);
            break;

        default: printf("Invalid choice.\n");
    }
}