#include <stdio.h>
int a[1<<19],n,p;
char c[1<<20];
void back(int s,int e){
    int i;
    if(c[++p]!='-'){
        for(i=s;i<=e;++i)a[i]=c[p]-48;
        return;
    }
    int m=(s+e)/2;
    back(s,m);
    back(m+1,e);
}
int main()
{
    int i;
    scanf("%d%s",&n,c+1);
    back(1,n);
    for(i=1;i<=n;++i)printf("%d",a[i]);
    return 0;
}
