#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int n;
double ans;
struct data{
    double x,y;
}a[100010];
bool cmpx(data aa,data bb){
    if(aa.x!=bb.x)return aa.x<bb.x;
    return aa.y<bb.y;
}
bool cmpy(data aa,data bb){
    if(aa.y!=bb.y)return aa.y<bb.y;
    return aa.x<bb.x;
}
double d(data aa,data bb){return sqrt((aa.x-bb.x)*(aa.x-bb.x)+(aa.y-bb.y)*(aa.y-bb.y));}
double f(int l,int r){
    if(l==r)return ans;
    if(l+1==r)return d(a[l],a[r]);
    double mn1,mn2,mn,Min;
    int i,j,k,p,m=(l+r)/2;
    mn1=f(l,m);
    mn2=f(m+1,r);
    ans=mn=Min=min(mn1,mn2);
    for(i=m-1;i>=l;--i)if(a[m].x-mn>a[i].x)break;
    l=i+1;
    for(i=m+1;i<=r;++i)if(a[i].x>a[m].x+mn)break;
    r=i-1;
    sort(a+l,a+r+1,cmpy);
    for(i=j=l;j<=r;++j){
        while(a[j+1].y<a[i].y+mn&&j+1<=r)++j;
        for(k=i;k<=j;++k){
            for(p=k+1;p<=j;++p)Min=min(Min,d(a[k],a[p]));
        }
    }
    sort(a+l,a+r+1,cmpx);
    return Min;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
    sort(a+1,a+1+n,cmpx);
    ans=d(a[1],a[2]);
    printf("%.lf",f(1,n));
    return 0;
}
