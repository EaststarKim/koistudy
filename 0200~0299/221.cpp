#include <stdio.h>
int main()
{
	int i,n,sw=0,p;
	long long m,s,k,t,l;
	scanf("%d%lld",&n,&m);
	scanf("%lld",&s);
	if(s>=m)sw=1;
	s%=m;
	for(i=1;i<n;++i){
		scanf("%lld",&k);
		if(!k)sw=0;
		if(k>=m)sw=1;
		k%=m;
		l=1;
		while(l<=k)l*=10;
		l/=10;
		t=s;
		p=0;
		if(!l)s=0;
		while(l){
			++p;
			if(p>1)s=s*10+t*(k/l);
			else s*=k/l;
			if(s>=m)sw=1;
			s%=m;
			k%=l;
			l/=10;
		}
	}
	if(s>=m)sw=1;
	if(sw)printf("%lld",s);
	else printf("%lld",s+1);
	return 0;
}
