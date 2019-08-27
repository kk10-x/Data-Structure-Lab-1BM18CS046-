#include<stdio.h>
int fact(int n)
{
  if(n==0)
  return 1;
  else
  return (n*fact(n-1));
}
void main()
{
int s,n;
printf("Enter the number till which the factroial is required\n");
scanf("%d",&n);
s=fact(n);
printf("the factroial is: %d",s);
}

