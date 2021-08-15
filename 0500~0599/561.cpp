#include <stdio.h>   
int a[101],b[1000001]={1};   
int main()   
{   
    int i,j,n,k;   
    scanf("%d%d",&n,&k);   
    for(i=1;i<=n;++i)scanf("%d",&a[i]);   
    for(i=1;i<=n;++i)   
    {   
        for(j=k;j>=a[i];--j)   
        {   
            if(b[j-a[i]])b[j]=1;   
        }   
    }   
    if(b[k])printf("YES");   
    else printf("NO");   
    return 0;   
}  