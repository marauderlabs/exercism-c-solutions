#include "binary_search_tree.h"

node_t*
insert(node_t *root, int data)
{
    if (!root) {
        root = calloc(1, sizeof(node_t));
        root->data = data;
        return root;
    }

    if (data > root->data) {
        root->right = insert(root->right, data);
    } else /*if (data <= root->data)*/ {
        root->left = insert(root->left, data);
    }

    return root;
}

node_t*
build_tree (int *tree_data, size_t tree_data_len)
{
    node_t *root = NULL;

    for (size_t i = 0; i < tree_data_len; i++) {
        root = insert(root, tree_data[i]);
    }
    return root;
}

// Free the tree. Don't worry about dangling pointers as we're freeing the whole thing.
void
free_tree(node_t *root)
{
    if (!root) {
        return;
    }
    if (root->left) {
        free_tree(root->left);
    }
    if (root->right) {
        free_tree(root->right);
    }
    free(root);
}

void
inorder_traverse(node_t *node, int *arr, size_t *len)
{
    if (!node) {
        return;
    }

    inorder_traverse(node->left, arr, len);

    // copy to end of the list.
    arr[*len] = node->data;
    (*len)++;
    
    inorder_traverse(node->right, arr, len);
}

int*
sorted_data(node_t * tree)
{
    int* list = calloc(MAX_NODES, sizeof(int));
    size_t len = 0;

    // in order traversal should get us the sorted list
    inorder_traverse(tree, list, &len);

    // reduce the size to just what's needed. it shouldn't fail. So not handling failure ;-)
    // Assuming not more than MAX_NODES, to avoid code to grow the array.
    list = realloc(list, len); 

    // caller should free
    return list;
}
