#include <stdio.h>
#include <string.h>
char a[2010];
int b[2010],n;
int y[2010],x[810][2010],sz[810];
long long t[19]={1},ans;
long long f(){
    int i,j,k,l,u,ch;
    long long s=0;
    for(i=809;i;){
        if(n<sz[i]){
            --i;
            continue;
        }
        ch=1;
        if(n==sz[i]){
            for(k=n;k--;){
                if(x[i][k]==b[k])continue;
                if(x[i][k]>b[k])ch=-1;
                break;
            }
            if(k==-1){
                ++s;
                break;
            }
            if(ch<0){
                --i;
                continue;
            }
        }
        if(b[n-1]>x[i][sz[i]-1])ch=1;
        else if(b[n-1]==x[i][sz[i]-1]){
            ch=1;
            for(k=n,l=sz[i];k--&&l--;){
                if(x[i][l]==b[k])continue;
                if(x[i][l]>b[k])ch=-1;
                break;
            }
        }
        else ch=-1;
        if(ch==1)k=n-1,s+=t[n-sz[i]];
        else k=n-2,s+=t[n-sz[i]-1];
        k-=sz[i]-1;
        for(j=u=0;j<sz[i];++j,++k){
            b[k]-=x[i][j]+u;
            if(b[k]<0)b[k]+=10,u=1;
            else u=0;
        }
        if(u==1){
            for(;!b[k];++k)b[k]=9;
            --b[k];
        }
        for(;n&&!b[n-1];--n);
    }
    return s;
}
int main(){
    int i,j;
    sz[1]=x[1][0]=1;
    for(i=2;i<810;++i){
        for(j=0;j<sz[i-1];++j)y[j]=x[i-1][j]*i;
        for(j=0;j<sz[i-1];++j)x[i][j]=y[j]%10,y[j+1]+=y[j]/10;
        for(sz[i]=sz[i-1];y[j];++j){
            x[i][j]=y[j]%10,y[j+1]+=y[j]/10;
            ++sz[i];
        }
    }
    for(i=1;i<19;++i)t[i]=t[i-1]*10;
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n;++i)b[n-1-i]=a[i]-48;
    for(i=0;!b[i];++i)b[i]=9;
    --b[i];
    for(;n&&!b[n-1];--n);
    ans-=f();
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n;i++)b[n-1-i]=a[i]-48;
    ans+=f();
    printf("%lld",ans);
    return 0;
}
