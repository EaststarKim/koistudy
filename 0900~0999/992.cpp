#include <stdio.h>
#include <stdlib.h>
struct data{
    long long x,y;
}a[110];
long long s,b;
int gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}
int main()
{
    int i,m;
    scanf("%d",&m);
    for(i=0;i<m;++i)scanf("%d%d",&a[i].x,&a[i].y);
    a[m]=a[0];
    for(i=0;i<m;++i)s+=a[i].x*a[i+1].y;
    for(i=m;i>0;--i)s-=a[i].x*a[i-1].y;
    if(s<0)s=-s;
    for(i=0;i<m;++i)b+=abs(gcd(a[i+1].x-a[i].x,a[i+1].y-a[i].y));
    printf("%lld",(s-b)/2+1);
    return 0;
}
