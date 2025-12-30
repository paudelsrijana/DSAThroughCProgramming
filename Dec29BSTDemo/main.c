#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        root = (struct Node *)malloc(sizeof(struct Node));
        root->data = value;
        root->left = root->right = NULL;
        return root;
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    // Constructing the BST
    for (int i = 0; i < 7; i++)
        root = insert(root, keys[i]);
    printf("Inorder Traversal (Sorted): ");
    inorder(root);
    return 0;
}
