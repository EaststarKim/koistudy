#include <stdio.h>
#define M 1000000007
int a[6010],D[6010];
int main(){
    int i,j,n,l,u,q,x,s;
    scanf("%d%d%d",&n,&l,&u);
    D[0]=1;
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        for(j=u;j>=a[i];--j)D[j]=(D[j]+D[j-a[i]])%M;
    }
    scanf("%d",&q);
    for(i=1;i<=q;++i){
        scanf("%d",&x);
        if(x==1){
            scanf("%d",&x);
            a[++n]=x;
            for(j=u;j>=x;--j)D[j]=(D[j]+D[j-x])%M;
        }
        else if(x==2){
            scanf("%d",&x);
            if(a[x]){
                for(j=a[x];j<=u;++j)D[j]=(D[j]-D[j-a[x]])%M;
                a[x]=0;
            }
        }
        else{
            s=0;
            for(j=l;j<=u;++j)s=(s+D[j])%M;
            printf("%d\n",(s+M)%M);
        }
    }
    return 0;
}
