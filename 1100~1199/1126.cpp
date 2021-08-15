#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int i,n,x,y,x1,x2,y1,y2,t;
    scanf("%d",&n);
    x1=y1=-2e9,x2=y2=2e9;
    for(i=1;i<=n;++i){
        scanf("%d%d",&x,&y);
        x1=max(x1,x),x2=min(x2,x),y1=max(y1,y),y2=min(y2,y);
    }
    t=max(x1-x2,y1-y2);
    printf("%lld",(long long)t*t);
    return 0;
}
