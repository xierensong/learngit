#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef struct POS
{
  int x;
  int y;
} POS;


int * calc_num(int ** array, int col)
{
}

vector<POS> * calc_pos(int ** array, int col)
{
}

int dfs(int ** array)
{
  vector<POS> posList;
  vector<int> numList;
  
  // 遍历每一列
  for(int i = 0; i < 9; i++)
  {
    numList = calc_num(i);
    posList = calc_pos(i);  
    lenNum = numList.size();
    lenPos = posList.size();
    // 候选数字和候选位置数量不等，失败
    if (lenNum != lenPos)
      return 0;
    // 候选数字和候选位置数量相等，都为0，成功
    else if (lenNum == 0 && lenPos == 0)
      continue;
    // 候选数字和候选位置数量相等，不为0，遍历候选数字和位置
    for (vector<POS>::iterator it = posList.begin();
            it < posList.end(); it++)
        for (vector<int>::iterator num_it = numList.begin();
               num_it < numList.end(); num_it++)
        {
            int x = it -> x;
            int y = it -> y;
            int num = (*num_it);
            array[x][y] = num;
            // 如果dfs结果为1,说明当前候选数字可用
            if (dfs(array))
            {
                //删除成功插入的候选位置信息
                posList.erase(it);
                //删除成功插入的候选数字信息
                numList.erase(num_it);
                //不再遍历后面的数字
                break;

            }

        } 
  }
}
int main()
{

  int array[9][9];
  int nList[9];
  POS pos[9];

  while(1)
  {
    char c;
    int i = 0, j = 0;
    for (i = 0; i < 9; i ++)
      for (j = 0; j < 9; j ++)
      {
        scanf("%c", &c); 
        if (c <= '9' && c >= '1')
            array[i][j] = c - '0';
        else
            array[i][j] = 0;
      }
  }
  return 0;
}
