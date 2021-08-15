#include <stdio.h>
int a,b,chk;
int main()
{
    int i,n,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&x,&y);
        a+=x,b+=y;
        if(x%2-y%2)chk=1;
    }
    if(a%2-b%2)puts("-1");
    else if(a%2){
        if(chk)puts("1");
        else puts("-1");
    }
    else puts("0");
    return 0;
}
