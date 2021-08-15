#include <stdio.h>         
int a[6][6],chk[6][6],dr[]={-1,0,1,0},dc[]={0,1,0,-1},cnt;         
void back(int br,int bc,int mr,int mc,int s)         
{         
    int i,j,w,x,y,z;         
    if(s<1)         
    {         
        if(br==mr&&bc==mc)++cnt;         
        return;         
    }         
    for(i=0;i<4;++i)         
    {         
        w=br+dr[i];         
        x=bc+dc[i];         
        if(w<1||w>5||x<1||x>5||a[w][x]||chk[w][x])continue;     
        for(j=0;j<4;++j)         
        {         
            y=mr+dr[j];         
            z=mc+dc[j];         
            if(y<1||y>5||z<1||z>5||a[y][z]||chk[y][z])continue;   
            if(s<3||w!=y||x!=z){   
                chk[w][x]=chk[y][z]=1;         
                back(w,x,y,z,s-2);         
                chk[w][x]=chk[y][z]=0;   
            }   
        }         
    }         
}         
int main()         
{         
    int i,k,r,c;         
    scanf("%d",&k);         
    for(i=1;i<=k;++i)         
    {         
        scanf("%d%d",&r,&c);         
        a[r][c]=1;         
    }         
    chk[1][1]=chk[5][5]=1;         
    back(1,1,5,5,23-k);      
    printf("%d",cnt);         
    return 0;         
}  