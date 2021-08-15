#include <stdio.h>
int main(){
    long long n,s=0;
    scanf("%lld",&n);
    for(;n;){
        s+=n%10;
        n/=10;
    }
    puts(s%7==4?"Bad":"Good");
    return 0;
}
