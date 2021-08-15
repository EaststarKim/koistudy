#include <stdio.h>
char a[110];
void f(int n){
    if(!n)return;
    puts(a);
    a[n-1]=0;
    f(n-1);
    a[n-1]='*';
    puts(a);
}
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;++i)a[i]='*';
    f(n);
    return 0;
}
