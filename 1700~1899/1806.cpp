#include <bits/stdc++.h>
using namespace std;
struct data{
	int s,d;
	bool operator<(const data&r)const{return d/2==r.d/2?s>r.s:d/2<r.d/2;}
}t;
char c[5];
int p[100010],s[100010],e[100010],cnt,mn,mx,ans;
priority_queue<data> q;
int main(){
	int n,m,k;
	scanf("%d%d",&n,&m);
	mn=n+1;
	for(;m--;){
		scanf("%s",c);
		if(c[0]=='I'){
			for(;!q.empty();){
				t=q.top();
				if(e[t.s]==t.s+t.d)break;
				q.pop();
			}
			if(q.empty()){
				if(mn==mx){
					if(mn-1>=n-mx)q.push({1,mn-1}),s[e[1]=mn]=1,mn=ans=1;
					else q.push({mx,n-mx}),e[s[n]=mx]=n,mx=ans=n;
				}
				else mn=mx=ans=1;
			}
			else{
				if(mn-1>=t.d/2&&mn-1>=n-mx)q.push({1,mn-1}),s[e[1]=mn]=1,mn=ans=1;
				else if(n-mx>t.d/2)q.push({mx,n-mx}),e[s[n]=mx]=n,mx=ans=n;
				else q.pop(),q.push({t.s,t.d/2}),q.push({ans=t.s+t.d/2,(t.d+1)/2}),e[s[ans]=t.s]=s[e[ans]=t.s+t.d]=ans;
			}
			p[++cnt]=ans;
		}
		else{
			scanf("%d",&k);
			k=p[k];
			if(mn==mx)mn=n+1,mx=0;
			if(mn==k)mn=e[k];
			if(mx==k)mx=s[k];
			e[s[k]]=e[k],s[e[k]]=s[k];
			if(s[k]&&e[k])q.push({s[k],e[k]-s[k]});
			s[k]=e[k]=0;
		}
	}
	printf("%d",ans);
	return 0;
}
