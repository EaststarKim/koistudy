#include <stdio.h>
int a[21];
int main(){
    int i,j,n;
    for(;;){
        scanf("%d",&n);
        if(!n)return 0;
        for(i=1;i<=n;++i)scanf("%d",a+i),a[i-1]-=a[i];
        for(i=1;i<n;++i){
            for(j=i+1;j<n;++j)if(a[j]!=a[j-i])break;
            if(j==n)break;
        }
        printf("%d\n",i);
    }
}
