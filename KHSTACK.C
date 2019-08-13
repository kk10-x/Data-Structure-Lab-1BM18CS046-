#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void push(int ele,int st[],int *top);
void display(int st[],int *top);
int pop(int st[],int *top);
void main()
{
	int ch,ele,st[4],top=-1,p;
	clrscr();
	while(1)
	{
	printf("Enter 1 for push,2 for pop,3 for display \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("enter the element to be pushed \n");
			scanf("%d",&ele);
			push(ele,st,&top);
			break;
		case 2:
			p=pop(st,&top);
			printf("the element %d has been popped \n",p);
			break;
		case 3:
			display(st,&top);
			break;
		default:
			exit(0);
	}
	}
	getch();
}
void push(int ele,int st[],int *top)
{
	if(*top==4)
	{
		printf("Stack is full \n");
		return;
	}
	else
		st[++*top]=ele;
	return;
}
void display(int st[],int *top)
{
	int i;
	for(i=*top;i>=0;i--)
		printf("%d \n",st[i]);
	return;
}
int pop(int st[],int *top)
{
	int p;
	if(*top<0)
	{
		printf("Stack underflow \n");
		return -999;
	}
	else
	{

		p=st[*top];
		*top=*top-1;
		return p;
	}
}
