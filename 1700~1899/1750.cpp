#include <bits/stdc++.h>
long long x[510],a,b,c,d;
int main(){
    int i,n,t;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%lld",x+i);
        if(n<5){
            puts("YES");
            continue;
        }
        a=x[4]-3*x[3]+3*x[2]-x[1];
        b=-6*x[4]+21*x[3]-24*x[2]+9*x[1];
        c=11*x[4]-42*x[3]+57*x[2]-26*x[1];
        d=-6*x[4]+24*x[3]-36*x[2]+24*x[1];
        for(i=5;i<=n;++i)if(a*i*i*i+b*i*i+c*i+d!=x[i]*6)break;
        puts(i>n?"YES":"NO");
    }
    return 0;
}
