#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*
	动态规划：背包问题,此背包问题需要记录其对应的价值所装的物品
*/
int coin[10001];
//number代表硬币数量，vec容器盛放对应价值的具体硬币
//当number = -1时，代表刚好对应此价值的硬币总量不存在
struct DP
{
	int number;
	vector<int> vec;
	DP(): number(-1),vec(NULL){}
};
DP dp[101];

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		//N枚硬币，对应0-N-1下标
		scanf("%d", &coin[i]);
	sort(coin+1, coin+N+1);
	dp[0].number = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = M; j >= 0; --j)
		{
			//计算的是刚好的值
			if (j >= coin[i] && dp[j-coin[i]].number != -1)
			{
				//分为两种情况
				//第一种dp[j - coin[i]] + 1 > dp[j]
				//第二种dp[j - coin[i]] + 1 == dp[j]
				//is_update标志是否更新dp[j]的值
				bool is_update = false;

			    if (dp[j - coin[i]].number + 1 > dp[j].number)
					is_update = true;
				if (dp[j-coin[i]].number + 1 == dp[j].number)
				{
					//依次比较dp[j-coin[i]].vec和dp[j].vec里面的值，如果小于则更新，否则不更新
					int length = dp[j].vec.size() - 1;
					for (size_t k = 0; k < length; ++k)
					{
						if (dp[j-coin[i]].vec[k] == dp[j].vec[k])
							continue;
						else
						{
							if (dp[j-coin[i]].vec[k] < dp[j].vec[k])
								is_update = true;
							break;
						}
					}
				}
				if (is_update)
				{
					dp[j].number = dp[j-coin[i]].number + 1;
					int length = dp[j].number - 1;
					dp[j].vec.clear();
					for (size_t k = 0; k < length ; ++k)
						dp[j].vec.push_back(dp[j-coin[i]].vec[k]);
					dp[j].vec.push_back(coin[i]);
				}
			}
		}
	}
	if (dp[M].number == -1)
	{
		printf("No Solution");
	}
	else
	{
		printf("%d", dp[M].vec[0]);
		int length = dp[M].vec.size();
		for (size_t i = 1; i < length; ++i)
			printf(" %d", dp[M].vec[i]);
	}
	printf("\n");
	return 0;
}
