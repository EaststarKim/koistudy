#include <stdio.h>
#include <string.h>
char s[6]="RINGS",t[101];
int p[101],b[2][101],D[101][2][101],ans;
int main()
{
	int i,j,k,l,m,n;
	scanf("%s",t);
	m=strlen(t);
	for(i=0;i<m;++i)p[i]=strchr(s,t[i])-s;
	for(i=0;i<2;++i){
		scanf("%s",t);
		n=strlen(t);
		for(j=0;j<n;++j){
			b[i][j]=strchr(s,t[j])-s;
			if(b[i][j]==p[0]){
				D[0][i][j]=1;
				if(m==1)++ans;
			}
		}
	}
	for(i=1;i<m;++i){
		for(j=0;j<2;++j){
			for(k=0;k<n;++k){
				if(b[j][k]==p[i]){
					for(l=0;l<k;++l)D[i][j][k]+=D[i-1][!j][l];
					if(i==m-1)ans+=D[i][j][k];
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
