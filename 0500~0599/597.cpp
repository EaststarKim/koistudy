#include <stdio.h>
int a[100010],st[100010],t,p;
char ans[200010];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=j=1;i<=n;++i){
        st[++t]=i;
        ans[++p]='+';
        while(t&&st[t]==a[j])--t,++j,ans[++p]='-';
    }
    if(t)puts("NO");
    else{
        for(i=1;i<=p;++i)printf("%c\n",ans[i]);
    }
    return 0;
}
