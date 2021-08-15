#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1010],ans[2][4],n,flag;
void back(int p){
    int i,j,k;
    if(!p){
        for(i=1;i<=n&&a[i]==i;++i);
        if(i>n){
            for(i=3;i>0;--i)printf("%d %d\n",ans[0][i],ans[1][i]);
            flag=1;
        }
        return;
    }
    for(i=1;i<=n&&a[i]==i;++i);
    for(j=n;j>0&&a[j]==j;--j);
    if(i>n){
        ans[0][p]=ans[1][p]=1;
        back(p-1);
        if(flag)return;
    }
    else{
        for(k=1;k<=n&&a[k]!=i;++k);
        if(i>k)swap(i,k);
        reverse(a+i,a+k+1);
        ans[0][p]=i;
        ans[1][p]=k;
        back(p-1);
        reverse(a+i,a+k+1);
        if(flag)return;
        for(k=1;k<=n&&a[k]!=j;++k);
        if(j>k)swap(j,k);
        reverse(a+j,a+k+1);
        ans[0][p]=j;
        ans[1][p]=k;
        back(p-1);
        reverse(a+j,a+k+1);
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    back(3);
    return 0;
}
