#include<stdlib.h>
#include<stdio.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
NODE getnode();
NODE insertfront (int item,NODE head)
{
NODE p = getnode();
p->data=item;
p->next=head;
head =p;
return head;
}
NODE getnode()
{
NODE p;
p=(NODE)malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("Memory could not be allocated\n");
exit(0);
}
}
void insertend(NODE head,int item)
{
NODE p,q;
q = getnode();
q->data = item;
p = head;
while(p->next!=NULL)
{
p = p->next;
}
p->next = q;
q->next = NULL;
}

NODE insertpos(NODE head,int item,int pos)
{
NODE curr,prev = NULL,newn;
int count =1;
newn =getnode();
newn->data= item;
newn->next=NULL;
if(head==NULL)
{
    if(pos==1)
    return newn;
    else
    {
    printf("INVALID POSITION\n");
    return head;
    }
}
else if(pos ==1)
{
    newn->next = head;
    head =newn;
return head;
}
else
{
    curr = head;
    while(curr!=NULL && count!=pos)
        {
            prev= curr;
            curr = curr->next;
            count++;
        }
    if(count==pos)
        {
            prev->next = newn;
            newn->next = curr;
            return head;
        }
    else
    {
    printf("INVALID POSITION\n");
    return head;
    }
}
}
void display(NODE head)
{
NODE p;
if(head == NULL)
{
printf("List is Empty\n");
return;
}
printf("Linked List Contents are: \n");
p = head;
while(p!=NULL)
{
printf("%d ",p->data);
p=p->next;
}
return;

}
NODE delbeg(NODE head)
{
    
     NODE p=head;
     
     
     
     
     	
     	NODE q=p->next;
     	free(p);
     	head=q;
     	return head;
 }    
     NODE delend(NODE head,int count)
     {int i;
     NODE p=head;
     	for(i=0;p!=NULL&&i<count-1;i++)
     	{
     		if(p==NULL&&p->next==NULL)
     		{
     			head=NULL;
     			free(p);
     			return head;
     		}
     		if(p->next->next!=NULL)
     			p=p->next;
     		else
     			p->next=NULL;
     			return head;
     	}
     }
     NODE delpos(NODE head,int pos)
     {	int i;
     NODE p=head;
     
     for(i=0;p!=NULL&&i<pos-1;i++)
     {
     	if(p==NULL||p->next==NULL)
     	{
     		printf("Position is more than the number of nodes\n");
     		return head;
     	}
     	NODE next=p->next->next;
     	free(p->next);
     }
    }
   
     	
     
     	
int main()
{
int c,item,pos,c1,count,ch;
count=0;
NODE head = (NODE)malloc(sizeof(struct node));
printf("Enter value of first element:\n");
scanf("%d",& item);
head->data = item;
c=1;
while(c!=0)
{
printf("\nENTER 1 TO INSERT AT FRONT\nENTER 2 TO INSERT AT END\nENTER 3 TO INSERT AT A POSITION\nENTER 4 TO DISPLAY\nENTER 5 TO DETETE AN NODE\nENTER 6 TO EXIT\n");
scanf("%d",&c);
if(c==1||c==2||c==3)
count++;
if(c==5)
count--;
switch(c)
{
case 0:break;
case 1: printf("Enter the item:\n");
        scanf("%d",&item);
        head = insertfront(item,head);
        break;
case 2: printf("Enter the item:\n");
        scanf("%d",&item);
        insertend(head,item);
        break;
case 3: printf("Enter the position:\n");
        scanf("%d",&pos);
        printf("Enter the item:\n");
        scanf("%d",&item);
        head = insertpos(head,item,pos);
        break;
case 4: display(head);
        break;
case 5: printf("Where should the node be deleted from?\n1.Beginning\n2.At any node\n3.End\n");
scanf("%d",&ch);
if(ch==1)
{
head=delbeg(head);
}
if(ch==2)
{printf("Enter the position\n");
scanf("%d",&pos);
head=delpos(head,pos);
}
if(ch==3)
{
head=delend(head,count);
}
break;


default: exit(0);
}
}
}
