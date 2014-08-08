#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>
using namespace std;
/*
	首先要理解这个题目，最后输出的单词是一个连续的字符或数字的字符串
	注意几个判断字符的函数
	判断数字 isdigit(c)
	判断字母 isalpha(c)
	判断标点符号 ispunct(c)
	判断字母或数字 isalnum(c)
	判断大写 isupper(c)
	判断小写 islower(c)
*/
string str;
map<string, int> mp;
int main(void)
{
	//输入一行数据
	getline(cin,str);
	int length = str.size();
	for (int i = 0; i < length; ++i)
	{
		if (isalpha(str[i]))
			str[i] = tolower(str[i]);
		else if(ispunct(str[i]))
			str[i] = ' ';
	}
	/*
		我们先采用map键值对的形式解决此题
	*/
	string st;
	//现在我要从string流中读取数据
	istringstream strm(str);
	int max = 0;
	while(strm>>st)
	{
		++mp[st];
		if (mp[st] > max)
			max = mp[st];
	}
	for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
	{
		if (iter->second == max)
		{
			cout<<iter->first<<" "<<iter->second<<endl;
			break;
		}
	}
	return 0;
}
