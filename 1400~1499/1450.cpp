#include <stdio.h>
char c[1000010];
int a[1000010],lev[1000010],st[20][1000010],t;
void TypeLetter(char L){
    int i;
    c[a[++t]=t]=L;
    lev[t]=lev[st[0][t]=a[t-1]]+1;
    for(i=1;i<20;++i)st[i][t]=st[i-1][st[i-1][t]];
}
void UndoCommands(int U){a[++t]=a[t-U-1];}
char GetLetter(int P){
    int i,x=a[t];
    for(i=20;i--;)if(lev[st[i][x]]>P)x=st[i][x];
    return c[x];
}
int main(){
    int q,x;
    char t;
    scanf("%d",&q);
    for(;q--;){
        scanf("%s",&t);
        if(t=='T'){
            scanf("%s",&t);
            TypeLetter(t);
        }
        else if(t=='U'){
            scanf("%d",&x);
            UndoCommands(x);
        }
        else{
            scanf("%d",&x);
            printf("%c\n",GetLetter(x));
        }
    }
    return 0;
}
