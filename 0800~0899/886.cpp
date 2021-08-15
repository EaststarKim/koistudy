#include <stdio.h>
int main()
{
    int i,n,s,mn=55,mx=0;
    for(i=1;i<11;++i)
    {
        scanf("%d",&n);
        s=0;
        while(n)
        {
            s+=n%10;
            n/=10;
        }
        if(mn>s)mn=s;
        if(mx<s)mx=s;
    }
    printf("%d %d",mx,mn);
    return 0;
}
