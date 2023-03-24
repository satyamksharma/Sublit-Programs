/*
Problem solving 1

Given a set of N keys construct red black tree and print the postorder traversal sequence of nodes and black height of the tree

Input Format

5// number of keys
10 20 30 40 50// keys

Output Format

10 30 50 40 20// postorder traversal
2// black height of tree external nodes are not counted height is length of longest path from root to any leaf node
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    char color;
    struct node *left, *right, *parent;
};

struct node *newNode(int key, char color) {
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->key = key;
    n->color = color;
    n->left = n->right = n->parent = NULL;
    return n;
}

void rotateLeft(struct node **root, struct node *x) {
    struct node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rotateRight(struct node **root, struct node *x) {
    struct node *y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}

void fixViolation(struct node **root, struct node *n) {
    while (n != *root && n->parent->color == 'R') {
        if (n->parent == n->parent->parent->left) {
            struct node *y = n->parent->parent->right;
            if (y != NULL && y->color == 'R') {
                n->parent->color = 'B';
                y->color = 'B';
                n->parent->parent->color = 'R';
                n = n->parent->parent;
            } else {
                if (n == n->parent->right) {
                    n = n->parent;
                    rotateLeft(root, n);
                }
                n->parent->color = 'B';
                n->parent->parent->color = 'R';
                rotateRight(root, n->parent->parent);
            }
        } else {
            struct node *y = n->parent->parent->left;
            if (y != NULL && y->color == 'R') {
                n->parent->color = 'B';
                y->color = 'B';
                n->parent->parent->color = 'R';
                n = n->parent->parent;
            } else {
                if (n == n->parent->left) {
                    n = n->parent;
                    rotateRight(root, n);
                }
                n->parent->color = 'B';
                n->parent->parent->color = 'R';
                rotateLeft(root, n->parent->parent);
            }
        }
    }
    (*root)->color = 'B';
}

void insert(struct node **root, int key) {
struct node *n = newNode(key, 'R');
struct node *parent = NULL;
struct node *current = *root;
while (current != NULL) {
parent = current;
if (key < current->key)
current = current->left;
else
current = current->right;
}
n->parent = parent;
if (parent == NULL)
*root = n;
else if (key < parent->key)
parent->left = n;
else
parent->right = n;
fixViolation(root, n);
}

void printPostorder(struct node *root) {
if (root != NULL) {
printPostorder(root->left);
printPostorder(root->right);
printf("%d ", root->key);
}
}

int blackHeight(struct node *root) {
int bh = 0;
struct node *n = root;
while (n != NULL) {
if (n->color == 'B')
bh++;
n = n->left;
}
return bh;
}

int main() {
int n, key;
struct node *root = NULL;
scanf("%d", &n);
for (int i = 0; i < n; i++) {
scanf("%d", &key);
insert(&root, key);
}
printPostorder(root);
printf("\n%d\n", blackHeight(root));
return 0;
}
