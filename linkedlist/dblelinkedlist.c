// By Amit Kumar Sahoo
// double linked list operations
#include<stdio.h>
#include<stdlib.h>
void create();
void ins_beg();
void display();
void ins_end();
void ins_pos();
void del_beg();
void del_end();
void del_pos();
void del_data();
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *newnode;
void create()
{
	head=NULL;
	struct node *temp;
	int ch=1;
	while(ch)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data:\n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head==NULL)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
		printf("Continue--->1");
		scanf("%d",&ch);
	}
}
void display()
{
	struct node *temp;
	temp=head;
	printf("Head--->");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		printf("<--->");
		temp=temp->next;
	}
	printf("->Tail");
}
void main()
{
	int c;
	while(1)
	{
		printf("\n...menu driven program..\n");
		printf("1.Create Double linked list\n2.Display\n3.Insert at begin\n4.Insert at end\n5.Insert at any position\n6.Delete At the beginning\n7.DElete at the end\n8.Delete at any position\n9.Delete with data\n10.Exit\nEnter the choice\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				ins_beg();
				break;
			case 4:
				ins_end();
				break;
			case 5:
				ins_pos();
				break;
			case 6:
				del_beg();
				break;
			case 7:
				del_end();
				break;
			case 8:
				del_pos();
				break;
			case 9:
				del_data();
				break;
			case 10:
				exit(0);
				break;
		}
	}
}
void ins_beg()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter The Data\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	head->prev=newnode;
	newnode->next=head;
	head=newnode;
}
void ins_end()
{
	struct node *temp;
	temp=head;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter The Data\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}
void ins_pos()
{
	struct node *temp,*temp2;
	int pos;
	temp=head;
	printf("Enter the position\n");
	scanf("%d",&pos);
	newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter The Data\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	while(pos>2)
	{
		temp=temp->next;
	}
	temp2=temp->next;
	newnode->next=temp->next;
	newnode->prev=temp;
	temp->next=newnode;
	temp2->prev=newnode;
}
void del_beg()
{
	struct node *temp;
	if(head==NULL)
		printf("Underflow\n");
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("\nNODE DELETED \n\n");
	}
	else
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
		printf("\nNODE DELETED\n");
	}
}
void del_end()
{
	struct node *temp;
	if(head==NULL)
		 printf("Underflow\n");
	 else if(head->next==NULL)
	 {
		  head=NULL;
		  free(head);
		  printf("\nNODE DELETED \n\n");
	 }
	else
	{
		 temp=head;
		 while(temp->next!=NULL)
		 {
			 temp=temp->next;
		 }
		 temp->prev->next=NULL;
		 free(temp);
		 printf("\n NODE DELETED \n");
	}
}
void del_pos()
{
	struct node *temp,*temp2;
	int pos;
	temp=head;
	printf("Enter the position to delete \n");
	scanf("%d",&pos);
	while(pos>1)
	{
		temp=temp->next;
		pos--;
	}
	temp2=temp->prev;
	temp2->next=temp->next;
	temp->next->prev=temp2;
	free(temp);
}
void del_data()
{
	 struct node *temp,*temp2;
	 int key;
	 temp=head;
	 printf("Enter the value you want to delete \n");
	 scanf("%d",&key);
	 while(temp->data!=key)
	 {
		 temp=temp->next;
	 }
	  temp2=temp->prev;
	  temp2->next=temp->next;
	  temp->next->prev=temp2;
	  free(temp);
}

