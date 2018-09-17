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
int fa[maxn];
int dis[maxn];
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
	cout << "pos: ";
	for (int i = 0; i <= n; i ++)
		cout << pos[i] << '\t';
	cout << endl;
    cout << "father: ";
    for (int i = 0; i <= n; i ++)
        cout << fa[i] << '\t';
    cout << endl;
    cout << "dis: ";
    for (int i = 0; i <= n; i++)
      cout << dis[i] << '\t';
    cout << endl;
	cout << "t: ";
	for (int i = 0; i <= 2 * n; i ++)
		cout << t[i] << '\t';
	cout << endl;
	cout << "dep: ";
	for (int i = 0; i <= 2 * n; i ++)
		cout << dep[i] << '\t';
	cout << endl;
}

void dfs(int u, int dfn)
{
	int i;
	//cout << "dfs start " << u << '\t' << dfn << endl;
	//not visited
	if (!v[u])
	{
		v[u] = 1;
		pos[u] = tot;
	}
	dep[tot] = dfn;
	t[tot++] = u;
    /*
	cout << "pos " << u << " :" << pos[u] << endl;
	cout << "dep " << tot -1 << " :" << dep[tot-1] << endl;
	cout << "t " << tot -1 << " :" << t[tot-1] << endl;
	*/
    vector<NodeType>::iterator p;
	for(p = node[u].begin(); p < node[u].end(); p++)
	{
		if (v[p->son])
			continue;
        fa[p->son] = u;
        dis[p->son] += p->dis;
        //cout << "fa " << p->son << '\t' << fa[p->son] << endl;
        //cout << "dis " << p->son << '\t' << dis[p->son] << endl;
		dfs(p->son, dfn+1);
		dep[tot]=dfn;
		t[tot]=u;
		tot++;
		//cout << "dep " << tot - 1 << " :" << dep[tot-1] << endl;
		//cout << "t " << tot -1 << " :" << t[tot-1] << endl;
	}	
	//cout << "dfs end " << u << '\t' << dfn << endl;	
}

void init() 
{
  int i, j;

  //initialize dp for the intervals with length 1
  for (i = 1; i <= tot; i++)
    dp[i][0] = i;
  //compute values from smaller to bigger intervals
  for (j = 1; 1 << j <= tot; j++)
    for (i = 1; i + (1 << j) - 1 < tot; i++)
        if (dep[dp[i][j - 1]] < dep[dp[i + (1 << (j - 1))][j - 1]])
          dp[i][j] = dp[i][j - 1];
        else
          dp[i][j] = dp[i + (1 << (j - 1))][j - 1];
}

int RMQ(int p1, int p2)
{
  int k = 0;
  k = log2 (p2 - p1 + 1);
  //if ((1 << k) < p2 - p1 + 1) 
   // k++;
  //cout << p1 << '\t' << k << p2 - (1 << k) + 1 << endl;
   //cout << dp[p1][k] << '\t' << dp[p2-(1<<k)+1][k] << endl;
  if (dep[dp[p1][k]] < dep[dp[p2 - (1 << k) + 1][k]])
        return t[dp[p1][k]];
  else
        return t[dp[p2 - (1 << k) + 1][k]];
}

int lca(int v1, int v2)
{
  if (pos[v1] < pos[v2])
        return RMQ(pos[v1], pos[v2]);
  else
        return RMQ(pos[v2], pos[v1]);
}

int sum(int node, int parent)
{
  int value = 0;
  
}
int main()
{
	int T = 0;
	scanf("%d", &T);
	while(T--)
	{
		int m=0;
        tot = 1;
		scanf("%d %d", &n, &m);
		int x = 0, y = 0, value = 0;
		for (int i = 0; i < n - 1; i ++)
		{
			scanf("%d %d %d", &x, &y, &value);
			addEdge(x, y, value);				
		}
		//printTree();
		//printList();
		//init v[], 0
		memset(v, 0, maxn);
		memset(pos, -1, maxn);
        memset(fa, -1, maxn);
        memset(dis, 0, maxn);
		memset(dep, -1, maxn*4);
		memset(t, -1, maxn*4);
        memset(dp,-1, maxn * 4 * 12);

		dfs(1,1);
        
        /*
		for (int i = 1; i <= n; i++)		
			cout << v[i] << '\t';
		cout << endl;
		*/
        //printList();
        init();
        /*
        for (int i = 0; i < tot; i ++)
        {
          cout << "i: " << i << endl;
          for (int j = 0; j < tot; j ++)
            cout << dp[i][j] << '\t';
          cout << endl;
        }
        */
        while(m--)
        {
            int least = 0;
            int p1 = 0, p2 = 0;
            int sum1 = 0, sum2 = 0;
            scanf("%d %d", &p1, &p2);
            least = lca(p1, p2);
            /*
            cout << "least: " << least << endl;*/
            cout << dis[p1] + dis[p2] - 2 * dis[least] << endl;
        }
        for (int i = 0; i <= n; i ++)
          node[i].clear();

	}	
	return 0;
}
