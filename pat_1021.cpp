#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>

using namespace std;

const int maxx = 10001;

vector<vector<int> > tree;
set<int> res;
set<int> tres;
int cnt,maxn = -1;
vector<bool> visit;

void dfs(int p,int step){
	visit[p] = true;
	for(vector<int>::iterator ite = tree[p].begin();ite!=tree[p].end();++ite){
		if(!visit[*ite]){
			dfs(*ite,step+1);
		}
	}
	if(step>maxn){
		res.clear();
		res.insert(p);
		maxn = step;
	}else if(step==maxn){
		res.insert(p);
	}
}

void init(int n)
{
	for(int i=1;i<=n;++i)
		visit[i]=false;
}

vector<int> root;
int findRoot(int node)
{
	while (root[node] != node)
		node = root[node];
	return node;
}

int main(){
	int n,a,b;
	scanf("%d",&n);
	tree.resize(n+1);
	root.resize(n+1);
	visit.resize(n+1);
	for (int i = 1; i <= n; ++i)
		root[i] = i;
	int count = n;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
		int t1 = findRoot(a);
		int t2 = findRoot(b);
		if (t1 != t2)
		{
			--count;
			root[t1] = t2;
		}
	}
	
	if(count > 1){
		printf("Error: %d components\n",count);
		return 0;
	}
	set<int>::iterator ite;
	init(n);
	dfs(1,1);
	init(n);//因为已经是树，所以不会再有环了，所以所有dfs后都恢复该点的可访问性很重要
	ite = res.begin();
	for(;ite!=res.end();++ite)
	{
		tres.insert(*ite);
	}
	int point = (*res.begin());
	dfs(point,1);
	res.insert(point);

	ite = res.begin();
	for(;ite!=res.end();++ite){
		tres.insert(*ite);
	}

	ite = tres.begin();
	for(;ite!=tres.end();++ite){
		printf("%d\n",*ite);
	}
	return 0;
}
