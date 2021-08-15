#include <stdio.h>   
int a[81],n,sw;   
void back(int p)   
{   
    int i,j,k,l;   
    if(p>n)   
    {   
        for(i=1;i<=n;++i)printf("%d",a[i]);   
        sw=1;   
        return;   
    }   
    for(i=1;i<4;++i)   
    {   
        if(i!=a[p-1])   
        {   
            a[p]=i;   
            for(j=2;j<=p/2;++j)   
            {   
                for(k=1;k<=p-j*2+1;++k)   
                {   
                    for(l=0;l<j;++l)   
                    {   
                        if(a[k+l]!=a[k+j+l])break;   
                    }   
                    if(l>=j)break;   
                }   
                if(k<=p-j*2+1)break;   
            }   
            if(j>p/2)back(p+1);   
            if(sw)return;   
        }   
    }   
}   
int main()   
{   
    scanf("%d",&n);   
    back(1);   
    return 0;   
}  