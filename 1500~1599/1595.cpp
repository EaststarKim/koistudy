#include <stdio.h>
#define M 100000007
int D[20000010];
int main(){
    int i,j,a,b;
    long long k,t;
    scanf("%d%d",&a,&b);
    D[a]=1;
    for(i=a;i<b;++i)if(D[i]){
        for(j=11;;++j){
            for(a=i,k=1,t=0;a;k*=j){
                t+=a%10*k;
                a/=10;
            }
            if(t>b)break;
            D[t]=(D[t]+D[i])%M;
        }
    }
    printf("%d",D[b]);
    return 0;
}
