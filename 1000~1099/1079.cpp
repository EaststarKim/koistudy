#include <stdio.h>
typedef unsigned int u;
int cnt(u n,u m){
    if(!n||!m)return 0;
    if(n<m)return cnt(n,m-n)+1;
    else return cnt(n-m,m)+1;
}
int main()
{
    u n,m;
    scanf("%u%u",&n,&m);
    printf("%d",cnt(n,m));
    return 0;
}
