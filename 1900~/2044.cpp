#include <stdio.h>
int w[20010],d[20010],a[20010],b[20010],ans=21e8;
void f(int s,int e,int l,int r){
    if(s>e||l>r)return;
    int i,m=(s+e)/2,p,D=21e8;
    for(i=(m+1>l?m+1:l);i<=r;++i)if(D>a[i]+b[i]-w[m]*(d[i]-d[m]))D=a[i]+b[i]-w[m]*(d[i]-d[m]),p=i;
    f(s,m-1,l,p);
    f(m+1,e,p,r);
    if(ans>D)ans=D;
}
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",w+i,d+i+1),w[i]+=w[i-1],d[i+1]+=d[i];
    for(i=1;i<=n;++i)a[i]=a[i-1]+w[i-1]*(d[i]-d[i-1]);
    for(i=n;i;--i)b[i]=b[i+1]+(w[i+1]-w[i])*(d[n+1]-d[i+1]);
    f(1,n-1,2,n);
    printf("%d",ans);
    return 0;
}
