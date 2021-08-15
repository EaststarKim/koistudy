#include <stdio.h>
#include <algorithm>
#define SZ 100010
using namespace std;
struct data{
    int i,s;
    bool operator<(const data&r)const{
        if(s==r.s)return i<r.i;
        return s<r.s;
    }
}a[SZ];
int idx[SZ],bit[SZ],n;
long long ans;
void getsum(int k){while(k)ans+=bit[k],k-=k&-k;}
void update(int k){while(k<=n)++bit[k],k+=k&-k;}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",&a[i].s),a[i].i=i;
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i)idx[a[i].i]=i;
    for(i=n;i>0;--i){
        j=idx[i];
        update(j);
        getsum(j);
    }
    printf("%.2lf",(double)ans/n);
    return 0;
}
