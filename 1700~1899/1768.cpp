#include <stdio.h>
int a[100010],st[100010][17];
int main(){
    int i,j,n,l,q,s,e;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    scanf("%d",&l);
    for(i=j=1;i<=n;++i){
        for(;j<n&&a[j+1]-a[i]<=l;++j);
        st[i][0]=j;
    }
    for(j=1;j<17;++j){
        for(i=1;i<=n;++i)st[i][j]=st[st[i][j-1]][j-1];
    }
    scanf("%d",&q);
    for(;q--;){
        scanf("%d%d",&s,&e);
        if(s>e)s^=e^=s^=e;
        int ans=1;
        for(i=17;i--;)if(st[s][i]<e)s=st[s][i],ans+=(1<<i);
        printf("%d\n",ans);
    }
    return 0;
}
