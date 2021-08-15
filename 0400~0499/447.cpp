#include <stdio.h>   
#include <math.h>   
int a[1000001],b[1000001];   
int main()   
{   
    int i,n,t=1;   
    scanf("%d",&n);   
    while(t<n*2)t*=2;   
    t/=2;   
    while(t)   
    {   
        for(i=1;i<=n;++i)   
        {   
            if(i+t>n&&i+t<=n*2&&!a[i+t-n]&&!b[i])   
            {   
                a[i+t-n]=1;   
                b[i]=i+t;   
            }   
        }   
        t/=2;   
    }   
    for(i=1;i<=n;++i)printf("%d %d\n",i,b[i]);   
    return 0;   
}  