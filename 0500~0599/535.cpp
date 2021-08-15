#include <stdio.h>
#include <string.h>
char a[1000010],b[1000010];
int main(){
    int i,t,n,m,k,l,cnt;
    scanf("%d\n%s",&t,a);
    n=strlen(a);
    while(t--){
        for(i=k=m=0;i<=n;++i,++cnt)if(k!=a[i]){
            if(k){
                for(l=1;l<=cnt;l*=10);
                for(;l/=10;cnt%=l)b[m++]=cnt/l+48;
                b[m++]=k;
            }
            k=a[i],cnt=0;
        }
        strcpy(a,b);
        n=m;
        memset(b,0,sizeof b);
    }
    puts(a);
    return 0;
}
