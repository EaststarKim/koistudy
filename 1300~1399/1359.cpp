#include <stdio.h>
int a[21];
int main(){
    int i,j,k,t,n,cnt;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%d",a+i);
        cnt=0;
        for(i=n-1;i;--i){
            for(j=1;j<=n;++j)if(a[j]==i)break;
            for(k=1;k<j;++k)if(a[k]>i)break;
            if(k<j){
                for(k=j-1;k;--k)a[k+1]=a[k];
                a[1]=i;
                ++cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
