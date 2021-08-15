#include <stdio.h>
char a[110];
int main(){
    int i,j,n,m,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%s",a);
        t=-1;
        for(j=0;j<m;++j){
            if(t!=-1)++t;
            if(a[j]=='c')t=0;
            printf("%d ",t);
        }
        puts("");
    }
    return 0;
}
