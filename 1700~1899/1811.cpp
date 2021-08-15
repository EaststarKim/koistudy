#include <stdio.h>
int main(){
    int i,t,m,d;
    long long l,x,y;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d",&m);
        x=y=0;
        for(;m--;)scanf("%lld%d",&l,&d),x+=l*d/10,y+=l*d%10;
        x+=y/10;
        for(l=0;x;x/=10)l+=x%10;
        x=l+y%10;
        for(;x>9;x=l)for(l=0;x;x/=10)l+=x%10;
        printf("%d\n",x);
    }
    return 0;
}
