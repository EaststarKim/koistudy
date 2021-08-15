#include <stdio.h>
int a[30],chk[128],t[128],ans;
int main(){
    int i,j,r,l,k;
    scanf("%d%d",&r,&l);
    for(i=0;i<r;++i)for(j=0;j<l;++j)scanf("%d",&k),a[i]+=k<<j;
    chk[a[0]]=1;
    for(i=1;i<r;++i){
        t[a[i]]=1;
        for(j=0;j<(1<<l);++j)if(chk[j])t[j^a[i]]=1;
        for(j=0;j<(1<<l);++j)chk[j]=t[j],t[j]=0;
    }
    for(i=0;i<(1<<l);++i)ans+=chk[i];
    printf("%d",ans);
    return 0;
}
