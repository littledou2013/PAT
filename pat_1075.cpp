#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//定义结构体
struct User
{
	int id;
	int solve;
	int all;
	bool sub;
	bool su[5];
	int score[5];
	User(): solve(0), all(0), sub(false)
	{
		memset(score, 0, sizeof(score));
		memset(su, false, sizeof(su));
	}
	//重载小于符号
	bool operator < (const User & user) const
	{
		if (all != user.all)
			return all > user.all;
		if (solve != user.solve)
			return solve > user.solve;
		if (sub != user.sub)
			return sub;
		return id < user.id;
	}
};

User user[10002];
int pro_score[5];

int main(void)
{
	int N, K, M;
	scanf("%d%d%d", &N, &K, &M);

	//输入每道题分数
	for (int i = 0; i < K; ++i)
		scanf("%d", &pro_score[i]);
	int user_index, pro_num, get_score;

	//输入提交
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d%d", &user_index, &pro_num, &get_score);
		//是否通过编译标志
		if (get_score != -1)
			user[user_index].sub = true;
		if (user[user_index].score[pro_num - 1] < get_score)
		{
			user[user_index].score[pro_num - 1] = get_score;
			
			if (get_score == pro_score[pro_num - 1])
				++(user[user_index].solve);
		}
		//是否提交标志
		user[user_index].su[pro_num - 1] = true;
	}

	//id赋值
	for (int i = 1; i <= N; ++i)
	{
		user[i].id = i;		
		for (int j = 0; j < K; ++j)
		{
			user[i].all += user[i].score[j];
		}
	}
	sort(user+1, user+N+1);
	//输出
	int last_index = 1;
	int i = 1;
	while (i <= N && user[i].sub)
	{
		if (user[i].all != user[last_index].all)
			last_index = i;
		printf("%d %05d %d", last_index, user[i].id, user[i].all);
		for (int j = 0; j < K; ++j)
		{
			if (user[i].su[j])
				printf(" %d", user[i].score[j]);
			else
				printf(" -");
		}
		printf("\n");
		++i;
	}
	return 0;
}
