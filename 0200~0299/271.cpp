#include <stdio.h>   
int a[161][160];   
int main()   
{   
    int i,j,k,n,mi,mj;   
    double mn;   
    scanf("%d",&n);   
    a[1][0]=1;   
    a[1][1]=1;   
    for(i=2;i<=n;++i)   
    {   
        for(j=1;j<i;++j)   
        {   
            for(k=2;k<=j;++k)   
            {   
                if(i%k==0&&j%k==0)break;   
            }   
            if(k>j)a[i][++a[i][0]]=j;   
        }   
    }   
    printf("0/1\n");   
    while(1)   
    {   
        mn=2;   
        for(i=1;i<=n;++i)   
        {   
            for(j=1;j<=a[i][0];++j)   
            {   
                if(a[i][j]&&mn>(double)a[i][j]/i)   
                {   
                    mn=(double)a[i][j]/i,mi=i,mj=j;   
                    break;   
                }   
            }   
        }   
        if(mn==2)break;   
        printf("%d/%d\n",a[mi][mj],mi);   
        a[mi][mj]=0;   
    }   
    return 0;   
}  