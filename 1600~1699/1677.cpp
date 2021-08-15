#include <stdio.h>
#include <queue>
using namespace std;
struct data{
    int i,x;
    bool operator<(const data&r)const{
        return x>r.x;
    }
};
priority_queue<data> pq;
int q[200010],chk[200010],f=1,r,m;
int main(){
    int i,n,k;
    char c;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("\n%c",&c);
        if(c=='+'){
            scanf("%d",&k);
            q[++r]=++m;
            pq.push({m,k});
        }
        if(c=='-')chk[q[f++]]=1;
        if(c=='?'){
            while(1){
                data x=pq.top();
                if(chk[x.i]){
                    pq.pop();
                    continue;
                }
                printf("%d\n",x.x);
                break;
            }
        }
    }
    return 0;
}
