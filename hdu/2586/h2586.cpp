#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <string.h>

using namespace std;

#define maxn 41003

typedef struct EdgeType {
int node;
int next;
int dis;
}EdgeType;

EdgeType edges[maxn * 2];

int heads[maxn];
int tot=1, value[maxn];
int dep[maxn *4], pos[maxn], t[maxn * 4];
int dp[maxn *4][25];
int v[maxn];
//int fa[maxn];
int dis[maxn];
int n = 0, size = 0;

void addEdge(int x, int y, int value)
{

    EdgeType  edge1;
    edge1.node = x;
    edge1.next = heads[y];
    edge1.dis = value;
    edges[size] = edge1;
    heads[y] = size++;

    EdgeType edge2;
    edge2.node = y;
    edge2.next = heads[x];
    edge2.dis = value;
    edges[size] = edge2;
    heads[x] = size++;
    
}

void printTree()
{
    int j = 0;
    cout << "head: " << endl;
    for (int i = 1; i <= n; i++)
      cout << i << '\t' << heads[i] << endl;
    cout << endl;
    cout << "edges: " << endl;
    for (int i = 1; i <= size; i++)
      cout <<i << '\t' << edges[i].node << '\t' 
            << edges[i].next << '\t'
            << edges[i].dis << endl;
    cout << endl;
    
	for (int i = 1; i <= n; i ++)
	{
		cout << i << '\t';
		for (j = heads[i]; j > -1; j = edges[j].next)
        {
            cout << edges[j].node << '\t';
			cout << edges[j].dis << '\t';
        }
		cout << endl;
	}  	
}

void printList()
{
	cout << "pos:" << '\t';
	for (int i = 0; i <= n; i ++)
		cout << pos[i] << '\t';
	cout << endl;
    /*
    cout << "father:" << '\t';
    for (int i = 0; i <= n; i ++)
        cout << fa[i] << '\t';
    cout << endl;
    */
    cout << "dis:" << '\t';
    for (int i = 0; i <= n; i++)
      cout << dis[i] << '\t';
    cout << endl;
	cout << "t:" << '\t';
	for (int i = 0; i <= 2 * n; i ++)
		cout << t[i] << '\t';
	cout << endl;
	cout << "dep:" << '\t';
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
    int j = 0;
    for (j = heads[u]; j > -1; j = edges[j].next)
	{
        //cout << "v: " << '\t' << edges[j].node << '\t' << v[edges[j].node] << endl;
		if (v[edges[j].node])
			continue;
        dis[edges[j].node] = dis[u] + edges[j].dis;
        //cout << "dis " << edges[j].node << '\t' << edges[j].dis << endl;
		dfs(edges[j].node, dfn+1);
		dep[tot]=dfn;
		t[tot++]=u;
        /*
		cout << "dep " << tot - 1 << " :" << dep[tot-1] << endl;
		cout << "t " << tot -1 << " :" << t[tot-1] << endl;
        */
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
        if (dep[dp[i][j - 1]] < dep[dp[i + (1 << j - 1)][j - 1]])
          dp[i][j] = dp[i][j - 1];
        else
          dp[i][j] = dp[i + (1 << j - 1)][j - 1];
}

int RMQ(int p1, int p2)
{
  int k = 0;
  int len = p2 - p1 + 1;
  //k = log2 (p2 - p1 + 1);
  k = log(len*1.0)/log(2.0);
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

int main()
{
	int T = 0;
	scanf("%d", &T);
	while(T--)
	{
		int m=0;
        tot = 1;
        size = 1;
		scanf("%d %d", &n, &m);
		int x = 0, y = 0, value = 0;
        memset(heads,-1,sizeof(heads));
		for (int i = 0; i < n - 1; i ++)
		{
			scanf("%d %d %d", &x, &y, &value);
			addEdge(x, y, value);				
		}
		//printTree();
		//printList();
		memset(v, 0, sizeof(v));
		memset(pos, -1, sizeof(pos));
        memset(dis, 0, sizeof(dis));
		memset(dep, -1, sizeof(dep));
		memset(t, -1, sizeof(t));
        memset(dp,-1, sizeof(dp));

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

	}	
	return 0;
}
