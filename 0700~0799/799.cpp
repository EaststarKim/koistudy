#include <cstdio>
long long a[27],mul;
int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    n%=m;
    if(!n){
        puts("0");
        return 0;
    }
    a[0]=n;
    for(i=1;i<27;++i)a[i]=(a[i-1]*a[i-1])%m;
    for(i=1;i<m;++i){
        if((m-1)%i)continue;
        mul=1;
        for(j=0;j<27;++j){
            if(i&(1<<j))mul=(mul*a[j])%m;
        }
        if(mul==1)break;
    }
    printf("%d",i);
    return 0;
}
