#include <stdio.h>
int a[5010],b[5010],l,m;
int main(){
    int i,j,k,t,n;
    for(i=1;i<=10003;i+=2)a[++l]=i;
    for(i=2;i<=l;++i){
        m=0;
        for(j=1;j<=l;++j){
            if(j%a[i]==0)continue;
            b[++m]=a[j];
        }
        l=m;
        for(j=1;j<=m;++j)a[j]=b[j];
    }
    scanf("%d",&t);
    for(;t--;){
        scanf("%d",&n);
        for(i=1;i<=l;++i)if(a[i]>=n)break;
        printf("%d %d\n",a[i-1],a[i+(a[i]==n)]);
    }
    return 0;
}
