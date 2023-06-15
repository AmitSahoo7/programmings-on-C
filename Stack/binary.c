// By Amit Kumar Sahoo

#include<stdio.h>
#define max 50
int top=-1;
int stack[max];
void push(int);
int pop();
void binary(int n)
{
    while(n!=0)
    {
        push(n%2);
        n/=2;
    }
}
void main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    binary(n);
    printf("The binary form of the number %d is :\n",n);
    while(top!=-1)
    {
        printf("%d\t",pop());
    }
}
void push(int a)
{
    if(top==max-1)
    {
        printf("Stack overflow!!");
    }
    else
    {
        stack[++top]=a;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("stack underflow!!");
    }
    else
    {
        return stack[top--];
    }
}
