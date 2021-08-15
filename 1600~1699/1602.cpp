#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 1000000009
struct data{
    int s,i;
    bool operator<(const data&r)const{
        if(s==r.s)return i<r.i;
        return s<r.s;
    }
}a[100010];
int s[100010],D[100010],n;
int getsum(int k){
    int sum=0;
    while(k)sum=(sum+D[k])%M,k-=k&-k;
    return sum;
}
void update(int k,int v){while(k<=n)D[k]=(D[k]+v)%M,k+=k&-k;}
int main(){
    int i,j,ans;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",s+i),s[i]+=s[i-1],a[i]={s[i],i};
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i){
        data tmp={s[i],i};
        j=lower_bound(a+1,a+n+1,tmp)-a;
        ans=getsum(j)+(s[i]>=0);
        update(j,ans);
    }
    printf("%d",ans);
    return 0;
}
