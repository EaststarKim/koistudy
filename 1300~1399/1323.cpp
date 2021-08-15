#include <stdio.h>
#include <algorithm>
using namespace std;
int a[5010],t[5010],n;
void quick(int s,int e){
    int i,l=s+1,r=e;
    if(s>=e)return;
    while(1){
        while(a[s]>=a[l]&&l<e)++l;
        while(a[s]<=a[r]&&r>s)--r;
        if(l<r)swap(a[l],a[r]);
        else break;
    }
    swap(a[s],a[r]);
    quick(s,r-1);
    quick(r+1,e);
    for(i=1;i<=n;++i)if(t[i]!=a[i])break;
    if(i<=n){
        for(i=1;i<=n;++i)printf("%d ",a[i]);
        puts("");
    }
    for(i=1;i<=n;++i)t[i]=a[i];
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=2;i<=n;++i)if(a[i]<a[i-1])break;
    if(i>n)puts("OK");
    else quick(1,n);
    return 0;
}
