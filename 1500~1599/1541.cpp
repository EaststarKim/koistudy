#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10010],d[10010];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    d[1]=1;
    for(i=1;i<=n;++i)if(d[i]){
        for(j=i+1;j<=i+a[i]&&j<=n;++j){
            if(d[j])d[j]=min(d[j],d[i]+1);
            else d[j]=d[i]+1;
        }
    }
    if(!d[n])d[n]=1;
    printf("%d",d[n]-1);
    return 0;
}
