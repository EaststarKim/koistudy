#include <stdio.h>
struct data{
	int e,t;
}a[5010][5010];
int l[5010],D[5003],ans=1e9;
int q[1000010],f,r;
void bfs(int x){
    int i,s,e,t;
    f=0,r=1;
    D[q[1]=x]=0;
	while(f<r){
        s=q[++f];
        for(i=1;i<=l[s];++i){
            e=a[s][i].e,t=a[s][i].t;
            if(D[1]>D[s]+t){
                if(e>1||s!=x){
                    if(D[e]>D[s]+t){
                        D[e]=D[s]+t;
                        if(e>1)q[++r]=e;
                    }
                }
            }
        }
	}
}
int main(){
    int i,j,n,m,x,y,z,w;
	scanf("%d%d",&n,&m);
	for(;m--;){
		scanf("%d%d%d%d",&x,&y,&z,&w);
        a[x][++l[x]]={y,z};
        a[y][++l[y]]={x,w};
	}
	for(i=1;i<=l[1];++i){
		x=a[1][i].e,y=a[1][i].t;
		if(ans>y){
            for(j=1;j<=n;++j)D[j]=1e9;
            bfs(x);
            if(D[1]&&ans>D[1]+y)ans=D[1]+y;
		}
    }
	printf("%d",ans);
	return 0;
}
