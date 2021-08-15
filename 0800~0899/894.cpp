#include <stdio.h>
int main(){
    int i,a,s=0;
    for(i=1;i<6;++i)scanf("%d",&a),s+=a<40?40:a;
    printf("%d",s/5);
    return 0;
}
