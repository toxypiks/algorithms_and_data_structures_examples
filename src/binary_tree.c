#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* create_node (int data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void tree_insert(Node **tree, int data) {
    Node *tmp = *tree;
    bool found = false;

    while(!found)
    {
        if (data < tmp->data) {
            if (tmp->left != NULL) {
                tmp = tmp->left;
            } else {
                found = true;
            }
        }
        else if (data == tmp->data) {
            found = true;
        }
        else {
            if (tmp->right != NULL) {
                tmp = tmp->right;
            }
            else {
                found = true;
            }
        }
    }
    if (data != tmp->data) {
        Node *new_node = create_node(data);
        if (data < tmp->data) {
            tmp->left = new_node;
        } else {
            tmp->right = new_node;
        }
    }
}

void tree_print_preorder(Node* tree)
{
    if (tree != NULL) {
       printf("%d ", tree->data);
       tree_print_preorder(tree->left);
       tree_print_preorder(tree->right);
    }
}

void tree_print_inorder(Node* tree)
{
    if (tree != NULL) {
        tree_print_inorder(tree->left);
        printf("%d ", tree->data);
        tree_print_inorder(tree->right);
    }
}

void tree_print_postorder(Node* tree)
{
    if (tree != NULL) {
        tree_print_inorder(tree->left);
        tree_print_inorder(tree->right);
        printf("%d ", tree->data);
    }
}

int main (void)
{
    int root_data = 10;
    Node *tree = create_node(root_data);

    tree_insert(&tree, 2);
    tree_insert(&tree, 5);
    tree_insert(&tree, 17);
    tree_insert(&tree, 1);

    // 10, 2, 1, 5, 17
    tree_print_preorder(tree);

    printf("\n---------------------------\n\n");
    // 1, 2, 5, 10, 17
    tree_print_inorder(tree);

    return 0;
}
