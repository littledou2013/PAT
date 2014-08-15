#include <iostream>
#include <cstdio>
using namespace std;
/**
  此题有点难，需要设置的变量比较多，搞清楚每一个变量的意义非常重要
**/
int main(void)
{
   int lasti, lastj, lsum, max;
   int curri, currj, val;
   int N;
   scanf("%d", &N);
   scanf("%d", &lsum);
   max = lsum;
   int first = lsum;
   lasti = lastj = lsum;
   curri = currj = lsum;
   for (int i = 1; i < N; ++i)
   {
     scanf("%d", &val);
     /*分为几种情况
      lsum >= 0, 直接加
      lsum < 0, 换成val
      最后都与曾经计算的最大的max进行比较，
      如果大于max，则更新max,和前后值，
      如果小于或等于max，则不用管，
     */
     if (lsum >= 0)
     {
      lsum += val;
      currj = val;
     }
     else
     {
      lsum = val;
      curri = currj = val;
     }
     if (lsum > max)
     {
       max = lsum;
       lasti = curri;
       lastj = currj;
     }
   }
  if (max < 0)
	  printf("0 %d %d\n", first, val);
  else
	 printf("%d %d %d\n", max, lasti, lastj);
  return 0;
}
