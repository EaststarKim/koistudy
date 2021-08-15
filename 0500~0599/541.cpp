#include <stdio.h>   
int a[210],b[210],mx;   
int main()   
{   
    int i,j,n;   
    scanf("%d",&n);   
    for(i=1;i<=n;++i)   
    {   
        scanf("%d",&a[i]);   
        for(j=1;j<i;++j)   
        {   
            if(a[j]<a[i]&&b[j]>=b[i])b[i]=b[j]+1;   
        }   
    }   
    for(i=1;i<=n;++i)   
    {   
        if(mx<b[i])mx=b[i];   
    }   
    printf("%d",n-mx-1);   
    return 0;   
}  