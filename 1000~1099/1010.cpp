#include <stdio.h>
int main(){
    int i,n,m,k,mx=-1,s=0,mn=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        s+=k*50-m;
        if(mx<s-mn+m-100)mx=s-mn+m-100;
        if(mn>s)mn=s;
    }
    printf("%d",mx);
    return 0;
}
