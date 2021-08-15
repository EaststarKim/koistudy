#include <stdio.h>
int a[110];
int main()
{
    int i,j,k,m,r,cnt;
    scanf("%d%d",&k,&m);
    for(i=1;i<=m;++i){
        scanf("%d",&r);
        cnt=0;
        for(j=1;j<=k;++j){
            if(!a[j])++cnt;
            if(cnt==r)a[j]=1,cnt=0;
        }
    }
    for(i=1;i<=k;++i)if(!a[i])printf("%d\n",i);
    return 0;
}
