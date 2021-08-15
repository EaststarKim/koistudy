#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,a,b,m,mn=0,mx,cnt=0;
    scanf("%d%d",&a,&b);
    if(a>b)a^=b^=a^=b;
    if(a<2)++a;
    for(i=a;i<=b;++i){
        m=sqrt(i);
        for(j=2;j<=m;++j)if(i%j==0)break;
        if(j>m){
            if(!mn)mn=i;
            mx=i;
            ++cnt;
        }
    }
    printf("%d\n%d",cnt,mn+mx);
    return 0;
}
