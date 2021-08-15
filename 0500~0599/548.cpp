#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
char c[5000010];
int a[5000010],b[5000010],chk[5000010],s[10000],t,xi,ans;
vector<int> v[1000010];
int f(int x,int y,int z){
    if(z==2)return x+y;
    if(z==3)return x-y;
    if(z==4)return x*y;
    return x/y;
}
int post(int p,int q){
    int i,x,y,t=0;
    for(i=p;i<=q;++i){
        if(b[i]){
            x=s[t--];
            y=s[t--];
            s[++t]=f(y,x,b[i]);
        }
        else s[++t]=a[i];
    }
    return s[t];
}
void sol(){
    int i,k,flag,p=0,q=t-1,r,s;
    for(;;){
        flag=0;
        if(b[q]<2)return;
        k=chk[q]+1+1e6;
        i=upper_bound(v[k].begin(),v[k].end(),-q)-v[k].begin();
        i=-v[k][i]-1;
        if(i<xi)flag=1;
        r=q;
        if(flag)s=post(p,i),p=i+1,--q;
        else s=post(i+1,q-1),q=i;
        if(b[r]==2)ans-=s;
        else if(b[r]==3){
            if(!flag)ans+=s;
            else ans=s-ans;
        }
        else if(b[r]==4)ans/=s;
        else if(b[r]==5){
            if(!flag)ans*=s;
            else ans=s/ans;
        }
    }
}
int main(){
    int i,s;
    fgets(c,sizeof c,stdin);
    for(i=0;c[i];i+=2){
        if(c[i]=='x')b[t++]=1;
        else if(c[i]=='+')b[t++]=2;
        else if(c[i]=='-')b[t++]=3;
        else if(c[i]=='*')b[t++]=4;
        else if(c[i]=='/')b[t++]=5;
        else if(c[i]=='=')break;
        else{
            s=0;
            while(47<c[i]&&c[i]<58)s=s*10+c[i++]-48;
            --i;
            a[t++]=s;
        }
    }
    i+=2,s=0;
    if(c[i]=='-')s=1,++i;
    while(47<c[i]&&c[i]<58)ans=ans*10+c[i++]-48;
    if(s)ans=-ans;
    for(i=t-1;i--;){
        if(b[i]==1)xi=i;
        chk[i]=chk[i+1]+(b[i]<2?1:-1);
        v[chk[i]+1000000].push_back(-i);
    }
    sol();
    printf("%d",ans);
    return 0;
}
