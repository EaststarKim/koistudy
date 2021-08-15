#include <stdio.h>
int a[1025][1025],n,p;
char c[2000010];
void back(int sr,int er,int sc,int ec){
    int i,j;
    if(c[++p]!='X'){
        for(i=sr;i<=er;++i){
            for(j=sc;j<=ec;++j)a[i][j]=c[p]-48;
        }
        return;
    }
    int mr=(sr+er)/2,mc=(sc+ec)/2;
    back(sr,mr,sc,mc);
    back(sr,mr,mc+1,ec);
    back(mr+1,er,sc,mc);
    back(mr+1,er,mc+1,ec);
}
int main()
{
    int i,j;
    scanf("%d%s",&n,c+1);
    back(1,n,1,n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}
