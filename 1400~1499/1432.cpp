#include <stdio.h>
int a[80010],c[80010],t;
int main(){
    int i,n,x;
    char s;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%s",&s);
        x=0;
        if(s=='a'){
            scanf("%d",&x);
            c[a[++t]=t]=x;
        }
        else if(s=='s')x=c[a[++t]=a[a[t-1]-1]];
        else{
            scanf("%d",&x);
            x=c[a[++t]=a[x-1]];
        }
        printf("%d\n",x?x:-1);
    }
    return 0;
}
