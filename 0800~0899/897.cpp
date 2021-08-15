#include <stdio.h>
#define M 10007
int a[1010],s[1010][8],n;
int f(int p,int t){
    int i;
    if(p>n)return 1;
    if(s[p][t])return s[p][t];
    for(i=1;i<8;++i)if(i&(1<<a[p])&&i&t)s[p][t]+=f(p+1,i);
    return s[p][t]%=M;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%1d",a+i),--a[i];
    printf("%d",f(1,1));
    return 0;
}
