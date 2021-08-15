#include <stdio.h>
int a[1010][1010];
long long s,t;
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            scanf("%d",a[i]+j);
            s+=a[i][j];
        }
    }
    if(n==2){
        puts("1 1");
        return 0;
    }
    s/=(n-1)*2;
    for(i=1;i<=n;++i){
        t=0;
        for(j=1;j<=n;++j)t+=a[i][j];
        printf("%d ",(t-s)/(n-2));
    }
    return 0;
}
