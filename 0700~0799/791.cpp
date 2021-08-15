#include <stdio.h>
int D[51][751]={{1}},s;
int main(){
    int i,j,k,n,w;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&w);
        s+=w;
        for(j=0;j<(n+1)/2;++j){
            for(k=0;k<751-w;++k)if(D[j][k])D[j+1][k+w]=1;
        }
    }
    for(i=s/2;i>0;--i)if(D[(n+1)/2][i])break;
    if(n==1)printf("%d",s);
    else printf("%d",i);
    return 0;
}
