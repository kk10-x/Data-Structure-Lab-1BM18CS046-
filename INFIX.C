#include<stdio.h>

#include<ctype.h>

void push(char x,int *top,char stack[100])

{

	stack[++*top]=x;

}

char pop(int *top,char stack[100])

{

	if(*top==-1)

	{
	
		printf("plj entor d xpresson \n");

			return-1;
	
	}
	
	else
		
			*top=*top-1;
			return stack[*top+1];

}

int priority(char x)

{

	if(x=='(')

		return 0;

	if(x=='+'||x=='-')

		return 1;

	if(x=='*'||x=='/')

		return 2;

	if(x=='^')

		return 3;

}

void main()

{

	char exp[20],*e,stack[20],x;

	int top,i;

	printf("Enter the expression \n");

	scanf("%s",exp);

	e=exp;

	while(*e!='\0')

	{

		if(isalnum(*e))

			printf("%c",*e);

		else if(*e=='(')

			push(*e,&top,stack);

		else if(*e==')')

		{

			while((x=pop(&top,stack))!='(')

				printf("%c",x);

		}
		
		else

		{

			while(priority(stack[top])>=priority(*e))

				printf("%c",pop(&top,stack));

			push(*e,&top,stack);

		}

		e++;

	}


	while(top!=-1)


		printf("%c",pop(&top,stack));


}


