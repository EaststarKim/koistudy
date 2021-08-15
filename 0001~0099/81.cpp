#include <stdio.h>
int main()
{
    int i,k;
    scanf("%X",&k);
    for(i=1;i<16;++i)printf("%X*%X=%X\n",k,i,k*i);
}
