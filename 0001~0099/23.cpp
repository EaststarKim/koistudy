#include <stdio.h>
#include <string.h>
char a[20];
int main()
{
    int i,n;
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n;++i)printf("'%c'\n",a[i]);
}
