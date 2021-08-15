#include <stdio.h>
int D[31]={1};
int main()
{
    int i,j,n,k,s;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;++i){
        for(j=1;j<4;++j)D[i+j]+=D[i];
    }
    s=D[k-1]*D[n-k-1];
    if(k>1)s+=D[k-2]*D[n-k-1];
    if(k<n-1)s+=D[k-1]*D[n-k-2];
    printf("%d",s);
    return 0;
}
