#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

AVLNode* create_avl_node(int key)
{
    AVLNode *node = malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max (int a, int b)
{
    return (a > b) ? a : b;
}

int get_height(AVLNode *node)
{
    return node == NULL ? 0 : node->height;
}

AVLNode* right_rotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // right rotation
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

AVLNode* left_rotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // left rotate
    y->left = x;
    x->right = T2;

    // update heights
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;

    return y;
}

/*void avl_insert(Node **root, int data)
{
    Node *new_node = create_avl_node(data);
    if (*root == NULL) {
        *root = new_node;
        return;
    }
}*/


int main (void)
{
    return 0;
}
