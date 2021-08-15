#include <stdio.h>
int main(){
    int i,j,n,s;
    while(scanf("%d%d",&n,&s)==2){
        if(s!=n+1)puts("-1");
        else{
            printf("%d\n",n*(n+1)/2);
            for(i=0;i<n;++i){
                for(j=0;j<=i;++j)printf("%d ",s-i+j*2);
            }
            puts("");
        }
    }
    return 0;
}
