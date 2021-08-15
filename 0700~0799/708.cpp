#include <stdio.h>   
#include "lib.h"   
int main()   
{   
    int i,k,l,r,h,t;   
    scanf("%d",&k);   
    for(i=1;i<101;++i)   
    {   
        l=1;   
        r=100;   
        while(l<=r)   
        {   
            h=(l+r)/2;   
            t=function(i,h);   
            if(t==k)   
            {   
                printf("%d %d",i,h);   
                return 0;   
            }   
            if(l==r)break;   
            if(t<k)l=h+1;   
            if(t>k)r=h;   
        }   
    }   
    return 0;   
}