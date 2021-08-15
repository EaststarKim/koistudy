#include <stdio.h>
#include <algorithm>
struct data{
    int s,e;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}a[151];
int D[151][151]={{1}},ans;
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].s,&a[i].e);
    std::sort(a+1,a+n+1);
    for(i=1;i<=n;++i){
        for(j=0;j<i;++j){
            for(k=0;k<i;++k)if(D[j][k]){
                if(a[j].e<=a[i].s&&D[j][k]+1>D[i][k])D[i][k]=D[j][k]+1;
                if(a[k].e<=a[i].s&&D[j][k]+1>D[j][i])D[j][i]=D[j][k]+1;
            }
        }
    }
    for(i=0;i<=n;++i){
        for(j=0;j<=n;++j)if(ans<D[i][j])ans=D[i][j];
    }
    printf("%d",ans-1);
    return 0;
}
