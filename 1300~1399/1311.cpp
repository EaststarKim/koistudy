#include <stdio.h>
char a[310][310];
int main(){
    int i,j,r,c,t,mx;
    scanf("%d%d",&r,&c);
    for(i=1;i<=r;++i)scanf("%s",a[i]+1);
    for(i=1;i<=c;++i){
        for(j=1,t=0;j<=r;++j)if(a[j][i]=='*'&&a[j-1][i]!='*')++t;
        printf("%d ",t);
    }
    puts("");
    for(i=1;i<=c;++i){
        for(j=1,t=mx=0;j<=r;++j){
            if(a[j][i]=='.')t=0;
            else ++t;
            if(mx<t)mx=t;
        }
        printf("%d ",mx);
    }
    return 0;
}
