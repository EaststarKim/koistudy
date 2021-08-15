#include <stdio.h>
int a[110],ans;
int gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}
int main()
{
    int i,j,k,n,g;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<n-1;++i){
        for(j=i+1;j<n;++j){
            for(k=j+1;k<=n;++k){
                g=gcd(gcd(a[i],a[j]),a[k]);
                if(ans<g)ans=g;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
