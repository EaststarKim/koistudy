#include <stdio.h>

int main()
{
  int i;
  int n;
  __int64 a, b, c;
  scanf("%d",&n);
  a=b=1;
  c=0;
  for(i=2;i<n;++i)
  {
    c=a+b;
    a=b;
    b=c;
  }
  printf("%I64d\n",b);
  return 0;
}