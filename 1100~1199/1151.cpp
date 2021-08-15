#include <stdio.h>
int main(){
    int i,m1=1e4,m2=1e4,a;
    for(i=1;i<4;++i)scanf("%d",&a),m1=m1<a?m1:a;
    for(i=1;i<3;++i)scanf("%d",&a),m2=m2<a?m2:a;
    printf("%d",m1+m2-50);
    return 0;
}
