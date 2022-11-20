/*
Display the words in a trie in lexicographic order

A specific key from a collection can be sorted and searched for using the k-ary search tree type called "Trie." Search complexity can be reduced to the ideal level using Trie.

A trie is an alphabet-letter-storing data structure that resembles a tree. Words and strings can be extracted from the structure by travelling down a branch path of the tree by organising the nodes in a specific way.

In this Lab we will print the words in the trie in lexicographic order and implement it using DFS traversal technique.


You are required to implement the following function:
Void insert(struct TrieNode *root , char *key);
A function that traverses through the trie and inserts the keys of the words into it . You need not call the function anywhere it is already being called in the main function.
[NOTE : Same words can be repeated Multiple Times but only one copy will exist in the Trie and will be only displayed once while printing].
Void dfs_word(struct TrieNode *root , char* word , int* plent);
A function that recursively traverses through the trie . The parameter word will append the current letter at present index and will print the word if it's a leaf node. plent is the length of the current word that allows us to keep track of the length of the word.
Functions to initialise Trie have already been implemented in the boilerplate code. 
USING THE BOILERPLATE CODE PROVIDED IS MANDATORY.

Input Format

First line of input consists of an integer N, representing the number of words to be inserted into the Trie.
The following N lines represent the words that will be inserted
Character of the words will be ‘a’ to ‘z’ only

Output Format

Lexicographically ordered words in N lines. Using the display method  

Testcase 1
Input

3
bimbo
jumbo
bamboo
Output

bamboo
bimbo
jumbo
Testcase 2
Input

8
marco
a
ant
p
marc
polo
any
mon
Output

a
ant
any
marc
marco
mon
p
polo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE (255)
#define ALPHABET_SIZE (26)

struct TrieNode
{

    struct TrieNode *children[ALPHABET_SIZE]; // pointer Array
    bool isEndOfWord;                         // denotes end of the word
};

struct TrieNode *getNode()
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        pNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}
int my_strlen(char *string)
{
    int i;
    for(i=1;string[i]!=0;i++)
    return i;
}
void insert(struct TrieNode *root, char *key)
{
    struct TrieNode *cur=root;
    int i,index;
    for(i=0;key[i]!=0;i++){
        index = key[i]-'a';
        if(cur->children[index]==NULL)
        cur->children[index] = getNode();
        cur = cur->children[index];
    }
    cur->isEndOfWord = true;
}


// Recursive Function to Print in Lexicographic order using DFS
void dfs_word(struct TrieNode *root, char *word, int *plent)
{
    int i,j;
    for(i=0;i<ALPHABET_SIZE;i++){
        if(root->children[i]!=NULL){
            word[(*plent)++] = i;
            if(root->children[i]->isEndOfWord==true){
                for(j=0;j<(*plent);j++) printf("%c",(word[j]+'a'));
                printf("\n");
            }
            dfs_word(root->children[i],word,plent);
        }
    }
    (*plent)--;
    return;
}


// Function to Display
void display(struct TrieNode *root)
{

    char word[MAXSIZE] = "";
    int length = 0;
    dfs_word(root, word, &length);
}


int main()
{
    int number_of_ele, i;

    // Number of input elements
    scanf("%d", &number_of_ele);

    // initialising root node
    struct TrieNode *root = getNode();
    char input[MAXSIZE][MAXSIZE];

    
    for (i = 0; i < number_of_ele; i++)
    {
        scanf("%s\n", input[i]);
    }

    // Inserting Into the Trie
    for (int i = 0; i < number_of_ele; i++)
    {

        insert(root, input[i]);
    }

    display(root);
    return 0;
}