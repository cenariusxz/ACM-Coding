#include <stdio.h>
#include <memory.h>

const int MAX = 102400;

int pAns[MAX];
int pVisited[MAX];

int main()
{
	int T, N, M;
	scanf("%d", &T);
	while(T--)
	{
	//	scanf("%d%d", &N, &M);
		for(N=1;N<=40;N++){
		for(M=2;M<=10;M++){
		//	printf("%d:\n",N);
		long long nTotal = 0;
		if(N & 1) { nTotal = (N + 1) / 2 * N; }
		else { nTotal = N / 2 * (N + 1); }
		if(nTotal % M != 0 || N<2*M-1) {/* printf("NO %d %d\n",N,M);*/ }
		else
		{
		//	printf("YES\n");
			long long nPer = nTotal / M;
			memset(pVisited, false, sizeof(pVisited));
			int summ=0;
			bool f=1;
			for(int i = 1; i <= M; i++)
			{
				summ=0;
				int nCnt = 0, nTmp = 0;
				memset(pAns, 0, sizeof(pAns));
				for(int j = N; j >= 0; j--)
				{
					if(!pVisited[j] && nTmp + j <= nPer)
					{
						nTmp += j;
						pVisited[j] = true;
						pAns[++nCnt] = j;
						if(nTmp == nPer) { break; }
					}
				}
		//		printf("%d ", nCnt);
				for(int j = nCnt; j >= 1; j--)
				{ /*printf("%d ", pAns[j]);*/ summ+=pAns[j];}
		//		printf("\n");
				if(summ!=nPer)f=0;
			}
			for(int i=1;i<=N;i++)if(!pVisited[i])f=0;
			if(!f)printf("WA%d %d\n",N,M);
		//	else printf("AC%d %d\n",N,M);
		}
		}
		}
	}
	return 0;
}
