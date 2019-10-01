#include<stdlib.h>
#include<stdio.h>
struct node
{
int data;
struct node *next;
};
typedef struct node *NODE;
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
void display(NODE head){
	NODE p;
	if(head == NULL){
		printf("stack is empty\n");
		return;
	}
	p = head;
	printf("the elements are\n");
	while(p!= NULL){	

		
printf("%d  \n", p->data);
		p = p->next;
	}
	printf("\n");
}
NODE push(NODE head, int ele){
    NODE p, q;
    p = getnode();
    p->data = ele;
    p->next = NULL;
    q = head;
    if(head == NULL)
     	
	return p;
    while(q->next != NULL){
        
	q = q->next;
    }
    q->next = p;
    return head;
}
NODE pop(NODE head){
    NODE q,p = head;
	if(head==NULL){
	printf("\n stack underflow\n");
	return head;
}
    if(head->next == NULL){
	printf("%d has been deleted\n",head->data);    	
	head=head->next;    	
	return head;
    }
   while((p->next)->next!=NULL)
    {
      p=p->next;
     }
     printf("DELTED ELEMENT=%d\n",(p->next)->data);
      p->next=NULL;
      return head;
 
}
int main(){
    NODE head = NULL;
    int choice, ele, n, pos, value, i=0;
	while(i != 5){
		printf("\n1.PUSH \n2.POP\n3.DISPLAY\n4.EXIT\n");
		printf("Enter option\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter element to be inserted\n");
					scanf("%d", &ele);
					head = push(head, ele);
					break;
			case 2: 	
					head=pop(head);
					break;
			case 3:	display(head);
					break;
			
                	default:exit(0);
		}
	}
	return 0;
}




