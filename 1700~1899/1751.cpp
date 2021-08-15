#include <stdio.h>
char a[10010],*str="ACGT";
int cnt[4],m;
int main(){
    int i,j,n;
    scanf("%d%s",&n,a);
    for(i=0;i<n;++i){
        for(j=0;j<4;++j)cnt[j]+=(str[j]==a[i]);
    }
    for(i=1;i<4;++i)if(cnt[i]<cnt[m])m=i;
    printf("%d",cnt[m]);
    return 0;
}
