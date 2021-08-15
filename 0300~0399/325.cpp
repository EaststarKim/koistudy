#include<stdio.h>

int d[505][1005];

int a[505][1005];

int x[1005];

struct STR {

    int conk, con[505], conwhat[505];

} town[505];

int main () {

    int n,i,j;

    scanf("%d",&n);

    char c;

    for(i=1;i<=n;i++) {

        scanf(" %c",&c);

        if (c=='R') x[i]=1;

        else if (c=='G') x[i]=2;

        else x[i]=3;

    }

    a[1][0]=1;

    int m,k;

    scanf("%d %d",&m,&k);

    for(i=1;i<=m;i++) town[i].conk=0;

    for(i=1;i<=k;i++) {

        int x,y,t;

        scanf("%d %d %c",&x,&y,&c);

        if (c=='R') t=1;

        else if (c=='G') t=2;

        else t=3;

        town[x].con[++town[x].conk]=y;

        town[x].conwhat[town[x].conk]=t;

        town[y].con[++town[y].conk]=x;

        town[y].conwhat[town[y].conk]=t;

    }

    for(i=1;i<=n;i++) {

        for(j=1;j<=m;j++) {

            for(k=1;k<=town[j].conk;k++) {

                if (a[town[j].con[k]][i-1]==1) {

                    a[j][i]=1;

                    if (town[j].conwhat[k]==x[i]) {

                        if (d[j][i]<d[town[j].con[k]][i-1]+10) d[j][i]=d[town[j].con[k]][i-1]+10;

                    }

                    else

                        if (d[j][i]<d[town[j].con[k]][i-1]) d[j][i]=d[town[j].con[k]][i-1];

                }

            }

        }

    }

    int max=0;

    for(i=1;i<=m;i++) {

        if (max<d[i][n]) max=d[i][n];

    }

    printf("%d",max);

}