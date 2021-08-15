#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(){
    int w,h,n,r,c,ans=0;
    scanf("%d%d%d%d%d",&w,&h,&n,&r,&c);
    for(;--n;){
        scanf("%d%d",&w,&h);
        ans+=(w-r)*(h-c)>0?max(abs(w-r),abs(h-c)):abs(w-r)+abs(h-c);
        r=w,c=h;
    }
    printf("%d",ans);
    return 0;
}
