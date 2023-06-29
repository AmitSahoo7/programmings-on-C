#include <stdio.h>
#include <malloc.h>
struct link
{
	int coeff;
	int pow;
	struct link *next;
};
struct link *poly1 = NULL, *poly2 = NULL;
void create(struct link *node)
{
	int ch = 1;
	while (ch)
	{
		printf("\nEnter the coefficient:\n");
		scanf("%d", &node->coeff);
		printf("\nEnter the power:\n");
		scanf("%d", &node->pow);
		node->next = (struct link *)malloc(sizeof(struct link));
		node = node->next;
		node->next = NULL;
		printf("\nContinue(1/0):\n");
		scanf("%d", &ch);
	}
}
void show(struct link *node)
{
	while (node->next != NULL)
	{
        if(node->pow==0)
        {
            printf("%d", node->coeff, node->pow);
        }
        else if(node->pow==1)
        {
            printf("%dx", node->coeff, node->pow);
        }
        else
        {
		printf("%dx^%d", node->coeff, node->pow);
        }
		node = node->next;
		if (node->next != NULL)
			printf(" + ");
	}
	printf("\n");
}
void main()
{
	poly1 = (struct link *)malloc(sizeof(struct link));
	poly2 = (struct link *)malloc(sizeof(struct link));
	printf("\n Enter the 1st Polynomial terms:\n");
	create(poly1);
	printf("\n Enter the 2nd polynomial terms:\n");
	create(poly2);
	printf("\n1st polynomial:\n");
	show(poly1);
	printf("\n2nd polynomial:\n");
	show(poly2);
}