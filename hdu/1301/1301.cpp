#include<iostream>

using namespace std;

int nodes[30];

typedef struct edgeType
{
  int node;
  int weight;
} edgeType;
//序号表示节点，每行数据表示节点相连的边
edgeType edges[30][20];

int main()
{
  int group = 0;
  while(cin >> group)
  {
    if (group == 0) break;
    for(int i = 1; i < group - 1; i++)
    {
      int node, edgeNum;
      cin >> node >> edgeNum;
      node = i;
      for (int j = 1; j < edgeNum; j++)
      {
        int out_node, fee;
        cin >> out_node >> fee;
        edgeType edge;
        edge.node = out_node - 'A' + 1;
        edge.weight = fee;
        edges[i][j] = edge;
      }
      for(int i = 1; i < group - 1; i++)
      {
        for (int j = 1; j < 
      }

    }
  }
  return 0;
}
