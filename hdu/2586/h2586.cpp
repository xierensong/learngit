#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string.h>

using namespace std;

#define maxn 40005

typedef struct NodeType {
int son;
int dis;
}NodeType;

vector<NodeType> node[maxn];

int tot=1, value[maxn];
int dep[maxn *4], pos[maxn], t[maxn * 4];
int dp[maxn *4][12];
int v[maxn];
int n = 0;

void addEdge(int x, int y, int value)
{
	NodeType node1, node2;
	node1.son = y;
	node1.dis = value;
	node[x].insert(node[x].end(), node1);
	node2.son = x;
	node2.dis = value;
	node[y].insert(node[y].end(), node2);
}

void printTree()
{
	vector<NodeType>::iterator p;
	for (int i = 1; i <= n; i ++)
	{
		cout << i << '\t';
		for (p = node[i].begin(); p < node[i].end(); p ++)
			cout << p->son << '\t' << p->dis << '\t';
		cout << endl;
	}  	
}

void printList()
{
	cout << "pos: " << '\t';
	for (int i = 1; i <= n; i ++)
		cout << pos[i] << '\t';
	cout << endl;
	cout << "t: " << '\t';
	for (int i = 1; i <= 2 * n; i ++)
		cout << t[i] << '\t';
	cout << endl;
	cout << "dep: " << '\t';
	for (int i = 1; i <= 2 * n; i ++)
		cout << dep[i] << '\t';
	cout << endl;
}

void dfs(int u, int dfn)
{
	int i;
	cout << "dfs start " << u << '\t' << dfn << endl;
	//not visited
	if (!v[u])
	{
		v[u] = 1;
		pos[u] = tot;
	}
	dep[tot] = dfn;
	t[tot++] = u;
	cout << "pos " << u << " :" << pos[u] << endl;
	cout << "dep " << tot -1 << " :" << dep[tot-1] << endl;
	cout << "t " << tot -1 << " :" << t[tot-1] << endl;
	vector<NodeType>::iterator p;
	for(p = node[u].begin(); p < node[u].end(); p++)
	{
		if (v[p->son])
			continue;
		dfs(p->son, dfn+1);
		dep[tot]=dfn;
		t[tot]=u;
		tot++;
		cout << "dep " << tot - 1 << " :" << dep[tot-1] << endl;
		cout << "t " << tot -1 << " :" << t[tot-1] << endl;
	}	
	cout << "dfs end " << u << '\t' << dfn << endl;	
}

int main()
{
	int T = 0;
	scanf("%d", &T);
	while(T--)
	{
		int m=0;
		scanf("%d %d", &n, &m);
		int x = 0, y = 0, value = 0;
		for (int i = 0; i < n - 1; i ++)
		{
			scanf("%d %d %d", &x, &y, &value);
			addEdge(x, y, value);				
		}
		printTree();
		printList();
		//init v[], 0
		memset(v, 0, maxn);
		memset(pos, -1, maxn);
		memset(dep, -1, maxn);
		memset(t, -1, maxn);

		dfs(1,1);

		for (int i = 1; i <= n; i++)		
			cout << v[i] << '\t';
		cout << endl;
		printList();
	}	
	return 0;
}
