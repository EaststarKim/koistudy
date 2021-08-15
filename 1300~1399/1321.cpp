#include <stdio.h>
#define M 1000000007
long long a[1010]={1},t[1010],n;
void f(long long *a,long long *b){
    int i,j;
    long long s[1010]={};
    for(i=0;i<n;++i)for(j=0;j<n;++j)s[(i+j)%n]+=a[i]*b[j]%M;
    for(i=0;i<n;++i)a[i]=s[i]%M;
}
int main(){
    int i,m,d;
    scanf("%d%d%d",&n,&m,&d);
    t[0]=m/n;
    for(i=1;i<n;++i)t[i]=m/n+(m%n>=i);
    for(i=1;i<=d;i*=2){
        if(i&d)f(a,t);
        f(t,t);
    }
    printf("%d",a[0]);
    return 0;
}
