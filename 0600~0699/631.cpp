#include <stdio.h>
const int n=10000000;
int q[n],s[n],f,r=1;
int main()
{
    int x,y,k;
    scanf("%d%d",&x,&y);
    q[1]=x;
    s[x]=1;
    if(x==y)
    {
        printf("0");
        return 0;
    }
    while(f<r)
    {
        x=q[++f];
        k=x*2%n;
        if(!s[k])q[++r]=k,s[k]=s[x]+1;
        if(k==y)break;
        k=(x+n-1)%n;
        if(!s[k])q[++r]=k,s[k]=s[x]+1;
        if(k==y)break;
        k=x*10%n+x*10/n;
        if(!s[k])q[++r]=k,s[k]=s[x]+1;
        if(k==y)break;
        k=x%10*n/10+x/10;
        if(!s[k])q[++r]=k,s[k]=s[x]+1;
        if(k==y)break;
    }
    printf("%d",s[q[r]]-1);
    return 0;
}
