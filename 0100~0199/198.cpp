#include <stdio.h>   
#include <math.h>   
long long int a[2][2001];   
int chk[2001]={0,1};   
int main()   
{   
    int i,j,k,n,mi,mj;   
    double s=0,mn,m;   
    scanf("%d",&n);   
    for(i=1;i<=n;++i)scanf("%lld%lld",&a[0][i],&a[1][i]);   
       
        for(j=1;j<=n;++j)   
        {   
            if(chk[j])   
            {   
                mn=200000000;   
                for(k=1;k<=n;++k)   
                {   
                    m=sqrt(double(((a[0][j]-a[0][k])*(a[0][j]-a[0][k])+(a[1][j]-a[1][k])*(a[1][j]-a[1][k]))));   
                    if(j!=k&&mn>m&&!chk[k])mn=m,mi=j,mj=k;   
                }   
                s+=mn;   
                chk[mj]=1;   
            }   
        }   
    printf("%lf",s);   
    return 0;   
}  