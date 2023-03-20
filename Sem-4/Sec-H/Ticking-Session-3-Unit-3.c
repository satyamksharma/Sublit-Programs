/* Given a set of N keys construct red black tree and print the postorder traversal sequence of nodes and black height of the tree

Input Format

5// number of keys
10 20 30 40 50// keys

Output Format

10 30 50 40 20// postorder traversal
2// black height of tree external nodes are not counted height is length of longest path from root to any leaf node

Testcase 1
Input

5
10 20 30 40 50
Output

10 30 50 40 20 
2 */

//CODE------->
#include<stdio.h>
#include<stdlib.h>

typedef enum { RED, BLACK } nodeColor;

typedef struct Node {
    int key;
    nodeColor color;
    struct Node *left, *right, *parent;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void rotateLeft(Node **root, Node *x) {
    Node *y = x->right;
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

void rotateRight(Node **root, Node *x) {
    Node *y = x->left;
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

void fix(Node **root, Node *z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node *y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(root, z->parent->parent);
            }
        }
        else {
            Node *y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void insert(Node **root, int key) {
    Node *newNode = createNode(key);
    Node *x = *root;
Node *y = NULL;

while (x != NULL) {
    y = x;
    if (newNode->key < x->key)
        x = x->left;
    else
        x = x->right;
}

newNode->parent = y;

if (y == NULL)
    *root = newNode;
else if (newNode->key < y->key)
    y->left = newNode;
else
    y->right = newNode;

fix(root, newNode);
}

void postorder(Node *root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->key);
}
}

int blackHeight(Node *root) {
if (root == NULL)
return 0;
int leftBlackHeight = blackHeight(root->left);
int rightBlackHeight = blackHeight(root->right);
return root->color == BLACK ? 1 + leftBlackHeight : leftBlackHeight;
}

int main() {
int n;
scanf("%d", &n);
int *keys = (int*)malloc(n * sizeof(int));
for (int i = 0; i < n; i++) {
    scanf("%d", &keys[i]);
}

Node *root = NULL;
for (int i = 0; i < n; i++) {
    insert(&root, keys[i]);
}

postorder(root);
printf("\n");

int bh = blackHeight(root);
printf("%d", bh);

return 0;
}