#include <stdio.h>
int a[21];
void f(int n,int t,int p){
    int i,j;
    if(!n){
        for(i=1;i<p;++i){
            for(j=1;j<=a[i];++j)printf("*");
            puts("");
        }
        puts("");
        return;
    }
    for(i=t;i;--i)if(n>=i){
        a[p]=i;
        f(n-i,i,p+1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    f(n,n,1);
    return 0;
}
