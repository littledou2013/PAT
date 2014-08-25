#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Bill
{
	char name[21];
	int month, day, hour, minite, total;
	bool is_on;
	bool operator < (const Bill &bill) const
	{
		int is_same = strcmp(name, bill.name);
		if (is_same > 0)
			return false;
		if (is_same < 0)
			return true;
		return total < bill.total;
	}
};

int toll[24];
vector<Bill> bill;
vector<Bill> format_bill[1000];
int chargeByTime(int time)
{
	int day = time / (24 * 60);
	time %= 24 * 60;
	int hour = time / 60;
	time %= 60;
	int one_day = 0 , money = 0;
	for (int i = 0; i < 24; ++i)
		one_day += toll[i] * 60;
	money = one_day * day;
	for (int i = 0; i < hour; ++i)
		money += toll[i] * 60;
	money += toll[hour] * time;
	return money;
}
float getMoney(Bill bill1, Bill bill2)
{
	return (chargeByTime(bill2.total) - chargeByTime(bill1.total)) * 0.01;
}
int main(void)
{
	for (int i = 0; i < 24; ++i)
		scanf("%d", &toll[i]);
	int N;
	scanf("%d", &N);
	char status[10];
	Bill b;
	for (int i = 0; i < N; ++i)
	{
		scanf("%s%d:%d:%d:%d%s",b.name, &b.month, &b.day, &b.hour, &b.minite, status);
		b.total = b.day * 24 * 60 + b.hour * 60 + b.minite;
		if (status[1] == 'n')
			b.is_on = true;
		else
			b.is_on = false;
		bill.push_back(b);
	}
	sort(bill.begin(), bill.end());
	//提取有效的记录非常关键
	int index = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		if (strcmp(bill[i].name, bill[i+1].name) == 0 && bill[i].is_on == true && bill[i+1].is_on == false)
		{
			format_bill[index].push_back(bill[i]);
			format_bill[index].push_back(bill[i+1]);
		}
		if (strcmp(bill[i].name, bill[i+1].name) != 0)
			++index;
	}
	float total, money;
	for (int i = 0; i <= index; ++i)
	{
		total = 0;
		//这里一定要加一个判断否则两个测试案例过不了
		if (format_bill[i].size() > 0)
		{
			printf("%s %02d\n", format_bill[i][0].name, format_bill[i][0].month); 
			for (int j = 0; j < format_bill[i].size(); j+=2)
			{
				money = getMoney(format_bill[i][j], format_bill[i][j+1]);
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02f\n",
					format_bill[i][j].day,format_bill[i][j].hour,format_bill[i][j].minite,
					format_bill[i][j+1].day,format_bill[i][j+1].hour,format_bill[i][j+1].minite,
					format_bill[i][j+1].total - format_bill[i][j].total, money);
				total += money;
			}
			printf("Total amount: $%.02f\n", total);	
		}
	}
	return 0;
}

//方法二
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int toll[24];
map<string, int> s2i;
struct Time
{
	int day, hour, minite;
	bool is_on;
	bool operator < (const Time &time) const
	{
		if (day != time.day)
			return day < time.day;
		if (hour != time.hour)
			return hour < time.hour;
		return minite < time.minite;
	}
};

struct Person
{
	vector<Time> line;
	vector<int> online;
	vector<int> time;
	vector<int> money;
	int sum;
};
Person person[1000];

int getTime(Time start, Time end)
{
	int m = start.day * 24 * 60 + start.hour * 60 + start.minite;
	int n = end.day * 24 * 60 + end.hour * 60 + end.minite;
	return n - m;
}
int getMoney(Time start, int time)
{
	int index = start.hour;
	int money;
	if (time + start.minite >= 60)
	{
		money = toll[index] * (60 - start.minite);
		time -= (60 - start.minite);
	}
	else
	{
		money = toll[index] * time;
		time = 0;
	}
	++index;
	while (time > 0)
	{
		index %= 24;
		if (time >= 60)
		{
			money += 60 * toll[index];
			time -= 60;
		}
		else
		{
			money += time * toll[index];
			time = 0;
		}
		++index;
	}
	return money;
}
int main(void)
{
	for (int i = 0; i < 24; ++i)
		scanf("%d", &toll[i]);
	int N, index = 0, node, month;
	scanf("%d", &N);
	string str;
	Time time;
	char state[10];
	for (int i = 0; i < N; ++i)
	{
		cin>>str;
		if (s2i.find(str) == s2i.end())
		{
			s2i[str] = index;
			node = index;
			++index;
		}
		else
		{
			node = s2i[str];
		}
		scanf("%d:%d:%d:%d%s", &month, &time.day, &time.hour, &time.minite, state);
		if (state[1] == 'n')
		{
			time.is_on = true;
		}
		else
		{
			time.is_on = false;
		}
		person[node].line.push_back(time);
	}
	for (int i = 0; i < index; ++i)
	{
		sort(person[i].line.begin(), person[i].line.end());
		int length = person[i].line.size() - 1;
		person[i].sum = 0;
		for (size_t j = 0; j < length; ++j)
		{
			if (person[i].line[j].is_on && !person[i].line[j+1].is_on)
			{
				person[i].online.push_back(j);
				int time = getTime(person[i].line[j], person[i].line[j+1]);
				int money = getMoney(person[i].line[j], time);
				person[i].time.push_back(time);
				person[i].money.push_back(money);
				person[i].sum += money;
			}
		}
	}
	for (map<string, int>::iterator iter = s2i.begin(); iter != s2i.end(); ++iter)
	{
		node = iter->second;
		if (person[node].online.size() > 0)
		{
			cout<<iter->first;
			printf(" %02d\n", month);
			for (size_t i = 0; i < person[node].online.size(); ++i)
			{
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02f\n", person[node].line[person[node].online[i]].day,
					person[node].line[person[node].online[i]].hour,
					person[node].line[person[node].online[i]].minite,
					person[node].line[person[node].online[i] + 1].day, 
					person[node].line[person[node].online[i] + 1].hour, 
					person[node].line[person[node].online[i] + 1].minite, 
					person[node].time[i], person[node].money[i] * 0.01);
			}
			printf("Total amount: $%.02f\n", person[node].sum * 0.01);
		}
	}
	return 0;
}
