#include <stdio.h>

int main()
{
  int i, j;
  int n;
  scanf("%d",&n);
  for(i=1;i<=n;++i)
  {
    if(i%2)for(j=1;j<=n;++j) printf("%d ",(i-1)*n+j);
    else for(j=n;j>=1;--j) printf("%d ",(i-1)*n+j);
    printf("\n");
  }
  return 0;
}