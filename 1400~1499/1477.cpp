#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010],b[100010],s[100010],n,p;
int bit[100010],ans[100010];
int getsum(int k){
    int sum=0;
    while(k)sum+=bit[k],k-=k&-k;
    return sum;
}
void update(int k,int v){while(k<=n)bit[k]+=v,k+=k&-k;}
int main(){
    int i,j,l,r,m;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
    sort(b+1,b+n+1);
    for(i=1;i<=n;++i)if(b[i]!=b[i-1])b[++p]=b[i];
    for(i=1;i<=n;++i){
        a[i]=(lower_bound(b+1,b+p+1,a[i])-b);
        update(a[i],1);
    }
    for(i=1;i<=n;++i)scanf("%d",s+i);
    for(i=n;i;--i){
        l=1,r=p;
        while(l<=r){
            m=(l+r)/2;
            if(getsum(m)-1<s[i])l=m+1;
            else j=m,r=m-1;
        }
        ans[i]=b[j];
        update(j,-1);
    }
    for(i=1;i<=n;++i)printf("%d\n",ans[i]);
    return 0;
}
