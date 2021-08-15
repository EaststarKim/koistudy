#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y;
    data(){}data(int x,int y):x(x),y(y){}
}a[5010];
bool cmp(data p,data q){return p.x==q.x?p.y<q.y:p.x<q.x;}
int f(int l,int r,data p){
    int m;
    while(l<=r){
        m=(l+r)/2;
        if(a[m].x==p.x&&a[m].y==p.y)return 1;
        if(cmp(a[m],p))l=m+1;
        else r=m-1;
    }
    return 0;
}
int main(){
    int i,j,n,cnt=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;++i){
        for(j=i+1;j<=n;++j)if(a[i].x<a[j].x&&a[i].y<a[j].y)
            cnt+=f(i,j,data(a[i].x,a[j].y))&f(i,j,data(a[j].x,a[i].y));
    }
    printf("%d",cnt);
    return 0;
}
