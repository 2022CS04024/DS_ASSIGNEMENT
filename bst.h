#ifndef __BST_H__
#define __BST_H__
typedef struct tree_node {
    int data;
    struct tree_node * left;
    struct tree_node * right;
    struct tree_node * parent;
} tree_node;

void bstCreateRoot(tree_node** root);
void inorder(tree_node *root);
void preorder(tree_node *root);
void postorder(tree_node *root);
void bstCleanup(tree_node** root);
void bstInsert(tree_node ** root, int data);
double timedBSTInsert(tree_node **root,int data);
bool bstDelete(tree_node **root,int data);
double timedBSTDelete(tree_node **root,int data);
bool bstSearch(tree_node *root,int data);
double timedBSTSearch(tree_node *root,int data);
int bstInsertArray(tree_node **root,int data[],int n);
double timedBSTInsertArray(tree_node **root,int data[],int n);

#endif
