#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",(1<<(n*2))+(2<<n)+1);
    return 0;
}
