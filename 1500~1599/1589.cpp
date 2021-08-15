#include <stdio.h>
int chk[20010];
int main(){
    int i,n,k;
    scanf("%d%d",&n,&k);
    chk[1]=1;
    for(i=1;i<=1e4;++i)if(chk[i])chk[i+n]=chk[i*2]=1;
    for(;k--;){
        scanf("%d",&n);
        puts(chk[n]?"true":"false");
    }
    return 0;
}
