#include <stdio.h>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 10004

int del[10];
int n = 0, m = 0;
int visited[MAX];
int pre[MAX];
char text[MAX];


int bfs()
{
    int yu = 0, current = 0;
    queue<int> thisQueue;

    thisQueue.push(0);

    while(!thisQueue.empty())
    {
        current = thisQueue.front();
        thisQueue.pop();

        for(int i = 0; i < 10; i ++)
        {
          if (del[i] == 1 || i == 0 && current == 0)
            continue;
          yu = (current * 10 + i) % n;
          if (visited[yu])
             continue;
          text[yu] = '0' + i;
          pre[yu] = current; 
          thisQueue.push(yu);
          visited[yu] = 1;
          if (yu == 0)
           return 1; 
        }
    }
    return 0;
}

void printAns()
{
    string ans; 
    int p = 0;
    while (p != 0 || ans.empty())   
    {
     ans += text[p];
     p = pre[p];
    }
    reverse (ans.begin(), ans.end());
    puts(ans.c_str());
}
int main()
{
  int caseNo = 0;

  while(scanf ("%d%d", &n, &m) != EOF)
  {
    memset(del,0,sizeof(del));
    memset(visited,0,sizeof(visited));
    while (m--)
    {
        int num = 0;
        scanf ("%d", &num);
        del[num] = 1;
    }

    printf("Case %d: ", ++caseNo);
    if (bfs())
        printAns();
    else
        printf("%d\n", -1); 
  } 
  return 0;
}
