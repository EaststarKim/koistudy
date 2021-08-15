#include <stdio.h>
#include <string.h>
char a[8],c[][9]={"vaporeon","jolteon","flareon","espeon","umbreon","leafeon","glaceon","sylveon"};
int main(){
    int i,j,n,m;
    scanf("%d%s",&n,a);
    for(i=0;i<8;++i){
        m=strlen(c[i]);
        if(n!=m)continue;
        for(j=0;j<n;++j)if(a[j]!='.'&&a[j]!=c[i][j])break;
        if(j==n)break;
    }
    puts(c[i]);
    return 0;
}
