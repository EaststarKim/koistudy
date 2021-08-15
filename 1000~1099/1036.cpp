#include <stdio.h>
struct data{
    int s,cnt,m;
}a[1000010];
long long sum;
int cnt;
int main()
{
    int i,j,k,n,q;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i)scanf("%d",&a[i].s);
    for(i=1;i<=q;++i){
        scanf("%d%d",&j,&k);
        ++a[j].cnt;
        --a[j+k].cnt;
        a[j+k].m+=k;
    }
    for(i=1;i<=n;++i){
        cnt+=a[i].cnt;
        sum+=cnt-a[i].m;
        printf("%lld ",a[i].s+sum);
    }
    return 0;
}
