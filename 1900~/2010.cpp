#include <stdio.h>
int a[100010],n,t;
long long s;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a[++t]);
        s+=a[t];
        if(!a[t])s-=a[t-1],t-=2;
    }
    printf("%lld",s);
    return 0;
}
