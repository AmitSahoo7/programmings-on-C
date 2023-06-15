// By Amit Kumar Sahoo
// Single linked list operations..
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*temp;
void ins_begin();
void insert_last();
void insert_loc();
void delete_begin();
void delete_last();
void delete_loc();
void display();
void main()
{
	int ch;
	while(1)
	{
		printf("..Menu driven program..\n");
		printf("1.Insert at the beginning\n2.Insert at the end\n3.Insert at any location\n4.Delete from the beginning\n5.Delete from the last\n6.Delete from any location\n7.Display\n8.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				ins_begin();
				break;
			case 2:
				insert_last();
				break;
			case 3:
			        insert_loc();
			        break;
			case 4:
			        delete_begin();
			        break;
			case 5:
				delete_last();
				break;
			case 6:
				delete_loc();
				break;
			case 7:
				display();
				break;
			case 8:
				exit(0);
				break;
		}
	}
}
void ins_begin()
{
	struct node *p;
	int value;
	p=(struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("NO MEMORY ALLOCATION");
		return;
	}
	else
	{
		printf("Enter the data");
		scanf("%d",&value);
		p->data=value;
		p->next=head;
		head=p;
	}
}
void display()
{
	struct node *p;
	p=head;
	if(p==NULL)
		printf("Nothing to print \n");
	else
	{
		printf("\nPrinting values\n");
		printf("Head-->");
		while(p!=NULL)
		{
			printf("%d-->",p->data);
			p=p->next;
		}
		printf("Tail\n");
	}
}
void insert_last()
{       
	struct node *p;
	int value;
	p=(struct node*)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("NO MEMORY ALLOCATION");
		return;
	}
	else
	{
		printf("Enter the data:\n");
		scanf("%d",&value);
		p->data=value;
		if(head==NULL)
		{
			p->next=NULL;
			head=p;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=p;
			p->next=NULL;
		}
	}
}
void insert_loc()
{       
	struct node *p;
	int i,loc,value;
	p=(struct node  *)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("\n OVER FLOW\n");
	}
	else
	{
		printf("\nEnter the data\n");
		scanf("%d",&value);
		p->data=value;
		printf("Enter the location after which you want to insert:\n");
		scanf("%d",&loc);
		temp=head;
		for(i=1;i<=loc;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("\nCannot insert\n");
				return;
			}
		}
		p->next=temp->next;
		temp->next=p;
	}
}
void delete_begin()
{
	struct node *p;
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY\n");
	}
	else
	{
		p=head;
		head=p->next;
		free(p);
	}
}
void delete_last()
{
	struct node *p,*p1;
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nONLY NODE OF THE LIST DELETED....\n");
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			p1=p;
			p=p->next;
		}
		p1->next=NULL;
		free(p);
	}
}
void delete_loc()
{
	struct node *p,*p1;
	int loc,i;
	printf("\nEnter the location of the node after which you want to perform deletion\n");
	scanf("%d",&loc);
	p=head;
	for(i=0;i<loc;i++)
	{
		p1=p;
		p=p->next;
		if(p==NULL)
		{
			printf("\nCann't Delete\n");
			return;
		}
	}
	p1->next=p->next;
	free(p);
	printf("\nDeleted node is%d\n",loc+1);
}
