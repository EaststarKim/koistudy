#include <stdio.h>   
#include <math.h>   
int a[201]={0,1},b[30001]={1};   
int main()   
{   
    int i,j,k,n,m,p,q;   
    scanf("%d",&n);   
    for(i=n;i>0;--i)   
    {   
        m=(int)sqrt(n);   
        p=1;   
        for(j=2;j<m;++j)   
        {   
            if(i%j==0)a[++p]=j;   
        }   
        q=p;   
        if(i%m==0)a[++p]=m;   
        for(j=q;j>1;--j)a[++p]=i/a[j];   
        for(j=1;j<=p;++j)   
        {   
            for(k=i;k>=0;--k)   
            {   
                if(b[k])b[k+a[j]]=1;   
            }   
        }   
        if(b[i])   
        {   
            printf("%d",i);   
            break;   
        }   
        for(j=1;j<=n;++j)b[j]=0;   
    }   
    return 0;   
}  