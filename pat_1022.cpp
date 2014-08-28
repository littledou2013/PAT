#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
using namespace std;

map<string, set<int> > Title;
map<string, set<int> > Author;
map<string, set<int> > Key;
map<string, set<int> > Publisher;
map<string, set<int> > Year;


int main(void)
{
	int N;
	scanf("%d", &N);
	int id;
	string title, author, key, publisher, year;
	string str;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &id);
		getchar();
		getline(cin, title);
		getline(cin, author);
		getline(cin, key);
		getline(cin, publisher);
		getline(cin, year);
		Title[title].insert(id);
		Author[author].insert(id);
		int start = 0, length = key.size(), index = 0;
		while (index < length)
		{
			while (index < length && key[index] != ' ')
				++index;
			str = key.substr(start,index - start);
			Key[str].insert(id);
			++index;
			start = index;
			
		}
		Publisher[publisher].insert(id);
		Year[year].insert(id);	
	}
	int M;
	scanf("%d", &M);
	int tt, tyear;
	
	for (int i = 0; i < M; ++i)
	{
		scanf("%d: ", &tt);
		set<int> result;
		getline(cin, str);
		cout<<tt<<": "<<str<<endl;
		switch(tt)
		{
		case 1: result = Title[str];break;
		case 2:	result = Author[str];break;
		case 3:	result = Key[str];break;
		case 4:	result = Publisher[str];break;
		case 5:	result = Year[str];break;
		}
		if (result.size() == 0)
			printf("Not Found\n");
		else
		{
			for (set<int>::iterator iter = result.begin(); iter != result.end(); ++iter)
				printf("%07d\n", *iter);
		}
	}
	return 0;
}
