#include <stdio.h>
int a[]={0,0,4,12,36,100,284,780,2172,5916,16268,44100,120292,324932},k;
int main(){
    long long m;
    scanf("%d%lld",&k,&m);
    printf("%lld",a[k]%m);
    return 0;
}
