#include<stdio.h>
void fun(int i);
void fun(int i)
{  if(i>1)
   fun(i/2);
   printf("%d",i%2);
}
int main()
{  int n;
   scanf("%d",&n);
   fun(n);
}