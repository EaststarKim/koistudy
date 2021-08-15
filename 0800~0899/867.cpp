#include <stdio.h>
int main(){
    int i,n,k,a=0,b=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        if(k==25)++a;
        else if(k==50){
            if(!a)break;
            --a,++b;
        }
        else{
            if(a&&b)--b,--a;
            else if(a>2)a-=3;
            else break;
        }
    }
    if(i>n)printf("YES");
    else printf("NO");
    return 0;
}
