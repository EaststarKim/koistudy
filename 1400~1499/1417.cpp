#include <stdio.h>
int n,m,t;
char c[21],a[21];
void f(int p,int s){
    if(p==n){
        if(s==n-m)puts(a);
        return;
    }
    if(s<n-m)a[s]=c[p],f(p+1,s+1);
    f(p+1,s);
}
int main(){
    int i;
    scanf("%d%d\n%s",&n,&m,c);
    f(0,0);
    return 0;
}
