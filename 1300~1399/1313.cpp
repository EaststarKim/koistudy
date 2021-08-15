#include <stdio.h>
#define M 1000000007
int cnt;
void f(int n,int s,int t,int e){
    if(!n||cnt>99)return;
    f(n-1,s,t,e);
    if(cnt<100)printf("%d : %c->%c\n",n,s,t),++cnt;
    f(n-1,e,t,s);
    if(cnt<100)printf("%d : %c->%c\n",n,t,e),++cnt;
    f(n-1,s,t,e);
}
int main(){
    int i,n;
    long long ans=1,t=3;
    scanf("%d",&n);
    for(i=1;i<=n;i*=2,t=(t*t)%M)if(n&i)ans=(ans*t)%M;
    f(n<5?n:5,'A','C','B');
    printf("%d",ans-1);
    return 0;
}
