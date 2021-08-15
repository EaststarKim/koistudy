#include <stdio.h>
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    puts((n-k-1)%(m+1)?"yes":"no");
    return 0;
}
