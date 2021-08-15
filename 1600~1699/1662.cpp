#include <stdio.h>
#include <string.h>
const int M=2010;
char a[M];
int b[M],n;
int y[M],x[810][M],sz[810];
long long ans;
long long f(){
    int i,j,k,l,u,ch;
    long long s=0;
    for(i=808;i;--i)if(n>=sz[i]){
        int l=1,r=i,m,p,t=0;
        while(l<=r){
            m=(l+r)/2,ch=1;
            for(j=sz[i];j<M;++j)y[j]=0;
            for(j=0;j<sz[i];++j)y[j]=x[i][j]*m;
            for(p=0;p<sz[i]||y[p];++p)y[p+1]+=y[p]/10,y[p]%=10;
            if(n<p)ch=0;
            else if(n==p){
                for(j=n;j--;){
                    if(y[j]==b[j])continue;
                    ch=(y[j]<b[j]);
                    break;
                }
            }
            if(!ch)r=m-1;
            else l=m+1,t=m;
        }
        if(!t)continue;
        s+=t;
        for(j=sz[i];j<M;++j)y[j]=0;
        for(j=0;j<sz[i];++j)y[j]=x[i][j]*t;
        for(p=0;p<sz[i]||y[p];++p)y[p+1]+=y[p]/10,y[p]%=10;
        for(j=u=0;j<p;++j){
            b[j]-=y[j]+u;
            if(b[j]<0)b[j]+=10,u=1;
            else u=0;
        }
        b[j]-=u;
        for(;n&&!b[n-1];--n);
    }
    return s;
}
int main(){
    int i,j;
    sz[1]=x[1][0]=1;
    for(i=2;i<809;++i){
        for(j=0;j<sz[i-1];++j)y[j]=x[i-1][j]*i;
        for(j=0;j<sz[i-1]||y[j];++j)y[j+1]+=y[j]/10,x[i][j]=y[j]%10;
        sz[i]=j;
    }
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n;++i)b[n-1-i]=a[i]-48;
    for(i=0;!b[i];++i)b[i]=9;
    --b[i];
    for(;n&&!b[n-1];--n);
    ans-=f();
    scanf("%s",a);
    for(j=0;a[j]==48;++j);
    n=strlen(a+j);
    for(i=0;i<n;i++)b[n-1-i]=a[i+j]-48;
    ans+=f();
    printf("%lld",ans);
    return 0;
}
