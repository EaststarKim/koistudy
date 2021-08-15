#include <stdio.h>
#include <stdlib.h>
char a[1010],b[1010];
int x[26],y[26],ans;
int main(){
    int i;
    scanf("%s",a);
    scanf("%s",b);
    for(i=0;a[i];++i)++x[a[i]-'a'];
    for(i=0;b[i];++i)++y[b[i]-'a'];
    for(i=0;i<26;++i)ans+=abs(x[i]-y[i]);
    printf("%d",ans);
    return 0;
}
