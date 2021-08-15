#include <stdio.h>
int main(){
    int i,n,s=1,t;
    scanf("%d",&n);
    for(i=1,t=2;i<n;++i){
        s+=t;
        if(i%2)t+=2;
    }
    printf("%d",s);
    return 0;
}
