#include <stdio.h>
#include <algorithm>
using namespace std;
char c[7][10];
int a[26],chk[10],s[7],n,cnt;
void f(int m,int k){
    int i,t=0;
    if(m>n){
        for(i=1,t=0;i<n;++i)t+=s[i];
        if(t!=s[n])return;
        printf("%d",s[1]);
        for(i=2;i<n;++i)printf(" + %d",s[i]);
        printf(" = %d\n",s[n]);
        ++cnt;
        return;
    }
    if(!c[m][k])f(m+1,0);
    else if(a[c[m][k]-'A']>=0){
        if(!a[c[m][k]-'A']&&!k)return;
        s[m]=s[m]*10+a[c[m][k]-'A'];
        f(m,k+1);
        s[m]/=10;
    }
    else{
        for(i=!k;i<10;++i)if(!chk[i]){
            a[c[m][k]-'A']=i;
            s[m]=s[m]*10+i;
            chk[i]=1;
            f(m,k+1);
            chk[i]=0;
            s[m]/=10;
            a[c[m][k]-'A']=-1;
        }
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<26;++i)a[i]=-1;
    for(i=1;i<=n;++i)scanf("%s",c[i]);
    f(1,0);
    if(!cnt)puts("Impossible");
    if(cnt==1)puts("Unique");
    return 0;
}
