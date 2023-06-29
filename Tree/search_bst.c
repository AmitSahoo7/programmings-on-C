// Binary Search Tree operations in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node* newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {

    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);

  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}
//preorder Traversal
void preorderTraversal(struct node* root)
{
	if(root==NULL)
		return;
	printf("%d->",root->key);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
//postorder
void postorderTraversal(struct node* root)
{
	if(root==NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d->",root->key);
}
//searching a element in bst

struct node *search(struct node *root,int element)
{
	if(root==NULL ||root->key==element)
		return root;
	if(element >root->key)
		return search(root->right,element);
	else
		return search(root->left,element);
}


int main() {
       	struct node* root = newNode(5);
       	insert(root, 4);
	insert(root, 6);
	insert(root, 42);
	insert(root, 3);
	insert(root, 2);
	insert(root, 33);

	printf("\nTraversal of the inserted binary tree");
	printf("\nInorder traversal \n");
	inorder(root);

	printf("\nPreorder traversal \n");
	preorderTraversal(root);
	printf("\nPostorder traversal \n");
	postorderTraversal(root);
	printf("\n");
	int num;
	printf("Enter the element which to be searched:\n");
	scanf("%d",&num); 
	if(search(root,num)==NULL)
		printf("Element %d not found \n",num);
	else
	{
		printf("Element %d found \n",num);
	}
	return 0;
}

