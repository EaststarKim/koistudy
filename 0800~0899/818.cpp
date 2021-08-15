#include <stdio.h>
int a[20];
int gcd(int x,int y)
{
    if(!y)return x;
    return gcd(y,x%y);
}
int main()
{
    int i,j,n,m,num;
    long long res=0,lcm;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;++i)scanf("%d",&a[i]);
    for(i=1;i<(1<<m);++i)
    {
        num=0;
        for(j=i;j!=0;j>>=1)num+=j&1;
        lcm=1;
        for(j=0;j<m;++j)
        {
            if(i>>j&1)
            {
                lcm=lcm/gcd(lcm,a[j])*a[j];
                if(lcm>n)break;
            }
        }
        if(num%2==0)res-=n/lcm;
        else res+=n/lcm;
    }
    printf("%d",res);
    return 0;
}
