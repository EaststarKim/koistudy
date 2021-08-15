#include <stdio.h>
#include <string.h>
#include <math.h>
int a[10],b[10],p[2020],cnt;
int main()
{
    int i,j,n,m,mi=0,s,ti,ts;
    double mn=5001;
    scanf("%d",&n);
    for(i=2;i<=n;++i){
        m=sqrt(i);
        for(j=2;j<=m;++j){
            if(i%j==0)break;
        }
        if(j>m)p[++cnt]=i;
    }
    for(i=2;i<=n;++i){
        s=i;
        for(j=1;j<=cnt;++j){
            if(i%p[j]==0)s=s*(p[j]-1)/p[j];
        }
        ti=i;
        ts=s;
        while(ti){
            ++a[ti%10];
            ti/=10;
        }
        while(ts){
            ++b[ts%10];
            ts/=10;
        }
        for(j=0;j<10;++j){
            if(a[j]!=b[j])break;
        }
        if(j>9&&mn>(double)i/s)mn=(double)i/s,mi=i;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    printf("%d",mi);
    return 0;
}
