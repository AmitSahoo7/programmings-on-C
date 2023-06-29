// program for implementing binary tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *left;
	struct node *right;
};
// create newnode
struct node *create(int value)
{
	struct node *newNode = malloc(sizeof(struct node));
	newNode->item = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
// Insert on the left of the node
struct node *insertLeft(struct node *root, int value)
{
	root->left = create(value);
	return root->left;
}

struct node *insertRight(struct node *root, int value)
{
	root->right = create(value);
	return root->right;
}
// Inorder Traversal
void inorderTraversal(struct node *root)
{
	if (root == NULL)
		return;
	inorderTraversal(root->left);
	printf(" %d ", root->item);
	inorderTraversal(root->right);
}
// preorder Traversal
void preorderTraversal(struct node *root)
{
	if (root == NULL)
		return;
	printf(" %d ", root->item);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
// postorder
void postorderTraversal(struct node *root)
{
	if (root == NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf(" %d ", root->item);
}

int main()
{
	struct node *root = create(1);
	insertLeft(root, 4);
	insertRight(root, 6);
	insertLeft(root->left, 42);
	insertRight(root->left, 3);
	insertLeft(root->right, 2);
	insertRight(root->right, 33);

	printf("\nTraversal of the inserted binary tree");
	printf("\nInorder traversal \n");
	inorderTraversal(root);

	printf("\nPreorder traversal \n");
	preorderTraversal(root);
	printf("\nPostorder traversal \n");
	postorderTraversal(root);
	printf("\n");
	return 0;
}