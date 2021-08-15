#include <stdio.h>
#include <algorithm>
using namespace std;
int a[60],b[60],c[60],d[60],as,bs=1,cs=1,ds=2,ans=100;
void f(int* a,int i){
    for(int j=-2;j<3;++j)a[i+j]=!a[i+j];
}
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=c[i]=d[i]=a[i];
    for(i=1;i<4;++i)b[i]=!b[i],d[i]=!d[i];
    for(i=1;i<5;++i)c[i]=!c[i],d[i]=!d[i];
    for(i=3;i<=n;++i){
        if(a[i-2])f(a,i),++as;
        if(b[i-2])f(b,i),++bs;
        if(c[i-2])f(c,i),++cs;
        if(d[i-2])f(d,i),++ds;
    }
    if(!a[n-1]&&!a[n])ans=min(ans,as);
    if(!b[n-1]&&!b[n])ans=min(ans,bs);
    if(!c[n-1]&&!c[n])ans=min(ans,cs);
    if(!d[n-1]&&!d[n])ans=min(ans,ds);
    if(ans==100)ans=-1;
    printf("%d",ans);
    return 0;
}
