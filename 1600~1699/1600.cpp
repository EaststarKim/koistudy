#include <stdio.h>
int main(){
    int i,j,n,s,t;
    scanf("%d",&n);
    for(i=6;i<=n;++i){
        for(s=-i,j=1;j*j<i;++j)if(i%j==0)s+=j+i/j;
        if(j*j==i)s+=j;
        for(t=-s,j=1;j*j<s;++j)if(s%j==0)t+=j+s/j;
        if(j*j==s)t+=j;
        if(t==i)printf("%d %d\n",i,s);
    }
    return 0;
}
