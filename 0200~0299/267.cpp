#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int ans[999],n;
void isprime(int p){
    int i,m;
    m=sqrt(p);
    if(p%2==0)return;
    for(i=3;i<=m&&p%i;i+=2);
    if(i>m)ans[++n]=p;
}
int main(){
    int i,j,a,b,s,t;
    scanf("%d%d",&a,&b);
    if(a<=11&&11<=b)ans[++n]=11;
    for(i=5;;++i){
        for(s=j=i,t=10;j/10;j/=10)s=s*10+j/t%10;
        if(s>b)break;
        if(s>=a)isprime(s);
    }
    sort(ans+1,ans+n+1);
    for(i=1;i<=n;++i)printf("%d\n",ans[i]);
    return 0;
}
