#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int Z=2e9;
struct data{
    int m,s;
}a[100010],ans;
char t[210];
int px,pn,mn=Z,flag;
int main(){
    int i,n,m;
    scanf("%d",&n);
    ans.m=Z,ans.s=1;
    for(i=1;i<=n;++i){
        memset(t,0,sizeof t);
        scanf("%s",t);
        m=strlen(t)-1;
        if(!m&&t[0]=='0'){
            mn=Z,px=pn=0,flag=1;
            continue;
        }
        a[i].s=a[i-1].s;
        if(t[0]=='-')a[i].s=!a[i].s,--m;
        if(t[1]=='.'||t[2]=='.')m=1-m;
        a[i].m=a[i-1].m+m;
        if(a[i].s){
            if(mn<Z){
                if(ans.s)ans.s=0,ans.m=a[i].m-mn;
                else ans.m=max(ans.m,a[i].m-mn);
            }
            else if(ans.s)ans.m=min(ans.m,a[i].m-px);
            mn=min(mn,a[i].m);
        }
        else{
            if(ans.s)ans.s=0,ans.m=a[i].m-pn;
            else ans.m=max(ans.m,a[i].m-pn);
            px=max(px,a[i].m),pn=min(pn,a[i].m);
        }
    }
    if(ans.s){
        if(flag){
            puts("0");
            return 0;
        }
        printf("-");
    }
    if(ans.m<0){
        printf("0.");
        for(i=1;i<-ans.m;++i)printf("0");
        printf("1");
    }
    else{
        printf("1");
        for(i=0;i<ans.m;++i)printf("0");
    }
    return 0;
}
