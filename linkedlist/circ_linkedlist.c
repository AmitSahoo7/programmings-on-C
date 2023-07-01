// Insertion and Deletion operation in Cicular Linked List

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;
void create();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void display();
void create()
{
	struct node *newnode,*temp;
	int ch=1;
	head=NULL;
	while(ch)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data:\n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(head==NULL)
		{
			temp=head=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		temp->next=head;
		printf("Continue...");
		scanf("%d",&ch);
	}
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("LIST IS EMPTY");
	}
	else
		{
			temp=head;
			while(temp->next!=head)
			{
				printf("%d<-->",temp->data);
				temp=temp->next;
			}
			printf("%d\n",temp->data);
		}
}
void main()
{
	int c;
	while(1)
	{
		printf("\n...Menu driven program..\n");
		printf("1.Create a circular linked list\n2.Insert at begin\n3.Insert at end\n4.Insert at any position\n5.Delete from the beginning\n6.Delete from the end\n7.Delete at any position\n8.Display\n9.Exit\nEnter the choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				create();
				break;
			case 2:
				insert_begin();
				break;
			case 3:
				insert_end();
				break;
			case 4:
				insert_pos();
				break;
			case 5:
			        delete_begin();
			        break;
			case 6:
			        delete_end();
			        break;
			case 7:
			        delete_pos();
			        break;	
			case 8:
				display();
				break;
			case 9:
			        exit(0);	
				break;
		}
	}

}
void insert_begin()
{
	struct node *newnode;
	struct node *temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("NO MEMORY ALLOCATION\n");
	}
	else
	{
		printf("Enter the data:\n");
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head=newnode;
			newnode->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			newnode->next=head;
			temp->next=newnode;
			head=newnode;
		}
	}
}
void insert_pos()
{
	struct node *newnode,*temp;
	int pos;
	newnode=(struct node *)malloc(sizeof(struct node));
	if (head==NULL)
	{
		printf("Cannot enter the data\n");
	}
                 printf("Enter the data:\n");
		 scanf("%d",&newnode->data);
		 printf("Enter the position to be inserted:\n");
		 scanf("%d",&pos);
		 temp=head;
		 while(--pos>1)
		 {
			 temp=temp->next;
		 }
		 newnode->next=temp->next;
		 temp->next=newnode;
	}
void insert_end()
	{
		struct node *newnode,*temp;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("\n NO MEMORY ALLOCATION\n");
		}
		else
		{
			printf("\n Enter the data:\n");
			scanf("%d",&newnode->data);
			if(head==NULL)
			{
				head=newnode;
				newnode->next=head;
			}
			else
			{
				temp=head;
				while(temp->next!=head)
					{
						temp=temp->next;
					}
				temp->next=newnode;
				newnode->next=head;
			}
			}
	}
void delete_begin()
{
	struct node *temp=head,*last=NULL;
	if(head==NULL)
	printf("LIST IS EMPTY");
	else
	{
		if(temp->next==head)
		{
			head=NULL;
			free(temp);
		}
		else
		{
			while(temp->next!=head)
			temp=temp->next;
			last=temp;
			temp=head;
			head=head->next;
			free(temp);
			last->next=head;
		}
		printf("\n DELETION SUCCESSFUL\n");
	}
}
void delete_end()
{
	struct node *temp=head,*last=NULL;
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		if(temp->next==head)
		{
			head=NULL;
			free(temp);
		}
		else
		{
			while(temp->next!=head)
			{
				last=temp;
				temp=temp->next;
			}
			free(temp);
			last->next=head;
		}
		printf("\n Deleteion successful..\n");
	}
}
void delete_pos()
{
	struct node *temp=head,*last=NULL;
	int pos;
	if(head==NULL)
		printf("List is empty\n");
	else
	{
		printf("Enter the position : \n");
		scanf("%d",&pos);
		if(temp->next==head)
		{
			head=NULL;
			free(temp);
		}
		else
		{
			while(pos-->1)
			{
				last=temp;
				temp=temp->next;
			}
			last->next=temp->next;
			free(temp);
		}
		printf("\n Deleteion successful..\n");
	}
}