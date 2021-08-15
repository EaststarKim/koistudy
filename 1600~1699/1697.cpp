#include <stdio.h>
double p[200010],a[200010],b[200010],ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%lf",p+i);
    for(i=1;i<=n;++i){
        a[i]=p[i]*(a[i-1]+b[i-1]);
        b[i]=p[i]*(b[i-1]+1);
        ans+=p[i]+6*a[i];
    }
    printf("%.3f",ans);
    return 0;
}
