#include <cstdio>      
#include <algorithm>      
#define M_MAX 3020      
#define N_MAX 110       
struct state {      
    bool isLine;      
    int num;      
} list[M_MAX*2], t;        
int n, m, map[M_MAX][M_MAX], nList[M_MAX][N_MAX], nFull[M_MAX], rNum[M_MAX], gList[M_MAX][N_MAX], gFull[M_MAX], rGroup[M_MAX], minNum, selected[M_MAX];      
bool chk[M_MAX][M_MAX];      
int getScore(state &x){      
    return x.isLine?rNum[x.num]:rGroup[x.num];      
}       
bool compare(state &x, state &y){      
    return getScore(x) < getScore(y);      
}      
void process(state &x, bool recur){      
    int i, d;      
    bool find=0;      
    if(x.isLine){      
        for(i=0; i<nFull[x.num]; i++){       
            if(chk[x.num][nList[x.num][i]]){      
                chk[x.num][nList[x.num][i]] = 0;      
                rGroup[nList[x.num][i]]--;      
                if(!find) {      
                    selected[nList[x.num][i]] = x.num;      
                    d = nList[x.num][i];      
                    rGroup[d] = n+1;      
                    find = 1;      
                }      
            }      
        }      
        for(i=0; i<gFull[d]; i++)      
            if(chk[gList[d][i]][d])      
                chk[gList[d][i]][d] = 0;      
        rNum[x.num] = n+1;      
    } else {      
        for(i=0; i<gFull[x.num]; i++){      
            if(chk[gList[x.num][i]][x.num]){      
                chk[gList[x.num][i]][x.num] = 0;      
                rNum[gList[x.num][i]]--;      
                if(!find) {      
                    selected[x.num] = gList[x.num][i];      
                    d = gList[x.num][i];      
                    rNum[d] = n+1;      
                    find = 1;      
                }      
            }      
        }      
        for(i=0; i<nFull[d]; i++)      
            if(chk[d][nList[d][i]])      
                chk[d][nList[d][i]] = 0;      
        rGroup[x.num] = n+1;      
    }      
}        
void getMin(){      
    minNum = 0;      
     
    int i;      
    for(i=1; i<2*m; i++)      
        if(getScore(list[i]) < getScore(list[minNum]))      
            minNum = i;      
}       
int main(){      
    scanf("%d%d", &m, &n);      
     
    int i, j, t;      
    for(i=1; i<=m; i++){      
        for(j=1; j<=n; j++){      
            scanf("%d", &t);      
            if(!map[t][i]){      
                map[t][i] = j;      
                chk[t][i] = 1;      
                nList[t][nFull[t]++] = i;      
                gList[i][gFull[i]++] = t;      
            }      
        }      
    }         
    for(i=0; i<m; i++){      
        rGroup[i+1] = gFull[i+1];      
        list[i*2].isLine = 0;      
        list[i*2].num = i+1;      
        rNum[i+1] = nFull[i+1];      
        list[i*2+1].isLine = 1;      
        list[i*2+1].num = i+1;      
    }      
    getMin();      
    while(getScore(list[minNum]) <= n){      
        process(list[minNum], 0);      
        getMin();      
    }      
    for(i=1; i<=m; i++)      
        printf("%d %d\n", selected[i], map[selected[i]][i]);      
     
    return 0;      
}  