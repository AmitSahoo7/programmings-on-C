/*Program for implementing basic operation of stack  using a menu driven program */
#include<stdlib.h>
#include<stdio.h>
#define SIZE 50
char stack[SIZE];
int top=-1;
void push(int);
char pop();
void traverse();
main()
{
int ch;
char x;
printf("####***** MENU *****####\n");
printf("1.PUSH\n2.POP\n3.TRAVERSE\n4.EXIT\n");
while(1)
{
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
    case 1:
        printf("Enter the element\n");
        scanf("%d",&x);
        push(x);
        break;
    case 2:
        printf("The popped element is %d \n",pop());
        break;
    case 3:
        traverse();
        break;
    case 4:
        printf("Thankyou\n");
        exit(0);
    default:
        printf("Wrong Input\n");
        }
    }
}
void push(int c)
{
if(top==SIZE-1)
{
printf("STACK IS FULL\n");
return ;
}
else
{
top=top+1;
stack[top]=c;
}
}
char pop()
{
if(top==-1)
{
printf("STACK IS EMPTY\n");
return;
}
else
    return(stack[top--]);
}
void traverse()
{
    int i=top;
    while(i>=0)
    {
        printf("%c\n",stack[i]);
        i--;
    }
}