#include <stdio.h>      
struct stick{   
    long long weight, lLen, rLen;   
    int l, r;   
} st[105];   
int n, cnt[105];   
int gcd(long long a, long long b){      
    if(b == 0) return a;      
    else return gcd(b, a%b);      
}   
void calc(int num){      
    if(num == 0) return;      
    stick &now=st[num];      
    int g=gcd(now.lLen, now.rLen), a, b;      
    now.lLen /= g;      
    now.rLen /= g;      
    calc(now.l);      
    calc(now.r);      
    a = st[now.l].weight/gcd(st[now.l].weight, now.rLen)*now.rLen;      
    b = st[now.r].weight/gcd(st[now.r].weight, now.lLen)*now.lLen;      
    g = (a/now.rLen)/gcd(a/now.rLen, b/now.lLen)*(b/now.lLen);      
    now.weight = g*(now.lLen+now.rLen);      
}      
int main(){      
    scanf("%d", &n);      
     
    int i, g;      
    for(i=1; i<=n; i++){      
        scanf("%lld%lld%d%d", &st[i].lLen, &st[i].rLen, &st[i].l, &st[i].r);      
        if(st[i].l != 0) cnt[st[i].l]++;      
        if(st[i].r != 0) cnt[st[i].r]++;;      
    }      
     
    for(i=1; i<=n; i++) if(cnt[i] == 0) break;      
    st[0].weight = 1;      
    calc(i);      
    printf("%lld\n", st[i].weight);      
     
    return 0;      
}  