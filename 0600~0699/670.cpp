#include <stdio.h>
int a[500010],bit[500010],n;
long long cnt;
int main()
{
    int i,j,s;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",a+i);
        s=0;
        for(j=a[i];j>0;j-=j&-j)s+=bit[j];
        cnt+=i-s;
        for(j=a[i];j<=n;j+=j&-j)bit[j]++;
    }
    printf("%lld",cnt);
    return 0;
}
