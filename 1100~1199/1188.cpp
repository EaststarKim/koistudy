#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y,i;
}a[100010];
bool cmpx(data a,data b){return a.x<b.x;}
bool cmpy(data a,data b){return a.y>b.y;}
int s[4],t[4],bit[100010],n,ans=-1<<31;
int getsum(int k){
    int s=0;
    while(k)s+=bit[k],k-=k&-k;
    return s;
}
void update(int k){
    while(k<=n)++bit[k],k+=k&-k;
}
int main(){
    int i,j,sum;
    scanf("%d",&n);
    for(i=0;i<4;++i)scanf("%d",t+i);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmpy);
    for(i=1;i<=n;++i)a[i].i=i;
    sort(a+1,a+n+1,cmpx);
    for(i=1;i<=n;++i){
        s[1]=getsum(a[i].i);
        s[0]=a[i].i-s[1]-1;
        s[2]=i-s[1]-1;
        s[3]=n-i-s[0];
        sum=0;
        for(j=0;j<4;++j)sum+=s[j]*t[j];
        if(sum>ans)ans=sum;
        update(a[i].i);
    }
    printf("%d",ans);
    return 0;
}
