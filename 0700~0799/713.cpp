#include <stdio.h>
long long D[11][1025];
int chk[1024][1024],n;
void back(int k,int p,int s){
    if(p==n){
        chk[k][s]=1;
        return;
    }
    if(k&(1<<p))back(k,p+1,s);
    else{
        if(p<n-1&&!(k&(1<<(p+1))))back(k,p+2,s);
        back(k,p+1,s+(1<<p));
    }
}
int main()
{
    int i,j,k,t;
    scanf("%d",&n);
    if(n%2){
        printf("-1");
        return 0;
    }
    t=1<<n;
    for(i=0;i<t;++i)back(i,0,0);
    D[1][0]=1;
    for(i=1;i<=n;++i){
        for(j=0;j<t;++j){
            if(D[i][j]){
                for(k=0;k<t;++k){
                    if(chk[j][k])D[i+1][k]+=D[i][j];
                }
            }
        }
    }
    printf("%lld",D[n+1][0]);
    return 0;
}
