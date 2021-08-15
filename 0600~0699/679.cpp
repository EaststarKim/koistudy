#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int p[10000],a[10],b[10],pn=1,ans;
double s=1e9,t;
void f(int k,int l){
    int i,j,x=k,y=l;
    for(i=0;y;++i)a[i]=x%10,x=x/10,b[i]=y%10,y=y/10;
    sort(a,a+i);
    sort(b,b+i);
    for(j=0;j<i;++j)if(a[j]!=b[j])break;
    t=(double)k/l;
    if(j==i&&s>t)ans=k,s=t;
}
int main(){
    int i,j,n,m,k,l,flag;
    scanf("%d",&n);
    p[1]=2;
    m=sqrt(n);
    for(i=3;i<=m*3;i+=2){
        flag=1;
        k=sqrt(i);
        for(j=1;p[j]<=k&&j<=pn;j++)if(i%p[j]==0){
            flag=0;
            break;
        }
        if(flag)p[++pn]=i;
    }
    for(i=1;i<=pn;++i){
        if(p[i]>m)break;
        for(j=i;j<=pn;++j){
            k=p[i]*p[j];
            if(k>n)break;
            l=p[i]+p[j]-1;
            if(l%9==0)f(k,k-l);
        }
    }
    printf("%d",ans);
    return 0;
}
