#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
struct data{
    int x,y;
    bool operator==(const data&r)const{
        return x==r.x&&y==r.y;
    }
    bool operator<(const data&r)const{
        if(x==r.x)return y<r.y;
        return x<r.x;
    }
}a[100010];
map<data,int> m;
map<data,int> chk;
long long ans[10];
int x[]={-1,-1,0,1,1,1,0,-1,0},y[]={0,1,1,1,0,-1,-1,-1,0};
int main(){
    int i,j,k,n,w,h,r,c,p;
    scanf("%d%d%d",&h,&w,&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i){
        for(j=0;j<9;++j){
            r=a[i].x+x[j],c=a[i].y+y[j];
            if(r>1&&r<h&&c>1&&c<w&&!chk[{r,c}]){
                chk[{r,c}]=1;
                int s=0;
                for(k=0;k<9;++k){
                    data t={r+x[k],c+y[k]};
                    p=lower_bound(a+1,a+n+1,t)-a;
                    if(a[p]==t)++s;
                }
                ++ans[s];
            }
        }
    }
    long long sum=0;
    for(i=1;i<10;++i)sum+=ans[i];
    ans[0]=(long long)(h-2)*(w-2)-sum;
    for(i=0;i<10;++i)printf("%lld\n",ans[i]);
    return 0;
}
