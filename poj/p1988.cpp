#include <iostream>
#include <cstdio>
using namespace std;
int parent[30005];
int cnt[30005];
int up[30005];

void init()
{
    for (int i = 1; i < 30006; i ++)
    { 
        parent[i] = i;
        cnt[i] = 1;
        up[i] = 0;
    }
}

int findP(int i)
{
    int pi = parent[i];
    if (parent[i] != i)
    {
        pi = findP(parent[i]);
        up[i] += up[parent[i]];
    }
    parent[i] = pi;
    return pi;
}
void move(int i, int j)
{
    int pi = findP(i), pj = findP(j);
    parent[pj] = pi;;
    up[pj] += cnt[pi]; //更新j祖先的up值
    cnt[pi] += cnt[pj]; //更新i祖先的cnt值
}

int checkSum(int i)
{
    int pi = findP(i);
    int num = 0;
    num = cnt[pi] - up[i] - 1;
    return num;
}

void print()
{
    for (int i = 1; i <= 10; i ++)
        cout << parent[i] << '\t';
    cout << endl;
    for (int i = 1; i <= 10; i ++)
        cout << cnt[i] << '\t';
    cout << endl;
    for (int i = 1; i <= 10; i ++)
        cout << up[i] << '\t';
    cout << endl;
}
int main()
{
    int P = 0;
    scanf ("%d", &P);
    init();
    while(P--)
    {
        char a[3];
        int i,j;
        scanf("%s", a);  // 1
        if (a[0] == 'M')
        {
            scanf ("%d %d", &i, &j);
            move(i,j);
            //print();
        }
        else if (a[0] == 'C')
        {
            int i = 0;
            scanf ("%d", &i);
            int num = checkSum(i);
            cout << num << endl;
        }
    }
    return 0;
}
