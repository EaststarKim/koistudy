#include <stdio.h>
int main(){
    int i,n,k;
    scanf("%d%d",&n,&k);
    if(n/k>=1e4)puts("��ȣ �ʰ� ����");
    else{
        for(i=1;i<=n/k;++i)printf("F-%04d\n",i);
    }
    return 0;
}
