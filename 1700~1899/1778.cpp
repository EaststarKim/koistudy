#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int n,x,y,w,h,a,b,c;
    scanf("%d%d%d",&w,&h,&n);
    x=y=0;
    for(;n--;){
        scanf("%d%d%d",&a,&b,&c);
        if(c==1)x=max(x,a);
        if(c==2)w=min(w,a);
        if(c==3)y=max(y,b);
        if(c==4)h=min(h,b);
    }
    printf("%d",(x<w?w-x:0)*(y<h?h-y:0));
    return 0;
}
