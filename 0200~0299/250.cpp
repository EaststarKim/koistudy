#include <stdio.h>   
#include <string.h>   
char name[20][100],give[100],get[100];   
int money[2][20];   
int main()   
{   
    int i,j,n,k,l,p;   
    scanf("%d",&n);   
    for(i=1;i<=n;++i)scanf(" %s",name[i]);   
    for(i=1;i<=n;++i)   
    {   
        scanf(" %s",give);   
        for(j=1;j<=n;++j)   
        {   
            if(strcmp(give,name[j])==0)break;   
        }   
        scanf("%d%d",&money[0][j],&k);   
        if(money[0][j])money[1][j]+=money[0][j]-money[0][j]/k*k;   
        for(p=1;p<=k;++p)   
        {   
            scanf(" %s",get);   
            for(l=1;l<=n;++l)   
            {   
                if(strcmp(get,name[l])==0)break;   
            }   
            money[1][l]+=money[0][j]/k;   
        }   
    }   
    for(i=1;i<=n;++i)printf("%s %d\n",name[i],money[1][i]-money[0][i]);   
    return 0;   
}  