#include<stdio.h>      
int line[1010];      
int ce[1010][1010];      
int cut(int s,int e){             
    if(ce[s][e]>0)return ce[s][e];      
    int i,energy=999999999;      
    for(i=s+1;i<e;i++){      
        if(line[i]==1){      
            if(energy>cut(s,i)+cut(i,e)){      
                energy=cut(s,i)+cut(i,e);      
            }      
        }      
    }      
    if(energy==999999999)energy=0;      
    ce[s][e]=energy+e-s;      
    return ce[s][e];      
}      
int main(){      
    int a,b,c,i;      
    scanf("%d%d",&a,&b);      
    for(i=0;i<b;i++){      
        scanf("%d",&c);      
        line[c]=1;      
    }      
    printf("%d",cut(0,a)-a);      
}  