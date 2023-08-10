#include <stdio.h>
#include <stdlib.h>

#define COUNT 5

struct node {
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;

struct node* newNode(int);
void print2D_Util(struct node*, int);
void print2D(struct node*);

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
    print2D(root);

return 0;
}

struct node* newNode(int x) {

    struct node* new = malloc(sizeof(struct node));

    new->data = x;
    new->left = new->right = NULL;

    return new;
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