#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char k[10010];
int s[10010],n,h;
void f(){
    int i;
    for(i=0;i<h;++i){
        s[i+1]+=s[i]/n;
        s[i]%=n;
    }
}
int main(){
    int i,j,l,m,t;
    scanf("%d%d",&n,&h);
    scanf("%s",k);
    m=strlen(k);
    reverse(k,k+m);
    for(i=0;i<m;++i)k[i]-=k[i]<'A'?48:55;
    --k[0];
    for(i=0;i<h;++i)if(k[i]<0)k[i]+=n,--k[i+1];
    for(i=h,j=0;i;--i){
        t=(k[i-1]-j+n)%n;
        for(l=0;l<i;++l)s[l]+=t;
        j=(j+t+1)%n;
        ++s[0];
    }
    f();
    for(i=h,t=0;i>=0;--i){
        if(s[i])t=1;
        if(t==1)printf("%c",s[i]+(s[i]>9?55:48));
    }
    return 0;
}
