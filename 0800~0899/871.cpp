#include <stdio.h>
#include <string.h>
int a[21];
char c[21];
int main()
{
    int i,n,s;
    scanf("%s",c);
    n=strlen(c)-1;
    for(i=0;i<=n;++i)
    {
        if(47<c[i]&&c[i]<58)a[i]=c[i]-48;
        if(c[i]=='I')a[i]=1;
        if(c[i]=='V')a[i]=5;
        if(c[i]=='X')a[i]=10;
        if(c[i]=='L')a[i]=50;
        if(c[i]=='C')a[i]=100;
        if(c[i]=='D')a[i]=500;
        if(c[i]=='M')a[i]=1000;
    }
    s=a[n-1]*a[n];
    for(i=n-2;i>0;i-=2)
    {
        if(a[i]<a[i+2])s-=a[i-1]*a[i];
        else s+=a[i-1]*a[i];
    }
    printf("%d",s);
    return 0;
}
