#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int i,a;
    bool operator<(const data&r)const{
        return a<r.a;
    }
}t[510];
int a[510],l[510],cnt[510],ans[510],n,k,mx,flag,an;
void back(int p,int s){
    int i;
    if(an==mx){
        flag=1;
        return;
    }
    for(i=p+1;i<=n;++i)if(t[p].i<t[i].i&&l[t[p].i]==l[t[i].i]+1){
        if(s+cnt[t[i].i]<k)s+=cnt[t[i].i];
        else{
            ans[++an]=t[i].a;
            back(i,s);
            break;
        }
    }
}
int main(){
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)scanf("%d",a+i),t[i].i=i,t[i].a=a[i];
    for(i=n;i>0;--i){
        for(j=i+1;j<=n;++j)if(a[i]<a[j])l[i]=max(l[i],l[j]);
        for(j=i+1;j<=n;++j)if(a[i]<a[j]&&l[i]==l[j])cnt[i]+=cnt[j];
        if(!cnt[i])++cnt[i];
        ++l[i];
        mx=max(mx,l[i]);
    }
    sort(t+1,t+n+1);
    l[0]=mx+1;
    back(0,0);
    if(flag){
        printf("%d\n",mx);
        for(i=1;i<=mx;++i)printf("%d ",ans[i]);
    }
    else puts("-1");
    return 0;
}
