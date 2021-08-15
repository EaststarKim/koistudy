#include <bits/stdc++.h>
using namespace std;
set<int> s;
int main(){
    int g,p,t,cnt=0;
    scanf("%d%d",&g,&p);
    for(;g;)s.insert(g--);
    for(;p--;++cnt){
        scanf("%d",&t);
        auto x=s.upper_bound(t);
        if(x==s.begin())break;
        s.erase(--x);
    }
    printf("%d",cnt);
    return 0;
}
