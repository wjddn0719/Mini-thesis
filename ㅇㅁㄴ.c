#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

int height(struct Node *n){
    if(!n) return 0;
    int hl = height(n->left);
    int hr = height(n->right);
    return (hl > hr ? hl : hr) + 1;
}

struct Node* avl_insert(struct Node *node, int key){

    if(!node){
        struct Node *cur = (struct Node*)malloc(sizeof(struct Node));
        cur->data = key; 
        cur->left = cur->right = NULL;
        return cur;
    }
    if(key < node->data) node->left = avl_insert(node->left, key);
    else if(key > node->data) node->right = avl_insert(node->right, key);
    else return node;

    int bf = height(node->left) - height(node->right);

    if(bf > 1){ 
        if(key < node->left->data){
            struct Node *z = node;
            struct Node *y = z->left;
            struct Node *T2 = y->right;
            y->right = z;
            z->left = T2;
            return y;
        }else{
            {
                struct Node *z = node->left;
                struct Node *y = z->right;
                struct Node *T2 = y->left;
                y->left = z;
                z->right = T2;
                node->left = y;
            }
            {
                struct Node *z = node;
                struct Node *y = z->left;
                struct Node *T2 = y->right;
                y->right = z;
                z->left = T2;
                return y;
            }
        }
    }
    if(bf < -1){
        if(key > node->right->data){
            struct Node *z = node;
            struct Node *y = z->right;
            struct Node *T2 = y->left;
            y->left = z;
            z->right = T2;
            return y;
        }else{
            {
                struct Node *z = node->right;
                struct Node *y = z->left;
                struct Node *T2 = y->right;
                y->right = z;
                z->left = T2;
                node->right = y;
            }
            {
                struct Node *z = node;
                struct Node *y = z->right;
                struct Node *T2 = y->left;
                y->left = z;
                z->right = T2;
                return y;
            }
        }
    }
    return node;
}

void insert(){
    int N;
    while(scanf("%d", &N) == 1){
        root = avl_insert(root, N);
    }
}

int main(){
    insert();
    return 0;
}
