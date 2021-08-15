#include <stdio.h>
#include <string.h>
char a[110];
int main()
{
    int i,j,n,m,s=0,t=0;
    scanf("%d\n",&n);
    for(i=1;i<=n;++i){
        fgets(a,100,stdin);
        m=strlen(a);
        for(j=0;j<m;++j){
            if(a[j]=='s'||a[j]=='S')++s;
            if(a[j]=='t'||a[j]=='T')++t;
        }
    }
    if(t>s)puts("English");
    else puts("French");
    return 0;
}
