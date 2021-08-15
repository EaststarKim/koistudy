#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010],ans;
int main(){
    int i,j,k,l,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i){
        for(j=1;j<31;++j){
            k=lower_bound(a+1,a+i,(1<<j)-a[i])-a;
            l=upper_bound(a+1,a+i,(1<<j)-a[i])-a;
            ans+=l-k;
        }
    }
    printf("%d",ans);
    return 0;
}
