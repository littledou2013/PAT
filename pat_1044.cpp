#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
struct Pair
{
	int i;
	int j;
};
vector<Pair> solu;
vector<Pair> solu1;
vector<int> diamonds;

int getSolution (int M, int N)
{
	int start = 0;
	int sum = 0;
	int maxsum = INT_MAX;
	Pair p;
	for (int i = 0; i < N; ++i)
	{
		sum += diamonds[i];
		if (sum >= M) 
		{
			if (sum == M)
			{
				p.i = start;
				p.j = i;
				solu.push_back(p);
			}			
			do
			{
				if (sum < maxsum)
				maxsum = sum;
				sum -= diamonds[start];
				++start;
			} while (sum > M);
			if (sum == M)
			{
				p.i = start;
				p.j = i;
				solu.push_back(p);
				sum -= diamonds[start];
				++start;
			}
		}
	}
	return maxsum;
}
int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	diamonds.resize(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &diamonds[i]);
	solu.clear();
	int maxsum = getSolution(M, N);
	if (solu.size() == 0)
		getSolution(maxsum, N);

	for (vector<Pair>::iterator iter = solu.begin(); iter != solu.end(); ++iter)
		printf("%d-%d\n", iter->i + 1, iter->j + 1);
	return 0;
}
