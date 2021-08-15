#include <stdio.h>
#include <string.h>
char c[60];
int main()
{
    int i,n,s;
    scanf("%s",c);
    n=strlen(c);
    s=n*10;
    for(i=1;i<n;++i)
    {
        if(c[i-1]==c[i])s-=5;
    }
    printf("%d",s);
    return 0;
}
