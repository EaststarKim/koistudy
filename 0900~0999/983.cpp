#include <stdio.h>
int D[25010]={1},sum;
int main()
{
    int i,j,a,b,s,e;
    scanf("%d%d%d%d",&a,&b,&s,&e);
    a-=b;
    if(a<0)a=-a;
    for(i=s;i<=e;++i){
        sum+=i;
        for(j=sum;j>=s;--j)if(D[j-i])D[j]=1;
    }
    sum-=a;
    if(sum<0||sum%2||!D[sum/2])puts("0");
    else puts("1");
    return 0;
}
