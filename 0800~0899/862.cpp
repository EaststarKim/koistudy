#include <stdio.h>
#include <string.h>
int a[2001],b[2001],x[2001],n,m;
char c[2001],d[2001],t[2001];
void change()
{
    int i;
    for(i=0;i<n;++i)a[i+1]=c[i]-48;
    for(i=0;i<m;++i)b[i+1]=d[i]-48;
}
void plus()
{
    int i;
    for(i=1;i<=n;++i)x[i]=a[i];
    for(i=0;i<m;++i)x[n-i]+=b[m-i];
    for(i=n;i>0;--i)x[i-1]+=x[i]/10,x[i]%=10;
}
void output()
{
    int i;
    for(i=0;i<=n;++i)
    {
        if(x[i])break;
    }
    for(;i<=n;++i)printf("%d",x[i]);
    printf("\n");
}
int main()
{
    int tmp;
    scanf("%s %s",c,d);
    n=strlen(c);
    m=strlen(d);
    if(n<m)
    {
        strcpy(t,c),strcpy(c,d),strcpy(d,t);
        tmp=n,n=m,m=tmp;
    }
    change();
    plus();
    output();
    return 0;
}
