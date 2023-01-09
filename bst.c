#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "./bst.h"
clock_t start, end;
double cpu_time_used;
tree_node *root = NULL;

void bstCreateRoot(tree_node** root){
    *root = (tree_node*) malloc(sizeof(tree_node));
}
void inorder(tree_node *root){
    //try printing and traversing only if current node is not null
    if (root!=NULL){
        //traverse left subtree
        inorder(root->left);
        //print current node
        printf("%d, ",root->data);
        //traverse right subtree
        inorder(root->right);
    }
}
void preorder(tree_node *root){
    //try printing and traversing only if current node is not null
    if (root!=NULL){
        //print current node
        printf("%d, ",root->data);
        //traverse left subtree
        preorder(root->left);
        //traverse right subtree
        preorder(root->right);
    }
}
void postorder(tree_node *root){
    //try printing and traversing only if current node is not null
    if (root!=NULL){
        //traverse left subtree
        postorder(root->left);
        postorder(root->right);
        //print current node
        printf("%d, ",root->data);
    }
}
void bstCleanup(tree_node** root){
    if(*root==NULL){
        return;
    }
    bstCleanup(&((*root)->left));
    bstCleanup(&((*root)->right));
    free(*root);
    *root = NULL;
}
void bstInsert(tree_node ** root, int data){
    // create new node for new data by allocating space in heap
    tree_node * newNode = (tree_node*) malloc(sizeof(tree_node));
    // store data in node
    newNode->data = data;
    // set all pointers in new node to null
    newNode->left=newNode->right=newNode->parent = NULL;
    // if root is NULL, meaning BST is not created, set the root as new node
    if (*root==NULL){
        *root = newNode;
        return;
    }
    tree_node * temp = *root;
    tree_node * prev = NULL;
    // traverse the tree unitl leaf is reached
    while (temp!=NULL){
        prev = temp;
        // if data is greater or equal to current node data, move to right subtree
        if (data>=temp->data){
            temp = temp->right;
        // if data is less than current node data, move to left subtree
        }
        else{
            temp = temp->left;
        }
    }
    // if data is greater or equal to current node data, add new node to right of prev node
    if (data>=prev->data){
        prev->right = newNode;
        newNode->parent = prev;
    }
    // if data is less than current node data, add new node to left of prev node
    else{
        prev->left = newNode;
        newNode->parent = prev;
    }
    return;
}
double timedBSTInsert(tree_node **root,int data){
    start = clock();
    bstInsert(root, data);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("inserted %d in %f seconds\n",data,cpu_time_used);
    return cpu_time_used;
}
bool bstDelete(tree_node **root,int data){
    tree_node* curr = *root;
    tree_node* prev = NULL;
 
    // Check if the data is actually
    // present in the BST.
    // the variable prev points to
    // the parent of the data to be deleted.
    while (curr != NULL && curr->data != data) {
        prev = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    // data is not present in BST
    if (curr == NULL) {
        return false;
    }
 
    // Check if the node to be
    // deleted has atmost one child.
    if (curr->left == NULL || curr->right == NULL) {
 
        // newCurr will replace
        // the node to be deleted.
        tree_node* newCurr;
 
        // if the left child does not exist.
        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;
 
        // check if the node to
        // be deleted is the root.
        if (prev == NULL){
            newCurr->parent = NULL;
            *root = newCurr;
            return true;
        }
 
        // check if the node to be deleted
        // is prev's left or right child
        // and then replace this with newCurr
        if (curr == prev->left){
            prev->left = newCurr;
            newCurr->parent = prev;
        }
        else{
            prev->right = newCurr;
            newCurr->parent = prev;
        }
 
        // free memory of the
        // node to be deleted.
        free(curr);
    }
 
    // node to be deleted has
    // two children.
    else {
        tree_node* p = NULL;
        tree_node* temp;
 
        // Compute the inorder successor
        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }
 
        // check if the parent of the inorder
        // successor is the curr or not(i.e. curr=
        // the node which has the same data as
        // the given data by the user to be
        // deleted). if it isn't, then make the
        // the left child of its parent equal to
        // the inorder successor'd right child.
        if (p != NULL)
            p->left = temp->right;
 
        // if the inorder successor was the
        // curr (i.e. curr = the node which has the
        // same data as the given data by the
        // user to be deleted), then make the
        // right child of the node to be
        // deleted equal to the right child of
        // the inorder successor.
        else
            curr->right = temp->right;
 
        curr->data = temp->data;
        free(temp);
    }
    return true;
}
double timedBSTDelete(tree_node **root,int data){
    start = clock();
    bool res = bstDelete(root, data);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("deletion of %d exists? : %s took %f seconds\n",data,res?"true":"false",cpu_time_used);
    return cpu_time_used;
}
bool bstSearch(tree_node *root,int data){
    // loop till leaf is reached or search data is found in tree
    while(root!=NULL && root->data != data){
        // if data is greater or equal to current node data, move to right subtree
        if(data>=root->data){
            root = root->right;
        }
        // if data is less than current node data, move to left subtree
        else{
            root = root->left;
        }
    }
    // if current is null, data is not found
    if (root==NULL)
        return false;
    return true;
}
double timedBSTSearch(tree_node *root,int data){
    start = clock();
    bool res = bstSearch(root, data);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%d exists ? : %s Search took %f seconds\n",data,res ? "true" : "false",cpu_time_used);
    return cpu_time_used;
}
int bstInsertArray(tree_node **root,int data[],int n){
    // for each element in the data array, call the insert function
    int i =0;
    for (i=0;i<n;i++){
        bstInsert(root,data[i]);
    }
    return 0;
}
double timedBSTInsertArray(tree_node **root,int data[],int n){
    start = clock();
    bstInsertArray(root, data,n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("inserted array of size %d in %f seconds\n",n,cpu_time_used);
    return cpu_time_used;
}
