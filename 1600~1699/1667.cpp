#include <stdio.h>
#include <algorithm>
using namespace std;
int D[10000010];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=2;i<=n;++i)D[i]=1e9;
    for(i=2;i<=n;++i){
        D[i]=D[i-1]+1;
        if(i%2==0)D[i]=min(D[i],D[i/2]+1);
        if(i%3==0)D[i]=min(D[i],D[i/3]+1);
    }
    printf("%d",D[n]);
    return 0;
}
