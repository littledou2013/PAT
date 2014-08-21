#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n)
{
	if (n < 2)
		return false;
	int mid = sqrt(double(n));
	for (int i = 2; i <= mid; ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;

}
int main(void)
{
	int N, radix;
	vector<int> vec;
	while(scanf("%d", &N) != EOF && N >= 0)
	{
		vec.clear();
		scanf("%d", &radix);
		while(N > 0)
		{
			vec.push_back(N % radix);
			N /= radix;
		}
		int m = 0, n = 0;
		int size = vec.size();
		for (int i = 0; i < size; ++i)
		{
			m *= radix;
			m += vec[i];
		}
		for (int i = size - 1; i >= 0; --i)
		{
			n *= radix;
			n += vec[i];
		}
		if (isPrime(m) && isPrime(n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
