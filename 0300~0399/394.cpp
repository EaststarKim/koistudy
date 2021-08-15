#include <stdio.h>         
#include <algorithm>         
using namespace std;       
int a[5001],b[4],c[4];         
int main()         
{         
    int i,n,s,e;         
    long long int mn,min=-min,sum,t;         
    scanf("%d",&n);         
    for(i=1;i<=n;++i)scanf("%d",&a[i]);         
    sort(&a[1],&a[n+1]);      
    for(i=1;i<=n;++i)         
    {         
        s=i+1;         
        e=n;         
        mn=min;         
        while(s<e)         
        {         
            sum=(long long int)a[i]+a[s]+a[e];      
        if(sum<0)t=-sum;      
        else t=sum;      
            if(mn>t)         
            {         
                mn=t;         
                b[1]=a[i];         
                b[2]=a[s];         
                b[3]=a[e];         
            }         
            if(sum<0)++s;         
            else if(sum>0)--e;      
            else break;      
        }         
        if(min>mn)         
        {         
            min=mn;         
            c[1]=b[1];         
            c[2]=b[2];         
            c[3]=b[3];         
        }         
    }      
    printf("%d %d %d",c[1],c[2],c[3]);         
    return 0;         
}  