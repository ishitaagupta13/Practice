#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct Stack {
	int s[SIZE];
	int top1,top2;
}stack;
void push(stack *,int ,int);
int pop(stack* ,int );
void disp(stack);
void main()
{
	stack st;
	st.top1=-1;
	st.top2=SIZE;
	
	int ch,id,x;
	printf("*********MULTIPLE STACK MENU***********\n\t");


	do{
	printf("enter stackid\n");
	scanf("%d",&id);
	
	printf("ENTER YOUR CHOICE\n1-push\n 2-pop\n 3-display\n 4-exit\n");
	scanf("%d",&ch);
	switch (ch)
	
	{
		case 1: printf("Enter the element to push\n ");
		        scanf("%d",&x);
		        push(&st,x,id);
		        break;
		case 2: pop(&st,id);
		        if(x!=-999)
					{
						printf("popped item is %d\n",x);
					}   
	           	break;
	    case 3: disp(st);
		case 4:exit(0);
	    default:printf("invalid choice\n");
			
	}
	
}while(1);
}
void push(stack * st,int x,int id)
{
	if(st->top1==st->top2 - 1)
	{
		printf("both queues are full\n");
		return ;
	}
	if(id==1)
	{
		st->top1++;
		st->s[st->top1]=x;
	}
	else
	{
		st->top2--;
		st->s[st->top2]=x;
	}
}


int pop(stack* st,int id)
{
	int x;
	if(st->top1==-1)
	{
		printf("stack 1 is empty\n");
		return -999;
	}
	if(st->top2==SIZE)
	{
		printf("stack 2 is empty\n");
		return -999;
	}
	
	
	if(id==1){
	
	x=st->s[st->top1];
	st->top1--;
	return x;
   }
   
if(id==2){
	
	x=st->s[st->top2];
	st->top2++;
	return x;
}
void disp(stack st)
{
	
 	int i;
 	if(st.top1==-1)
 	   printf("stack 1 is empty\n");
 	if(st.top2==SIZE)
		printf("stack 2 is empty\n");
 	 
 	for(i=SIZE;i>=0;i--)
 	{
 		printf("%d\n",st.s[i]);
	 }
 
}
}

		     
	     


	     
	   

