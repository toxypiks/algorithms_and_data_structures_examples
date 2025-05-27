#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 4 // max degree of b-tree

typedef struct BTreeNode {
    int num_keys; // current number of keys in node
    int keys[M - 1]; // array of keys
    struct BTreeNode *children[M]; // array of child pointers
    bool is_leaf; // true if node is a leaf
} BTreeNode;

BTreeNode* create_node(bool is_leaf) {
    BTreeNode *new_node = malloc(sizeof(BTreeNode));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->num_keys = 0;
    new_node->is_leaf = is_leaf;
    for (int i = 0; i < M; ++i) {
        new_node->children[i] = NULL;
    }
    for (int i = 0; i < M - 1; ++i) {
        new_node->keys[i] = 0;
    }
    return new_node;
}

int main(void)
{
    return 0;
}
