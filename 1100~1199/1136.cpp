#include <stdio.h>
int main(){
    long long t=0,e=1,k;
    scanf("%lld",&k);
    for(;e<k;t=!t)e*=t?2:9;
    printf("%c",t?'G':'Y');
    return 0;
}
