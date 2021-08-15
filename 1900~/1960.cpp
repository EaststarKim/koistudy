#include <stdio.h>
int a[100010],b[100010],ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),a[i]+=a[i-1];
    for(i=1;i<=n;++i){
        scanf("%d",b+i),b[i]+=b[i-1];
        if(a[i]==b[i])ans=i;
    }
    printf("%d",ans);
    return 0;
}
