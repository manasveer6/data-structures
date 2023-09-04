#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define COUNT 10

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
    int size;
};

struct node* newNode(int);
void display(struct node*);
struct Queue* createQueue();
void enqueue(struct Queue*, struct node*);
void dequeue(struct Queue*);
int height(struct node*);

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

    printf("Height: %d\n", height(root));

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

int height(struct node* root) {

    if(root == NULL)
        return 0;
    else {

    int lheight = height(root->left);
    int rheight = height(root->right);

    if(lheight > rheight)
        return (lheight + 1);
    else return (rheight + 1);
    }
}

struct Queue* createQueue() {
    struct Queue *queue = malloc(sizeof(struct Queue));

    queue->front = queue->rear = NULL;
    queue->size = 0;

    return queue;
}

void enqueue(struct Queue* queue, struct node* root) {

    struct queue_node* new = malloc(sizeof(struct queue_node));
    new->next = NULL;
    new->ptr = root;

    if(queue->rear == NULL || queue->front == NULL) {
        queue->front = queue->rear = new;
        queue->size = 1;
        return;
    }

    queue->rear->next = new;
    queue->rear = new;
    (queue->size)++;
}

void dequeue(struct Queue* queue) {

    if(queue->front == NULL) {
        queue->size = 0;
        return;
    }
    
    struct queue_node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    (queue->size)--;
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

void print2D_Util(struct node* root, int space) {

    if(root == NULL)
        return;

    space += COUNT;

    print2D_Util(root->right, space);

    printf("\n");
    for(int i = 0; i < space - COUNT; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    print2D_Util(root->left, space);

}

void print2D(struct node* root) {
    print2D_Util(root, 0);
}

void display(struct node* root) {

    int choice;
    printf("Choose traversal method:\n");
    printf("1. Inorder\n2. Preoder\n3. Postorder\n4. Level order\n5. 2-Dimensional\n: ");
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

        case 5:
            print2D(root);
            break;

        default: printf("Invalid choice.\n");
    }
}