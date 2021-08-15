#include <stdio.h>
int a[1010],s;
void back(int n,int c){
    if(!n){
        if(s>c)s=c;
        return;
    }
    if(a[n]<=c){
    	if(n>0)back(n-1,c-a[n]);
    	if(n>1)back(n-2,c-a[n-1]);
    }
    else back(n-1,c);
}
int main(){
    int i,n,c;
    scanf("%d%d",&n,&c);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    s=c;
    back(n,c);
    printf("%d",c-s);
    return 0;
}
