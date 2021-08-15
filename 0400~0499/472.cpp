#include <stdio.h>
int main(){
    int i,n,v;
    double l,H,h=2e9;
    scanf("%d%d",&v,&n);
    for(i=1;i<=n;++i){
        scanf("%lf%lf",&l,&H);
        if(h>H+10)h=H+10;
        if(h>H)h-=(h-H)*(1-2*v/l);
    }
    printf("%d",(int)h);
    return 0;
}
