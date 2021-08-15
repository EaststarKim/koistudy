#include <stdio.h>
int a[1010];
int main(){
    int i,j,n,s,ans=2e9;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=0;i<101;++i){
        s=0;
        for(j=1;j<=n;++j){
            if(a[j]<i)s+=(a[j]-i)*(a[j]-i);
            if(a[j]>i+17)s+=(i+17-a[j])*(i+17-a[j]);
        }
        if(s<ans)ans=s;
    }
    printf("%d",ans);
    return 0;
}
