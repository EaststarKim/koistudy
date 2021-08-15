#include <stdio.h>
#include <algorithm>
using namespace std;
int a[2010],d[2010],chk[2010];
int main(){
    int i,j,k,n,q,mn,x,y;
    scanf("%d",&n);
    for(i=1;i<n;++i)scanf("%d",a+i),d[i]=1e9;
    for(i=1;i<n;++i){
        mn=1e9;
        for(j=0;j<n;++j)if(!chk[j]&&mn>d[j])mn=d[j],k=j;
        for(j=1;j<n;++j)if(a[(k-j+n)%n])d[j]=min(d[j],d[k]+a[(k-j+n)%n]);
        chk[k]=1;
    }
    scanf("%d",&q);
    for(;q--;){
        scanf("%d%d",&x,&y);
        x=(y-x+n)%n;
        printf("%d\n",d[x]<1e9?d[x]:-1);
    }
    return 0;
}
