#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct data{
    int cnt,i,j;
    bool operator<(const data&r)const{
        if(cnt==r.cnt){
            if(i==r.i)return j<r.j;
            return i<r.i;
        }
        return cnt>r.cnt;
    }
}ans[1<<13];
char c[200010];
int cnt[13][1<<12],t;
int main(){
    int i,j,k,a,b,n,l;
    scanf("%d%d%d\n%s",&a,&b,&n,c);
    l=strlen(c);
    for(i=a;i<=b;++i){
        for(j=k=0;j<i-1;++j)k=k*2+(c[j]-48);
        for(;j<l;++j){
            k=k*2+(c[j]-48);
            ++cnt[i][k];
            k%=(1<<(i-1));
        }
    }
    for(i=a;i<=b;++i){
        for(j=0;j<(1<<i);++j)if(cnt[i][j])ans[++t]={cnt[i][j],i,j};
    }
    sort(ans+1,ans+t+1);
    for(i=1;i<=t;++i){
        if(ans[i].cnt!=ans[i-1].cnt){
            if(n--)printf("\n%d\n",ans[i].cnt);
            else break;
        }
        for(j=ans[i].i;j--;)printf("%d",!!(ans[i].j&(1<<j)));
        printf(" ");
    }
    return 0;
}
