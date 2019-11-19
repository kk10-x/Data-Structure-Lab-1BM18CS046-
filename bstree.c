#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *rc;
	struct node *lc;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE p=(NODE)malloc(sizeof(struct node));
    if(p==NULL)
        exit(0);
    return p;
}
NODE insert(NODE root,int ele)
{
	if(root==NULL)
	{
		NODE p=getnode();
		p->data=ele;
		return p;
	}
	if(root->data>ele)
	{
		root->lc=insert(root->lc,ele);
	}
	else if(root->data<ele)
	{
		root->rc=insert(root->rc,ele);
	}
	return root;
}
void posorder(NODE root)
{
	if(root==NULL)
	{
		return;
	}
	posorder(root->lc);
	posorder(root->rc);
	printf("%d",root->data);
}
void preorder(NODE root)
{
	if(root==NULL)
		return;
	printf("%d",root->data);
	preorder(root->lc);
	preorder(root->rc);
}
void inorder(NODE root)
{
	if(root==NULL)
		return;
	inorder(root->lc);
	printf("%d",root->data);
	inorder(root->rc);
}
int main(){
    NODE root= NULL;
    int choice, ele, i=0;
	while(i != 5){
		printf("\n1.Insert\n2.InOrder\n3.PostOreder\n4.PreOrder\n5.Display\n6.Exit\n");
		printf("Enter option\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter element to be inserted\n");
					scanf("%d", &ele);
					root = insert(root, ele);
					break;
			case 2: inorder(root);	
					break;
			case 3:	posorder(root);
					break;
			case 4: preorder(root);
					break;
			
            default:exit(0);
		}
	}
	return 0;
}
	

