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
exit(0);
}
printf("Linked List Contents are: \n");
p = head;
while(p!=NULL)
{
printf("%d\n",p->data);
p=p->next;
}
return;

}

int main()
{
int c,item,pos,c1;
NODE head = (NODE)malloc(sizeof(struct node));
printf("Enter value of first element:\n");
scanf("%d",& item);
head->data = item;
c=1;
while(c!=0)
{
printf("\nENTER 1 TO INSERT AT FRONT\nENTER 2 TO INSERT AT END\nENTER 3 TO INSERT AT A POSITION\nENTER 4 TO DISPLAY\n");
scanf("%d",&c);
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
default: printf("Invalid Entry\n");
}
}
}
