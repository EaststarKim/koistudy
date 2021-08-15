#include <stdio.h>
#include <algorithm>
using namespace std;
int a[7],t;
int main(){
    int i,n,s;
    scanf("%d",&n);
    for(;n;n/=10)a[++t]=n%10;
    sort(a+1,a+t+1);
    do{
        for(i=1,s=0;i<=t;++i)s=s*10+a[i];
        if(s%8==0)break;
    }while(next_permutation(a+1,a+t+1));
    puts(s%8?"No":"Yes");
    return 0;
}
