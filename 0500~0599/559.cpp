#include <stdio.h>
#include <algorithm>
int n,m,k[2010],kk[4000010];
bool b_s(int x)
{
    int l=0,r=n*n;
    while(l<r)
    {
        int i=(l+r)/2;
        if(kk[i]==x)return true;
        else if(kk[i]<x)l=i+1;
        else r=i;
    }
    return false;
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i)scanf("%d",&k[i]);
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)kk[i*n+j]=k[i]+k[j];
    }
    std::sort(kk,kk+n*n);
    bool f=false;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            if(b_s(m-k[i]-k[j]))f=true;
        }
    }
    if(f)puts("YES");
    else puts("NO");
    return 0;
}
