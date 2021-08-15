#include <stdio.h>
#include <set>
using namespace std;
set<int> s;
set<int>::iterator x;
int main(){
    int n,k,t,cnt=0;
    scanf("%d%d",&n,&k);
    while(n)s.insert(n--);
    while(k--){
        scanf("%d",&t);
        x=s.upper_bound(t);
        if(x==s.begin())break;
        s.erase(--x);
        ++cnt;
    }
    printf("%d",cnt);
    return 0;
}
