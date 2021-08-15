#include <stdio.h>
int main(){
    int k,a,b,v,cnt=0;
    scanf("%d%d%d%d",&k,&a,&b,&v);
    while(a>0){
        if(k>b)a-=(b+1)*v,b=0;
        else a-=k*v,b-=k-1;
        ++cnt;
    }
    printf("%d",cnt);
    return 0;
}
