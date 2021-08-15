#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n,m,p,a,b,t;
    scanf("%d%d%d",&n,&m,&p);
    for(i=1;i<=p;++i){
        scanf("%d%d",&a,&b);
        n+=a,m+=b;
        t=abs(n)+abs(m);
        if(t<=i&&t%2==i%2)break;
    }
    if(i>p)i=-1;
    printf("%d",i);
    return 0;
}
