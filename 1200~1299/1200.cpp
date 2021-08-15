#include <stdio.h>
int a[110],s[110];
int main(){
    int i,j,n,m,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d",a+i);
    for(i=1;i<=m;++i){
        s[a[i]]+=n;
        for(j=1;j<=n;++j){
            scanf("%d",&k);
            s[j]+=a[i]==k;
            s[a[i]]-=a[i]==k;
        }
    }
    for(i=1;i<=n;++i)printf("%d\n",s[i]);
    return 0;
}
