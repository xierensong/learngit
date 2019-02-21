#include <iostream>
#include <vector>
const int maxdist = 9999;
using namespace std;
/*n是总的结点数,v是出发结点,dist是距离,pre前一个结点,d是结点间的权值*/
void Dijkstra(int n, int v, vector<int> &dist, vector<int> &pre, vector<vector<int>> &d)
{
    vector<bool> s(n+1);
    for (int i = 1; i <= n;i++)
    {
        dist[i] = d[v][i];
        if (dist[i] < maxdist)
            pre[i] = v;
        else
            pre[i] = 0;
    }
    dist[v] = 0;
    s[v] = true;
    for (int i = 2; i <= n;i++)//总的迭代次数
    {
        int best = v;
        int temp = maxdist;
        for (int j = 1; j <= n;j++)//找到最小的距离
        {
            if (!s[j]&&dist[j]<temp)
            {
                temp = dist[j];
                best = j;
            }
        }
        s[best] = true;
        for (int j = 1; j <= n;j++)//更新dist和pre
        {
            if (!s[j] && d[best][j] != maxdist)
            {
                int newdist = dist[best] + d[best][j];
                if (newdist<dist[j])
                {
                    dist[j] = newdist;
                    pre[j] = best;
                }
            }
        }       
    }
}

void printpath(vector<int> pre, int init, int fina)
{
    int temp=fina;
    vector<int> t;
    while (temp != init)
    {
        t.push_back(temp);
        temp = pre[fina];
        fina = temp;
    }
    cout << init << "->";
    for (int i = t.size(); i >1;i--)
    {
        cout << t[i-1] << "->";
    }
    cout << t[0];
    t.clear();
}
int main()
{
    int n, l, start, end;
    cin >> n >> l >> start >> end;
    vector<vector<int>> d(n+1, vector<int>(n+1));
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n; j++)
            d[i][j] = maxdist;
    }
    int p, q, len;
    for (int i = 1; i <= l; ++i)
    {
        cin >> p >> q >> len;
        if (len < d[p][q])       // 有重边
        {
            d[p][q] = len;      // p指向q
        }
    }
    vector<int> dist(n+1),pre(n+1);
    for (int i = 1; i <= n; ++i)
        dist[i] = maxdist;
    Dijkstra(n, start, dist, pre, d);
    int go = dist[end];
    Dijkstra(n, end, dist, pre, d);
    int come = dist[start];
    cout << go + come << endl;
    //cout << "点start到点end的最短路径长度: " << dist[end] << endl;
    //cout << "点1到点n的路径为: ";
    //printpath(pre, start, end);
    return 0;
}
