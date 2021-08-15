#include <stdio.h>
typedef long long ll;
const int MOD=1e8;
ll mod_pow(ll x,int n){
    if(!n)return 1;
    ll res=mod_pow(x*x%MOD,n>>1);
    if(n&1)res=res*x%MOD;
    return res;
}
int main()
{
    int i,n;
    long long s=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)s=(s+mod_pow(i,i))%MOD;
    printf("%08d",s);
    return 0;
}
