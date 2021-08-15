#include <stdio.h>
#include <algorithm>
using namespace std;
int n,a[10010],flag,s,e;
void back(int t)
{
    int i,j,k;
    for(i=1;i<=n;++i)if(a[i]!=i)break;
    for(j=n;j>0;--j)if(a[j]!=j)break;
    for(k=i;k<=j;++k)if(a[k]!=i+j-k)break;
    if(k>j){
        s=i;
        e=j;
        if(!t)printf("%d %d\n1 1",i,j);
        flag=1;
        return;
    }
    if(t)return;
    for(k=1;k<=n;++k)if(a[k]==i)break;
    if(i>k)swap(i,k);
    reverse(a+i,a+k+1);
    back(1);
    if(flag){
        printf("%d %d\n%d %d",i,k,s,e);
        return;
    }
    reverse(a+i,a+k+1);
    for(k=1;k<=n;++k)if(a[k]==j)break;
    if(j>k)swap(j,k);
    reverse(a+j,a+k+1);
    back(1);
    printf("%d %d\n%d %d",j,k,s,e);
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        if(i!=a[i])flag=1;
    }
    if(flag)
    {
        flag=0;
        back(0);
    }
    else printf("1 1\n1 1");
    return 0;
}
