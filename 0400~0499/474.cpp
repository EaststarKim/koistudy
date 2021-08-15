#include <stdio.h>      
#include <math.h>      
long long int a[5][41];      
int main()      
{      
    int i,j,k,n,m;      
    long long int s=1;      
    scanf("%d",&n);      
    a[2][0]=1;      
    for(i=1;i<=n;++i)      
    {      
        for(j=1;j<5;++j)      
        {      
            if(a[j][i-1])      
            {      
                for(k=1;k<5;++k)a[k][i]+=a[j][i-1];      
                a[j][i]-=a[j][i-1];      
            }      
        }      
    }      
    m=n;      
    while(a[1][n]&&!(a[1][n]%3))      
    {      
        a[1][n]/=3;      
        --m;      
    }   
    if(!a[1][n])printf("0");   
    else  
    {     
        for(i=1;i<=m;++i)s*=3;   
        printf("%lld/%lld",a[1][n],s);   
    }   
    return 0;      
}