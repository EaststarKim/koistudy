#include <stdio.h>      
int a[11],cnt;      
int main()      
{      
    int i,j,k,l,m,n,x,y,z,p,q;      
    scanf("%d",&n);      
    for(i=1;i<=n;++i)scanf("%d",&a[i]);      
    for(i=1;i<=n;++i)      
    {   
        if(a[i])   
        {   
            for(j=1;j<=n;++j)      
            {      
                for(k=1;k<=n;++k)      
                {      
                    for(l=1;l<=n;++l)      
                    {   
                        if(a[l])   
                        {   
                            for(m=1;m<=n;++m)      
                            {      
                                x=(100*a[i]+10*a[j]+a[k])*a[m];      
                                y=x/a[m]*a[l];      
                                z=y*10+x;      
                                if(x>999||y>999||z>9999)goto aa;      
                                for(p=1;p<4;++p)      
                                {      
                                    for(q=1;q<=n;++q)      
                                    {      
                                        if(a[q]==x%10)break;      
                                    }      
                                    if(q>n)break;      
                                    x/=10;      
                                }      
                                if(p<4)goto aa;      
                                for(p=1;p<4;++p)      
                                {      
                                    for(q=1;q<=n;++q)      
                                    {      
                                        if(a[q]==y%10)break;      
                                    }      
                                    if(q>n)break;      
                                    y/=10;      
                                }      
                                if(p<4)goto aa;      
                                for(p=1;p<5;++p)      
                                {      
                                    for(q=1;q<=n;++q)      
                                    {      
                                        if(a[q]==z%10)break;      
                                    }      
                                    if(q>n)break;      
                                    z/=10;      
                                }      
                                if(p<5)goto aa;      
                                ++cnt;   
aa:;   
                            }      
                        }      
                    }      
                }      
            }      
        }   
    }   
    printf("%d",cnt);      
    return 0;      
}  