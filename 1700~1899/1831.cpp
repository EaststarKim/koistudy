#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t,s=0,mx=0;
    scanf("%d%d",&n,&m);
    for(;m--;){
        scanf("%d%d",&t,&t);
        if(t>n)s+=t-n,mx=max(mx,t-n);
    }
    printf("%d",s-mx);
    return 0;
}
