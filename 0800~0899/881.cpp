#include <stdio.h>
char a[10010],b[10010];
int main()
{
    int i,n,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf(" %c",a+i);
    for(i=0;i<n;++i)scanf(" %c",b+i);
    for(i=0;i<n;++i){
        if(a[i]==b[i])++cnt;
    }
    printf("%d",cnt);
    return 0;
}
