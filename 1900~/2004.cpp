#include <stdio.h>
int a[53],b[53],cnt;
char c[3000010];
int main(){
    int i,j,n,m;
    scanf("%d%d\n%s\n",&n,&m,c);
    for(i=0;i<n;++i)c[i]>96?++a[c[i]-70]:++a[c[i]-64];
    scanf("%s",c);
    for(i=0;i<n-1;++i)c[i]>96?++b[c[i]-70]:++b[c[i]-64];
    for(;i<m;++i){
        c[i]>96?++b[c[i]-70]:++b[c[i]-64];
        for(j=1;j<53&&a[j]==b[j];++j);
        if(j>52)++cnt;
        c[i-n+1]>96?--b[c[i-n+1]-70]:--b[c[i-n+1]-64];
    }
    printf("%d",cnt);
    return 0;
}
