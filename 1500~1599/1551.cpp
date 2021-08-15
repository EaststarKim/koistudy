#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int i,j,n,flag=0;
    scanf("%d",&n);
    for(i=1;i<=n/3;++i){
        for(j=max(i,n/2+1-i);j<=(n-i)/2;++j){
            flag=1;
            printf("%d %d %d\n",i,j,n-i-j);
        }
    }
    if(!flag)puts("-1");
    return 0;
}
