#include <stdio.h>
int s[10010],e[10010],a[10010],b[10010],ans;
int main(){
    int i,j,k,l,n,m,p,q,r,x,y,cnt=1,t;
    scanf("%d%d%d%d%d",&n,&m,&p,&q,&r);
    s[1]=1,e[1]=n;
    for(i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        for(j=1;e[j]-s[j]+1<=x;++j)x-=e[j]-s[j]+1,y-=e[j]-s[j]+1;
        for(k=j;e[k]-s[k]+1<=y;++k)y-=e[k]-s[k]+1;
        t=0;
        a[++t]=s[k]+y,b[t]=e[k];
        for(l=k+1;l<=cnt;++l)a[++t]=s[l],b[t]=e[l];
        a[++t]=s[j]+x;
        if(j==k)b[t]=s[j]+y-1;
        else b[t]=e[j];
        for(l=j+1;l<k;++l)a[++t]=s[l],b[t]=e[l];
        if(y&&j!=k)a[++t]=s[k],b[t]=s[k]+y-1;
        for(l=1;l<j;++l)a[++t]=s[l],b[t]=e[l];
        if(x)a[++t]=s[j],b[t]=s[j]+x-1;
        cnt=t;
        for(l=1;l<=t;++l)s[l]=a[l],e[l]=b[l];
    }
    for(i=1;e[i]-s[i]+1<p;++i)p-=e[i]-s[i]+1,q-=e[i]-s[i]+1;
    if(s[i]+p-1<=r){
        if(e[i]<=r)ans+=e[i]-s[i]-p+2;
        else ans+=r-s[i]-p+2;
    }
    for(j=i;e[j]-s[j]+1<q;++j)q-=e[j]-s[j]+1;
    if(j!=i&&s[j]<=r){
        if(s[j]+q-1<=r)ans+=q;
        else ans+=r-s[i]+1;
    }
    for(++i;i<j;++i)if(s[i]<=r){
        if(e[i]<=r)ans+=e[i]-s[i]+1;
        else ans+=r-s[i]+1;
    }
    printf("%d",ans);
    return 0;
}
