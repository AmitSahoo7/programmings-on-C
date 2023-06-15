// By Amit Kumar Sahoo

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define max 100
void inftopost();
int precedence(char);
void push(char);
char pop();
int isempty();
int isFull();
char stack[max];
char infix[max];
char post[max];
int top=-1;
void main()
{
    printf("Enter the infix expresson:\n");
    scanf("%s",infix);
    inftopost();
}
void inftopost()
{
    int i,j=0;
    char sym,next;
    for(i=0;i<strlen(infix);i++)
    {
        sym=infix[i];
        switch(sym)
        {
            case '(':
                push(sym);
                break;
            case ')':
                while((next=pop())!=')')
                    post[j++]=next;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isempty() && precedence(stack[top])>=precedence(sym))
                    post[j++]=pop();
                push(sym);
                break;
            default:
                post[j++]=sym;
        }
    }
    while(!isempty())
        post[j++]=pop();
    post[j]='\0';
    printf("%s",post);
}
int precedence( char a)
{
    switch(a)
    {
        case '^':
            return 3;
            
        case '/':
        case '*':
            return 2;
          
        case '+':
        case '-':
            return 1;
         
        default:
            return 0;
    }
}
void push(char s)
{
    if(isFull())
    printf("Stack overflow");
    else
    {
        top++;
        stack[top]=s;
    }
}
char pop()
{
    char ch;
    if(isempty())
        return -1;
    ch=stack[top];
    top--;
    return ch;
}
int isempty()
{
    return top==-1;
}
int isFull()
{
    return top==max-1;
}