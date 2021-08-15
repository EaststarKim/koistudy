#include <stdio.h>   
int d[11][11],chk[11],n,f,sw;   
void back(int p)   
{   
    int i,j;   
    if(sw)return;   
    if(p>n)   
    {   
        for(i=2;i<=n;++i)   
        {   
            for(j=i;j<=n;++j)d[i][j]=d[i-1][j-1]+d[i-1][j];   
        }   
        if(d[n][n]==f)   
        {   
            for(i=1;i<=n;++i)printf("%d ",d[1][i]);   
            sw=1;   
        }   
        return;   
    }   
    for(i=1;i<=n;++i)   
    {   
        if(!chk[i])   
        {   
            chk[i]=1;   
            d[1][p]=i;   
            back(p+1);   
                        if(sw)return;   
            chk[i]=0;   
        }   
    }   
}   
int main()   
{   
    scanf("%d%d",&n,&f);   
    back(1);   
    return 0;   
}  