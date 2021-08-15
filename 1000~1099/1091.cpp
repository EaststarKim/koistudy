#include <stdio.h>
int p[10010],a[100010],l[100010],r[100010],idx[100010],t[1<<18],cnt;
void trav(int n){
	if(!n)return;
	trav(l[n]);
	idx[n]=++cnt;
	trav(r[n]);
}
void update(int n,int s,int e,int k,int v){
	if(s==e){
		t[n]=v;
		return;
	}
	int l=n*2,r=l+1,m=(s+e)/2;
	if(k>m)update(r,m+1,e,k,v);
	else update(l,s,m,k,v);
	t[n]=t[l]+t[r];
}
int query(int n,int s,int e,int si,int ei){
	if(ei<s||e<si)return 0;
	if(si<=s&&e<=ei)return t[n];
	int l=n*2,r=l+1,m=(s+e)/2;
	return query(l,s,m,si,ei)+query(r,m+1,e,si,ei);
}
int main(){
	int i,j,n,q,x,y,z;
	char c;
	for(i=2;i<1e4;++i){
		for(j=2;j*j<i&&i%j;++j);
		if(j*j>i)p[i]=1;
	}
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<n;++i){
		scanf("%d%d %c\n",&x,&y,&c);
		if(c=='L')l[x]=y;
		else r[x]=y;
	}
	trav(1);
	for(i=1;i<=n;++i)update(1,1,n,idx[i],p[a[i]]);
	scanf("%d",&q);
	for(;q--;){
		scanf("%d%d%d",&x,&y,&z);
		if(x<2){
			if(idx[y]>idx[z])y^=z^=y^=z;
			printf("%d\n",query(1,1,n,idx[y],idx[z]));
		}
		else update(1,1,n,idx[y],p[z]);
	}
	return 0;
}
