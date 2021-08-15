#include <stdio.h>

char map[5005][5005];

struct data

{

	int J,O,I;

};

data hori[5005][5005],rec[5005][5005];

int main()

{

	int n,m,k,i,j;

	scanf("%d %d",&n,&m);

	scanf("%d",&k);

	for(i=1;i<=n;i++) scanf("%s",map[i]+1);

	for(i=1;i<=n;i++)

	{

		for(j=1;j<=m;j++)

		{

			hori[i][j] = hori[i][j-1]; // y축으로 누적시킨다.

			switch(map[i][j])

			{

			case 'J':

				hori[i][j].J++;

				break;

			case 'O': 

				hori[i][j].O++;

				break;

			case 'I':

				hori[i][j].I++;

				break;

			}

		}

	}

	for(j=1;j<=m;j++)

	{

		for(i=1;i<=n;i++)

		{

			rec[i][j].J = hori[i][j].J + rec[i-1][j].J; // x축 누적

			rec[i][j].O = hori[i][j].O + rec[i-1][j].O;

			rec[i][j].I = hori[i][j].I + rec[i-1][j].I;

		}

	}

	for(i=0;i<k;i++)

	{

		int a,b,c,d;

		scanf("%d %d %d %d",&a,&b,&c,&d);

		printf("%d %d %d\n",rec[c][d].J - rec[c][b-1].J - rec[a-1][d].J + rec[a-1][b-1].J,rec[c][d].O - rec[c][b-1].O - rec[a-1][d].O + rec[a-1][b-1].O,rec[c][d].I - rec[c][b-1].I - rec[a-1][d].I + rec[a-1][b-1].I); // 그림에서 설명한 것에 대한 식

	}

	return 0;

}
