#include <stdio.h>
int a[10000],b[10000],l[10000],r[10000];
long long f(int x,int y){
    if(y==1)return 1;
    if(y<3)return 2;
    return f(x+1,l[r[x]-1]-x-1)*f(l[r[x]-1],x+y-l[r[x]-1]);
}
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",a+i);
    for(i=0;i<n;++i)scanf("%d",b+i);
    for(i=0;i<n;++i){
        for(j=0;j<n;++j)if(a[i]==b[j])r[i]=j,l[j]=i;
    }
    printf("%lld",f(0,n));
    return 0;
}
