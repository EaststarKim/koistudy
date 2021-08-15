#include <stdio.h>
#include <algorithm>
using namespace std;
#define M (1<<15)
int a[3010],cnt[M*2];
int main(){
    int i,j,n,t;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),++cnt[a[i]+M];
    sort(a+1,a+n+1);
    for(i=1;i<n;++i){
        for(j=i+1;j<=n;++j){
            t=-a[i]-a[j];
            if(-M<=t&&t<M&&cnt[t+M]-(a[i]==t)-(a[j]==t)>0){
                printf("%d %d %d",a[i],a[j],t);
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
