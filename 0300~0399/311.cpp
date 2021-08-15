#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k;
int chu[15];

int counts = 0;
__int64 answers[660000];

void input()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		scanf("%d", chu + i);
	scanf("%d", &k);
}

int filled[10];

inline void make()
{
	__int64 su = 0;
	int i;

	for(i=0; i<10; ++i)
		su = su * 10 + filled[i];

	if(su > 0)
	{
		answers[++counts] = su;
	}
}

void backtracking(int cn, int lsum, int rsum)
{
	if(cn == n)
	{

		int torque = rsum - lsum;
		int pos;

		if(torque == 0)
		{
			make();
		}

		else if(torque < 0)
		{
			if((-torque) % chu[cn] == 0)
			{
				pos = (-torque) / chu[cn];
				if(1 <= pos && pos <= 5)
				{
					if(filled[pos + 4] == 0)
					{

						filled[pos + 4] = chu[cn];
						make();
						filled[pos + 4] = 0;
					}
				}
			}
		}

		else
		{
			if(torque % chu[cn] == 0)
			{
				pos = 6 - (torque / chu[cn]);
				if(1 <= pos && pos <= 5)
				{
					if(filled[pos - 1] == 0)
					{
						filled[pos - 1] = chu[cn];
						make();
						filled[pos - 1] = 0;
					}
				}
			}
		}

		return;
	}

	backtracking(cn + 1, lsum, rsum);

	int i;
	for(i=0; i<5; ++i)
	{
		if(filled[i]) continue;

		filled[i] = chu[cn];
		backtracking(cn + 1, lsum + chu[cn] * (5 - i), rsum);
		filled[i] = 0;
	}

	for(i=0; i<5; ++i)
	{
		if(filled[i + 5]) continue;

		filled[i + 5] = chu[cn];
		backtracking(cn + 1, lsum, rsum + (i + 1) * chu[cn]);
		filled[i + 5] = 0;
	}
}

int main()
{
	input();
	backtracking(1, 0, 0);
	sort(answers + 1, answers + counts + 1);

	if(k <= counts)
		printf("%I64d\n", answers[k]);
	else printf("%I64d\n", answers[counts]);

	return 0;
}