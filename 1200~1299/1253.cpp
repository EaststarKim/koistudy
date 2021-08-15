#include <stdio.h>
int main(){
    int i,j,k,l,a,b,flag=0;
    long long s,t;
    scanf("%d%d",&a,&b);
    for(i=a;i<b;++i){
        for(j=i+1;j<b;++j){
            s=j*j-i*i;
            for(k=j;k<b;++k){
                for(l=k+1;l<=b;++l){
                    t=l*l-k*k;
                    if(s*k*k*l*l==t*i*i*j*j)printf("%d %d %d %d\n",i,j,k,l),flag=1;
                }
            }
        }
    }
    if(!flag)puts("-1");
    return 0;
}
