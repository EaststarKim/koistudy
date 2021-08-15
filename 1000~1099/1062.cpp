#include <stdio.h>
int n;
char a[110];
void back(int p){
    puts(a);
    if(p==n)return;
    a[p]=a[n-p-1]='*';
    back(p+1);
    a[p]=a[n-p-1]='.';
    puts(a);
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i)a[i]='.';
    a[n/2]='*';
    back(n/2+1);
    return 0;
}
