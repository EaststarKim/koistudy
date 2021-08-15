#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int i,s;
    bool operator<(const data&r)const{
        return s>r.s;
    }
}a[510];
int b[510],chk[510],cnt,s;
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<=n;++i)scanf("%d",&a[i].s),a[i].i=i,s+=a[i].s;
    sort(a,a+n+1);
    for(i=0;i<=n;++i){
        if((s-a[i].s)%2)continue;
        for(j=0;j<=n;++j)b[j]=a[j].s;
        b[i]=0;
        for(j=1;j<=n;++j){
            sort(b,b+n+1);
            for(k=n-1;b[n]&&k&&b[k];--k)--b[n],--b[k];
            if(b[n])break;
        }
        if(j>n)chk[a[i].i]=1,++cnt;
    }
    printf("%d\n",cnt);
    for(i=0;i<=n;++i)if(chk[i])printf("%d\n",i+1);
    return 0;
}
