#include <stdio.h>
int chk(int n){
    for(;n;n/=10)if((n%10)&&!((n%10)%3))return 1;
    return 0;
}
int f(int n){
    if(n<1)return 0;
    int q=n/10,r=n%10,s=f(q);
    return s*10+(q-s+1)*3-(chk(q)?9-r:((r<3)+(r<6)+(r<9)));
}
int main(){
    int i,a,b;
    scanf("%d%d",&a,&b);
    printf("%d",f(b)-f(a-1));
    return 0;
}
