#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
	//M:栈的最大容量，N:序列长度
	int M, N, K;
	scanf("%d%d%d", &M, &N, &K);
	vector<int> vec;
	//模拟stack
	stack<int> sta;
	for (int i = 0; i < K; ++i)
	{
		vec.clear();
		while(!sta.empty())
			sta.pop();
		int val;
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &val);
			vec.push_back(val);
		}
		//注意last是保存还没有push进去的最小的值
		int last = 1;
		bool is_pop = true;
		for (int j = 0; j < N; ++j)
		{
			for (int k = last; k <= vec[j]; ++k)
				sta.push(k);
			if (vec[j] >= last)
				last = vec[j] + 1;
			if (sta.size() > M || vec[j] != sta.top())
			{
				is_pop = false;
				break;
			}
			sta.pop();
		}
		if (is_pop)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
