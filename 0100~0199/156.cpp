#include <stdio.h>
int k;
void f(int n)
{
  if(n<k) 
  {
	  printf("%X",n);
	  return ;
  }
  f(n/k);
  printf("%X",n%k);
}
void main()
{
  int n;
  scanf("%d%d",&n, &k);
  f(n);
}