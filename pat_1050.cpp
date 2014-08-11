#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string str1;
string str2;
bool has[128];
int main(void)
{
	getline(cin,str1);
	getline(cin,str2);
	for (int i = 0; i < 128; ++i)
		has[i] = true;
	int length1 = str1.size();
	int length2 = str2.size();
	for (int i = 0; i < length2; ++i)
		has[str2[i]] = false;
	for (int i = 0; i < length1; ++i)
		if (has[str1[i]])
			printf("%c", str1[i]);
	printf("\n");
	return 0;
}
