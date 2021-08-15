#include <stdio.h>
int a[1010][6],cnt[1010]={-1},m1,m2;
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<6;++j)scanf("%d",a[i]+j);
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            for(k=1;k<6;++k)if(a[i][k]==a[j][k]){
                    ++cnt[i],++cnt[j];
                    break;
            }
        }
    }
    for(i=1;i<=n;++i){
        if(cnt[m1]<cnt[i])m2=m1,m1=i;
        else if(cnt[m2]<cnt[i])m2=i;
    }
    printf("%d %d",m1,m2);
    return 0;
}
