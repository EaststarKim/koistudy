#include<stdio.h>      
#include<vector>      
struct pos{      
    int x,y;      
};      
int n, m;      
int map[12][12], numHouse, res;      
bool chk[12][12];      
pos church;      
std::vector < pos > dir[5][12][12];      
void fly(int x, int y, int cnt){      
    if(numHouse == cnt){      
        if(x == church.x || y == church.y) res++;      
        return;      
    }      
    int i, j;      
    for(i=0; i<4; i++){      
        for(j=0; j<dir[i][y][x].size(); j++){      
            if(!chk[dir[i][y][x][j].y][dir[i][y][x][j].x]){      
                chk[dir[i][y][x][j].y][dir[i][y][x][j].x] = 1;      
                fly(dir[i][y][x][j].x, dir[i][y][x][j].y, cnt+1);      
                chk[dir[i][y][x][j].y][dir[i][y][x][j].x] = 0;      
                break;      
            }      
        }      
    }      
}      
int main(){      
    scanf("%d%d", &m, &n);      
    int i, j, k;      
    for(i=1; i<=n; i++){      
        for(j=1; j<=m; j++){      
            scanf("%d", &map[i][j]);      
            if(map[i][j] == 2) church.x = j, church.y = i;      
            else if(map[i][j] == 1) numHouse++;      
        }      
    }      
    pos tmp;      
    for(i=1; i<=n; i++){      
        tmp.y = i;      
        for(j=1; j<=m; j++){      
            if(map[i][j] == 1){      
                tmp.x = j;      
                for(k=j-1; k>=1; k--)      
                    if(map[i][k] > 0) dir[0][i][k].push_back(tmp);      
            }      
        }      
        for(j=m; j>=1; j--){      
            if(map[i][j] == 1){      
                tmp.x = j;      
                for(k=j+1; k<=m; k++)      
                    if(map[i][k] > 0) dir[1][i][k].push_back(tmp);      
            }      
        }      
    }      
    for(j=1; j<=m; j++){      
        tmp.x = j;      
        for(i=1; i<=n; i++){      
            if(map[i][j] == 1){      
                tmp.y = i;      
                for(k=i-1; k>=1; k--)      
                    if(map[k][j] > 0) dir[2][k][j].push_back(tmp);      
            }      
        }      
        for(i=n; i>=1; i--){      
            if(map[i][j] == 1){      
                tmp.y = i;      
                for(k=i+1; k<=n; k++)      
                    if(map[k][j] > 0) dir[3][k][j].push_back(tmp);      
            }      
        }      
    }      
    fly(church.x, church.y, 0);      
    printf("%d\n", res);      
    return 0;      
}  