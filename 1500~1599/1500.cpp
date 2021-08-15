#include <stdio.h>
char a[1000010];
int f[1000010],n;
void ff(){
    int i=2,j=0;
    for(i=2;i<=n;++i){
        while(j&&a[j+1]!=a[i])j=f[j];
        if(a[j+1]==a[i])++j;
        f[i]=j;
    }
}
int main(){
    int i;
    scanf("%d\n%s",&n,a+1);
    ff();
    printf("%d",n-f[n]);
    return 0;
}
