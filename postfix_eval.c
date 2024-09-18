#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
# define SIZE 10
typedef struct Stack
{
	int s[SIZE];
	int top;
}stack;
void push(stack*,int );
int pop (stack*);
int postfix_eval(char[]);
int calc(int,int,char);

void main()
{

	char exp[SIZE],res;
	printf("\nENTER VALID POSTFIX EXPRESSION\n");
	scanf("%s",exp);
	if(res!=-999){
	
	res=postfix_eval(exp);
	printf("Result=%d",res);
}
}
void push(stack* st,int x)
{
	if(st->top==SIZE-1)
	{
		printf("stack is full\n");
		return;
	}
	st->top++;
	st->s[st->top]=x;
}
int pop(stack *st)
{
	int x;
	if(st->top==-1)
	{
		printf("stack is empty\n");
		return -999;
	}
	x=st->s[st->top];
	st->top--;
	return x;
}
int postfix_eval(char exp[SIZE])
{
	stack st;
	st.top=-1;
	int lopnd,ropnd,res,i=0;
	while(exp[i]!='\0')
	{
		if(isdigit(exp[i]))
		    push(&st,exp[i]-48);
		else if(exp[i]=='*'||exp[i]=='+'||exp[i]=='-'||exp[i]=='/')   
		{
			ropnd=pop(&st);
			lopnd=pop(&st);
			res=calc(lopnd,ropnd,exp[i]);
			push(&st,res);
		 } 
		 else
		 {
		 
		   printf("invalid character");
		   return -999;
	}
		   
		   i++;
	}
	return pop(&st);
}
int calc(int l,int r,char opt)
{

switch(opt)
 {
 	case'+':return l+r;
 	     
 	case'*':return l*r;
 	       
	case'-':return l-r;
 	     
	case'/':return l/r;
 	       	
 	        
 }
}
