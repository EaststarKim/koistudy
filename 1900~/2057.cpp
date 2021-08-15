#include <stdio.h>
int a[1000010]={1},t[1000010]={1},l,p;
char c[1000010];
int main(){
    int i,n,m,ans=1;
    scanf("%d%d",&n,&m);
    scanf("%s",c+1);
    for(i=1;i<=n;++i)a[i]=(a[i-1]+t[i-1])%m,t[i]=(t[i-1]*(2-i%2))%m;
    for(i=1;i<=n;++i){
        if(c[i]=='L')++l,p-=!!p;
        else ans=l<2?(ans+(l?t[n-i]:a[n-i]))%m:ans,l-=!!l,++p;
    }
    printf("%d",ans);
    return 0;
}
