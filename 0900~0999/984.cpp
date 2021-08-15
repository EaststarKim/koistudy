#include <stdio.h>
const int MX=1e9;
int D[10010];
int main()
{
    int i,j,e,f,n,p,w;
    scanf("%d%d%d",&e,&f,&n);
    f-=e;
    for(i=1;i<=f;++i)D[i]=MX;
    D[0]=1;
    for(i=1;i<=n;++i){
        scanf("%d%d",&p,&w);
        for(j=0;j<=f-w;++j){
            if(D[j]!=MX&&D[j+w]>D[j]+p)D[j+w]=D[j]+p;
        }
    }
    if(D[f]==MX)puts("-1");
    else printf("%d",D[f]-1);
    return 0;
}
