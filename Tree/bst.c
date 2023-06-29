// program to implementation of binary search tree
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
// Insert on bst
struct node* insert(struct node* root,int value)
{
    if(root==NULL)
    return create(value);
    if(value<root->item)
    root->left=insert(root->left,value);
    else
    root->right=insert(root->right,value);

    return root;
};


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
	struct node *root = create(5);
	insert(root,4);
	insert(root,6);
	insert(root,42);
	insert(root,3);
	insert(root,2);
	insert(root,33);

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