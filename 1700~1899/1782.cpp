#include <stdio.h>
int d[200010],q[200010],f,r=1;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    d[n]=1;
    q[1]=n;
    while(f<r){
        n=q[++f];
        if(n==k)break;
        if(n<k&&!d[n*2])d[n*2]=d[n]+1,q[++r]=n*2;
        if(n&&!d[n-1])d[n-1]=d[n]+1,q[++r]=n-1;
        if(n<k&&!d[n+1])d[n+1]=d[n]+1,q[++r]=n+1;
    }
    printf("%d",d[k]-1);
    return 0;
}
