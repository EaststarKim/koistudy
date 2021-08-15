#include <stdio.h>
#define F(i) for(s[i]=0;s[i]<100;++s[i])
int a[4][3],s[4];
int main(){
    int i,j;
    for(i=0;i<4;++i)for(j=0;j<3;++j)scanf("%d",a[i]+j);
    F(1)F(2)F(3){
        int t[3]={},r=0;
        for(i=1;i<4;++i)for(j=0;j<3;++j)t[j]+=a[i][j]*s[i];
        for(i=0;i<3;++i){
            if(a[0][i]){
                if(!t[i]||t[i]%a[0][i])break;
                t[i]/=a[0][i];
                if(r&&r!=t[i])break;
                r=t[i];
            }
            else if(t[i])break;
        }
        if(i>2){
            printf("%d %d %d %d",s[1],s[2],s[3],r);
            return 0;
        }
    }
    puts("NONE");
    return 0;
}
