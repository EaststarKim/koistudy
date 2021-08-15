#include <stdio.h>
#include <algorithm>
using namespace std;
int m[20010];
int p[4][20010],a[20010],b[20010];
bool cmp1(int a,int b){
     int i,s=0;
     for(i=0;i<4;++i)s+=p[i][a]>p[i][b];
     if(s==2)return true;
     return s<2;
}
int cmp2(int a,int b){
     int i,s=0;
     for(i=0;i<4;++i)s+=p[i][a]>p[i][b];
     if(s==2)return false;
     return s<2;
}
int main(){
    int i,j,n,t;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&t);
        m[i]=a[i]=b[i]=t;
    }
    sort(m+1,m+n+1);
    for(i=1;i<=n;++i)a[i]=b[i]=lower_bound(m+1,m+n+1,a[i])-m;
    for(i=1;i<=n;++i)p[0][a[i]]=i;
    for(i=1;i<4;++i){
        for(j=1;j<=n;++j){
            scanf("%d",&t);
            t=lower_bound(m+1,m+n+1,t)-m;
            p[i][t]=j;
        }
    }
    sort(a+1,a+n+1,cmp1);
    sort(b+1,b+n+1,cmp2);
    for(i=1;i<=n;++i)if(a[i]!=b[i])break;
    if(i>n)for(i=1;i<=n;++i)printf("%d ",m[a[i]]);
    else puts("impossible");
    return 0;
}
