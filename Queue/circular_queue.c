#include<stdio.h>
#include<stdlib.h>
#define max 6
void enqueue();
void dequeue();
void display();
int queue[max];
int front=-1;
int rear=-1;
int main(){
	int ch,element;
	while(1){
        printf("\n...Menu Driven Program...\n");
		printf("\n1.enqueue\n");
		printf("\n2.dequeue\n");
		printf("\n3.display\n");
		printf("\n4.exit\n");
		printf("\nenter the choice\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				exit(0);
				break;
		}
	}
}
void enqueue()
{
    int element;
	printf("enter the data\n");
	scanf("%d",&element);
	if(front==-1&&rear==-1){
		front=0;
		rear=0;
		queue[rear]=element;
	}
	else if ((rear+1)%max==front){
		printf("queue is overflow");
	}
	else{
		rear=(rear+1)%max;
		queue[rear]=element;
	}
}
void dequeue(){
	if((front==-1)&&(rear==-1)){
		printf("\nqueue is underflow");
	}
	else if(front==rear){
		printf("the dequeue elementis %d",queue[front]);
		front=-1;
		rear=-1;
	}
	else{
		printf("\nthe dequeue elementis %d",queue[front]);
		front=(front+1)%max;
	}
}
void display(){
	int i=front;
	if(front==-1&&rear==-1){
		printf("\n the circular queue is empty/nothing to display");
	}
	else{
		printf("element in the queue are:\n");
		while(i<=rear)
        {
			printf("-->%d",queue[i]);
			i=(i+1)%max;
		}
	}
}