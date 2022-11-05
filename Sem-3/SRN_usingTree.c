/*Create a Binary Search Tree to store SRNs of students where SRNs are strings. Implement the insert function of the BST by comparing strings.

You will have to implement these other functions also:
● A function to print all SRNs in ascending order
● A function to search an SRN

A Binary Search Tree is a node-based non-linear data structure that stores values hierarchically which has the following properties:
● The left subtree of a node contains only nodes with keys lesser than the node’s key.
● The right subtree of a node contains only nodes with keys greater than the node’s key.
● The left and the right subtree of a node will be binary search trees themselves.

Your task is to implement an insert function, a search function, and a function that prints values in ascending order.

You are required to implement the following tree operations as a part of this lab exercise:
1) void insert(char*key, struct node**leaf, Compare cmp);
- This function inserts the string “key” to its appropriate position in the tree.
- It is mandatory in this function that you update check as -1 in case you encounter a duplicate insertion.
- There can be multiple duplicate insertions, you just have to update the check as - 1 every time you see a duplicate value i.e. if a value has been duplicated once, the check will be -1, and even if there are two duplicate values, the check will be -1, so write the code accordingly.

2) void asc_order(struct node*root)
- This function prints the values stored in trees in ascending order.

3) void search(char*key,struct node*leaf,Compare cmp)
- This function is used to search for a key in the BST, set the found variable to 1 if found, else return;

The other string operations you’re supposed to implement are my_strlen, my_strcmp, my_strcpy

You are supposed to use the code provided to you via the boilerplate code.

The skeleton of the tree is provided to you via the “struct” so you need not code that.

//struct for node
struct node {
    char *value;
    struct node *p_left;
    struct node *p_right;
};

USING THE BOILERPLATE CODE PROVIDED BY US IS MANDATORY.
YOU WILL FAIL MOST OF THE TEST CASES IN CASE YOU FAIL TO DO SO.

Input Format

Each test case starts with a digit ‘n’, this n denotes the number of values in the tree N is followed by the n strings to be inserted in the tree.
After the n strings, one more string is scanned to see if the string is present in the tree or not.

Output Format

The values stored in the tree are printed in ascending order, followed by an integer to check if there have been any duplicate insertions or not, i.e. set check to -1 if there is ANY duplicate insertion, and 0 if not followed by the value returned by search i.e. 0 if the scanned element is not present in the tree and 1 if the element is present.

You don’t need to print anything as a part of this lab exercise. Make sure to remove all the printfs and scanfs used for debugging.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check=0;
int found=0;
//struct for node
typedef struct node {
    char *value;            // all void* types replaced by char*
    struct node *p_left;
    struct node *p_right;
}node;

int isempty(node *t){
    return t==NULL;
}

node *createnode(char *s){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->value=s;
    newnode->p_left=NULL;
    newnode->p_right=NULL;
    return newnode;
}

int my_strlen(char * s)
{
    return strlen(s);
}

void my_strcpy(char *str1, char *str2)//str2 is source, str1 is dest
{
    strcpy(str1,str2);
}

int my_strcmp(const char *a, const char *b)
{
    char a1[5];
    char b1[5];
    int cnt = 10;
    for(int i=0; i<3; i++)
    {
        a1[i] = a[cnt];
        b1[i] = b[cnt];
        cnt++;
    }
    a1[3] = '\0';
    b1[3] = '\0';
    int an = atoi(a1);
    int bn = atoi(b1);
    if(an==bn)
    {
        check = -1;
        return 0;
    }
    else if(an<bn)
    {
        return -1;
    }
    else if(an>bn)
    {
        return 1;
    }

}

//inserts elements into the tree
void insert(char* key, struct node **leaf)
{
    node *nn = *leaf;
    if(isempty(nn))
    {
        *leaf = createnode(key);
    }
    else if(my_strcmp(key,nn->value)==0)
    {
        check = -1;
    }
    else if(my_strcmp(key,nn->value)<0)
    {
        insert(key,&nn->p_left);
    }
    else if(my_strcmp(key,nn->value)>0)
    {
        insert(key,&nn->p_right);
    }

}


//recursive function to print out the tree inorder
void asc_order(struct node *root)
{
    if(root == NULL)
        return;
    asc_order(root->p_left);
    printf("%s\n",root->value);
    asc_order(root->p_right);
}


//searches elements in the tree
void search(char* key, struct node* leaf)  // no need for **
{
    if(leaf==NULL)
        return;
    search(key,leaf->p_left);
    if(strcmp(key,leaf->value)==0)
    {
        found=1;
    }
    search(key,leaf->p_right);
}



int main()
{
    struct node *p_root = NULL;
    char *value;
    size_t malloc_size = 100;
    int size;
    int temp=100;
    scanf("%d",&size);
    int i;
    //reading the input and inserting in the tree
    char *srn[size];
    for (i = 0; i < size; i++)
    {
        srn[i] = malloc(malloc_size * sizeof(char));
        scanf("%99s", srn[i]);
        insert(srn[i],&p_root);
    }
    char searchname[temp];
    scanf("%s",searchname);

    //checking inorder print
    asc_order(p_root);

    //checking for 1 or more duplicate insertions
    printf("%d\n",check);

    //searching a string in the tree
    search(searchname,p_root);
    printf("%d\n",found);
    return 0;
}
