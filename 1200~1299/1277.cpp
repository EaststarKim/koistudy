#include <math.h>
bool isPrime(int n){
    int i,m=sqrt(n);
    if(n<2)return 0;
    for(i=2;i<=m;++i)if(n%i==0)return 0;
    return 1;
}
