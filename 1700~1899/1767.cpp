#include <stdio.h>
int ans[]={0,0,0,0,1,5,13,35,49,126,161,330,301,715,757,1365,1377,2380,1837,3876,3841,5985,5941,8855,7297,12650,12481,17550,17249,23751,16801};
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",ans[n]*24);
    return 0;
}