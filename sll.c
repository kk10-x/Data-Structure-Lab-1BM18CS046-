#include<stdio.h>
#include<stdlib.c>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
		printf("\nMemory could not be allocated");
	exit(0);
}	
NODE insert(NODE head)
{
	NODE p;
	int ele;
	printf("\nEnter the element to be inserted"); 
	scanf("%d",&ele);
	p=getnode();
	p->data=ele;
	p->next=head;
	head=p;
	return head;
}
void sort(NODE head)
{
	int s,t;
	NODE p;
	p=head;
	do
	{
		s=0;
		while(p->next!=NULL)
		{
			if(p->data=p->next->data)
			{
				t=p->data;
				p->data=p->next->data;
				p->next->data=t;
				s=1;
			}
			p=p->next;
		}
	}while(s);
}
void display(NODE head)
{
	NODE p=head;
	if(head==NULL)
	{
		printf("\nthe list is empty");
		return;
	}	
	printf("the elements in the list are");
	while(p!=NULL)
	{
		printf("%d",p->data);
		p=p->next;
	}
	return;
}
NODE rev(NODE head)
{
	NODE p,q=NULL;
	while(head!=NULL)
	{
		p=getnode();
		p->data=head->data;
		p->next=q;
		q=p;
		p=p->next;
		head=head->next;
	}
	head=q;
	free(q);
	return head;
}
NODE cc(NODE head)
{
	int n,
	NODE p=head,ahead=NULL;
	printf("\nenter the no of elements in the other list");
	scan("%d",&n);
	while(n!=0)
	{
		ahead=insert(ahead);
	}
	while(p->next==NULL)
	{
		p=p->next;
	}
	p->next=ahead;
}
int main()
{
	head=insert(head);
	head=rev(head);
