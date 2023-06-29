#include<stdio.h>
#include<malloc.h>
struct link
{
	int coeff;
	int pow;
	struct link *next;
};
struct link *poly1=NULL,*poly2=NULL,*poly=NULL;
void create(struct link *node)
{
	int ch=1;
	while(ch)
	{
		printf("\nEnter the coefficient:\n");
		scanf("%d",&node->coeff);
		printf("\nEnter the power:\n");
		scanf("%d",&node->pow);
		node->next=(struct link *)malloc(sizeof(struct link));
		node=node->next;
		node->next=NULL;
		printf("\nContinue(1/0):\n");
		scanf("%d",&ch);
	}
}
void show(struct link *node)
{
	while(node->next!=NULL)
	{
		if(node->pow==0)
		{
			printf("%d  ",node->coeff);
		}
        else if(node->pow==1)
		{
			printf("%dx ",node->coeff);
		}
        else
		{
		printf("%dx^%d  ",node->coeff,node->pow);
		}
		node=node->next;
		if(node->next!=NULL)
		printf("  +  ");
	}
	printf("\n\n");
}
void polyadd(struct link *poly1,struct link *poly2,struct link *poly)
{
	while(poly1->next && poly2->next)
	{
		if(poly1->pow > poly2->pow)
		{
			poly->pow=poly1->pow;
			poly->coeff=poly1->coeff;
			poly1=poly1->next;
		}
		else if(poly1->pow <poly2->pow)
		{
			poly->pow=poly2->pow;
			poly->coeff=poly2->coeff;
			poly2=poly2->next;
		}
		else
		{
			poly->pow=poly1->pow;
			poly->coeff=poly1->coeff+poly2->coeff;
			poly1=poly1->next;
			poly2=poly2->next;
		}
		poly->next=malloc(sizeof(struct link));
		poly=poly->next;
		poly->next=NULL;
	}
	while(poly1->next || poly2->next)
	{
		if(poly1->next)
		{
			poly->pow=poly1->pow;
			poly->coeff=poly1->coeff;
			poly1=poly1->next;
		}
		if(poly2->next)
		{
			poly->pow=poly2->pow;
			poly->coeff=poly2->coeff;
			poly2=poly2->next;
		}
		poly->next=malloc(sizeof(struct link));
		poly=poly->next;
		poly->next=NULL;
	}
}

void main()
{
	poly=(struct link *)malloc(sizeof(struct link));
	poly1=(struct link *)malloc(sizeof(struct link));
	poly2=(struct link *)malloc(sizeof(struct link));
	printf("\n Enter the 1st Polynomial terms:\n");
	create(poly1);
	printf("\n Enter the 2nd polynomial terms:\n");
	create(poly2);
	printf("\n1st polynomial:\n");
	show(poly1);
	printf("\n2nd polynomial:\n");
	show(poly2);
	polyadd(poly1,poly2,poly);
	printf("\nThe Sum of two polynomials is :\n");
	show(poly);
}