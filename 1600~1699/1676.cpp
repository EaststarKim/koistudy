#include <stdio.h>
#include <string.h>
using namespace std;
char a[1010],b[1010];
int main(){
    int i,j,k,n,m,mx=0,mi;
    scanf("%s",a+1);
    scanf("%s",b+1);
    n=strlen(a+1);
    m=strlen(b+1);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            for(k=0;k<=n-i&&k<=m-j;++k){
                if(a[i+k]!=b[j+k]){
                    if(k>mx){
                        mx=k;
                        mi=i;
                    }
                    break;
                }
            }
            if(k>n-i||k>m-j){
                if(k>mx){
                    mx=k;
                    mi=i;
                }
            }
        }
    }
    if(!mx)mx=-1;
    printf("%d\n",mx);
    if(mx<0)puts("No");
    else for(i=0;i<mx;++i)printf("%c",a[mi+i]);
    return 0;
}
