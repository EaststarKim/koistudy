#include <stdio.h>
#include <algorithm>
using namespace std;
int D[10000010],ans=1e9;
void f(int n,int t){
    if(t>10)return;
    if(n<=10000000)ans=min(ans,t+D[n]);
    int ans=1e9;
    if(n%3==0)f(n/3,t+1);
    if(n%2==0)f(n/2,t+1);
    f(n-1,t+1);
}
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=2;i<=10000000;++i){
        D[i]=D[i-1]+1;
        if(i%2==0)D[i]=min(D[i],D[i/2]+1);
        if(i%3==0)D[i]=min(D[i],D[i/3]+1);
    }
    f(n,0);
    printf("%d",ans);
    return 0;
}
