#include <stdio.h>
#define M 1000000007
int D[1000010]={1};
int main()
{
    int i,j,n,k,s;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;++i){
        for(j=1;j<4;++j)D[i+j]=(D[i+j]+D[i])%M;
    }
    s=(long long)D[k-1]*D[n-k-1]%M;
    if(k>1)s=(s+(long long)D[k-2]*D[n-k-1])%M;
    if(k<n-1)s=(s+(long long)D[k-1]*D[n-k-2])%M;
    printf("%d",s);
    return 0;
}
