// by Amit Kumar Sahoo
// reverse a string using stack
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 50
int stack[max];
int top=-1;
void reverse(char []);
void push(char );
char pop();
void main()
{
    int i;
    char s[max];
    printf("Enter the string : ");
    scanf("%s",s);
    reverse(s);
}
void reverse(char a[])
{
    int i;
    for(i=0;i<strlen(a);i++)
    {
        push(a[i]);
    }
    for(i=0;i<strlen(a);i++)
    {
        a[i]=pop();
    }
    printf("The reversed string is: %s ",a);
}
void push(char c)
{
    if(top==max-1)
    {
        printf("Stack overflow!!");
    }
    else
    {
        stack[++top]=c;
    }
}
char pop()
{
    if(top==-1)
    {
        printf("stack underflow!!");
    }
    else
    {
        char t=stack[top];
        top--;
        return t;
    }
}