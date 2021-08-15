#include <stdio.h>
int a[100010];
int main(){
    int i,j,n,mx=0,mi;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j*j<i;++j)if(i%j==0)a[i]+=2;
        if(j*j==i)++a[i];
        if(mx<a[i])mx=a[i],mi=i;
    }
    printf("%d",n-mi+1);
    return 0;
}
