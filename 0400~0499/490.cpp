#include <stdio.h>
#include <algorithm>
#define max(a,b) a>b? a:b
struct data
{
    int x,j;
    bool operator<(const data&r)const{
        return x<r.x;
    }
}a[100010];
int la[100010],ra[100010],ld,rd,m,t;
int main()
{
    int i,n,l,k;
    scanf("%d%d",&n,&l);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        a[i].j=i;
        if(k>0)a[i].x=ra[++rd]=k,t=max(t,l-k);
        else a[i].x=la[++ld]=-k,t=max(t,-k);
    }
    std::sort(&la[1],&la[ld+1]);
    std::sort(&ra[1],&ra[rd+1]);
    std::sort(&a[1],&a[n+1]);
    for(i=1;i<=ld;++i){
        if(la[i]-t==0){
            m=a[i].j;
            break;
        }
    }
    if(!m){
        for(i=1;i<=rd;++i){
            if(ra[rd-i+1]+t==l){
                m=a[n-i+1].j;
                break;
            }
        }
    }
    printf("%d %d",m,t);
    return 0;
}
