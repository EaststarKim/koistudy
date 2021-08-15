#include<stdio.h>         
int a,b,n,i,j,k,q[1000002][2],w[10][2],sx,sy,h,t,v[1001][1001],D[1001][1001],s;         
char p[1001][1001];
void BFS(int x,int y)         
{         
    if(x>0&&v[x-1][y]==0&&p[x-1][y]!='X'){         
        v[x-1][y]=1,q[t][0]=x-1,q[t++][1]=y,D[x-1][y]=D[x][y]+1;}         
    if(x<a-1&&v[x+1][y]==0&&p[x+1][y]!='X'){         
        v[x+1][y]=1,q[t][0]=x+1,q[t++][1]=y,D[x+1][y]=D[x][y]+1;}         
    if(y>0&&v[x][y-1]==0&&p[x][y-1]!='X'){         
        v[x][y-1]=1,q[t][0]=x,q[t++][1]=y-1,D[x][y-1]=D[x][y]+1;}         
    if(y<b-1&&v[x][y+1]==0&&p[x][y+1]!='X'){         
        v[x][y+1]=1,q[t][0]=x,q[t++][1]=y+1,D[x][y+1]=D[x][y]+1;}         
}         
int main(){         
    scanf("%d%d%d",&a,&b,&n);         
    for(i=0;i<a;i++){         
        scanf("%s",p[i]);         
        for(j=0;j<b;j++){         
            if(p[i][j]>='1'&&p[i][j]<='9'){         
                w[p[i][j]-'0'][0]=i,w[p[i][j]-'0'][1]=j;         
            }         
            if(p[i][j]=='S'){         
                sx=i,sy=j;         
            }         
        }         
    }         
    for(i=1;i<=n;i++){         
        t=h=0;         
        q[t][0]=sx,q[t++][1]=sy;         
        D[sx][sy]=0;         
        v[sx][sy]=1;         
        while(v[w[i][0]][w[i][1]]==0){         
            BFS(q[h][0],q[h][1]);         
            h++;}         
        for(j=0;j<a;j++)for(k=0;k<b;k++)v[j][k]=0;         
        s+=D[w[i][0]][w[i][1]];         
        sx=w[i][0],sy=w[i][1];         
    }         
    printf("%d\n",s);         
}  