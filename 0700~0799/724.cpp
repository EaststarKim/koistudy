#include<stdio.h>   
#include<memory.h>   
#include<queue>   
  
struct coord{   
    int x,y;   
} f[1010];   
  
std::queue<coord> Q;   
int n,w,dist[1010][1010],D[1010][1010],tx1,ty1,tx2,ty2;   
int flag[8][2]={2,1,1,2,2,-1,-1,2,-2,1,1,-2,-2,-1,-1,-2};   
inline int abs(int d){   
    return d>0?d:-d;   
}   
inline int min(int a,int b){   
    return a>b?b:a;   
}   
inline int min(int a,int b,int c){   
    return a>b ? b>c?c:b : a>c?c:a;   
}   
  
int fun(int a,int b){   
    int next = a>b?a:b;   
    ++next;   
    if(D[a][b]!=-1);   
    else if(next==w+2) D[a][b]=0;   
    else{   
        int nextb=fun(next,b);   
        int anext=fun(a,next);   
        nextb += min( dist[abs(f[a].x-f[next].x)][abs(f[a].y-f[next].y)],   
  dist[abs(f[a].x-tx1)][abs(f[a].y-ty1)]+dist[abs(tx2-f[next].x)][abs(ty2-f[next].y)],   
 dist[abs(f[a].x-tx2)][abs(f[a].y-ty2)]+dist[abs(tx1-f[next].x)][abs(ty1-f[next].y)]);   
        anext += min( dist[abs(f[b].x-f[next].x)][abs(f[b].y-f[next].y)],   
  dist[abs(f[b].x-tx1)][abs(f[b].y-ty1)]+dist[abs(tx2-f[next].x)][abs(ty2-f[next].y)],   
 dist[abs(f[b].x-tx2)][abs(f[b].y-ty2)]+dist[abs(tx1-f[next].x)][abs(ty1-f[next].y)]);   
  
        D[a][b] = min(anext, nextb);   
    }   
    return D[a][b];   
}   
int main(){   
    int i,j;   
    memset(D,-1,sizeof(D));   
    scanf("%d%d",&n,&w);   
    scanf("%d%d%d%d",&tx1,&ty1,&tx2,&ty2);   
    for(i=2;i<w+2;i++)   
        scanf("%d%d",&f[i].x,&f[i].y);   
  
    f[0].x=f[0].y=1;   
    f[1].x=f[1].y=n;   
  
    coord f;   
    f.x=f.y=0;   
    Q.push(f);   
    while(!Q.empty())   
    {   
        f=Q.front();   
        Q.pop();   
        for(i=0;i<8;i++){   
            int xx = f.x + flag[i][0], yy = f.y + flag[i][1];   
            if(xx>=0 && yy >= 0 && xx<n && yy<n && dist[xx][yy]==0){   
                dist[xx][yy]=dist[f.x][f.y]+1;   
                coord pus;   
                pus.x=xx;   
                pus.y=yy;   
                Q.push(pus);   
            }   
        }   
    }   
    dist[0][0]=0;   
    dist[1][1]=2;   
    printf("%d", fun(0,1));   
}  