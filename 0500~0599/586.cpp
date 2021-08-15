#include <stdio.h>
#include <string.h>
#include <math.h>
int a[110],p[80000]={2},n,t;
char c[110];
int mod(int m){
    int i,s=0;
    for(i=0;i<n;++i)s=s*10+a[i],s%=m;
    return s;
}
int main(){
    int i,j,k,m;
    scanf("%s%d",c,&k);
    n=strlen(c);
    for(i=0;i<n;++i)a[i]=c[i]-48;
    for(i=3;i<=k;i+=2){
        m=sqrt(i);
        for(j=0;j<=t&&p[j]<=m&&i%p[j];++j);
        if(j<=t&&i%p[j])p[++t]=i;
    }
    for(i=0;i<=t&&mod(p[i]);++i);
    if(i>t)printf("GOOD");
    else printf("BAD %d",p[i]);
    return 0;
}
