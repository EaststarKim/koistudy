#include <stdio.h>
char a[110],b[110];
int c[26],d[26],s;
int main(){
    int i;
    scanf("%s\n%s",a,b);
    for(i=0;a[i];++i)++c[a[i]-'a'];
    for(i=0;b[i];++i)b[i]=='*'?++s:++d[b[i]-'a'];
    for(i=0;i<26;++i)if(c[i]<d[i])break;
    puts(i<26?"N":"A");
    return 0;
}
