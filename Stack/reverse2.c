// reverse a number using stack...
#include<stdio.h>
#define max 100
int stack[max];
int top=-1;
void push(int);
int pop();
void reverse(int);
void main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    reverse(n);
}
void reverse(int  n)
{
    int r1,r2,a,m=0;
    while(n!=0)
    {
        r1=n%10;
        m=m*10+r1;
        n=n/10;
    }
    a=m;
    while(m!=0)
    {
        r2=m%10;
        push(r2);
        m=m/10;
    }
    printf("The reversed number is:\t");
    while(a!=0)
    {
        printf("%d",pop());
        a=a/10;
    }
}
void push(int r)
{
    if(top==max-1)
    {
        printf("Stack overflow!!");
    }
    else
    {
        stack[++top]=r;
    }
}
int pop()
{
    if (top==-1)
    {
        printf("Stack  underflow!!");
    }
    else
    {
        return stack[top--];
    }
}