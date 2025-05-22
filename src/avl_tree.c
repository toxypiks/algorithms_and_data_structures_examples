#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

AVLNode* create_node(int key)
{
    AVLNode *node = malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int get_height(AVLNode *node)
{
    return node == NULL ? 0 : node->height;
}


int main (void)
{
    return 0;
}
