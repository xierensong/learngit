#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

typedef struct EmptyType
{
  int x; 
  int y;
}EmptyType;

typedef struct STValType
{
  int order;
  int value;
}STValType;

int plate[9][9]; //矩阵大小

stack<STValType> st; //栈，暂存可选值
vector<EmptyType> emptyList; // 搜索空间，待填的数

int len = 0;
int num = 0, ok = 0;

//输出矩阵
void printArray()
{
    for(int i = 0; i < 9; i ++)
    {
      for (int j = 0; j < 8; j ++)
        printf("%d ", plate[i][j]);
      printf("%d\n", plate[i][8]);
    }
    //printf("\n");
}

int valid(EmptyType pos, int value)
{
  int xx = pos.x;
  int yy = pos.y;
  
  //cout << "valid pos " << xx << '\t' << yy << endl;
  
  for(int i = 0; i < 9; i ++)
  {
    //cout << "valid " << plate[xx][i] << '\t' << plate[i][yy] << endl;
    //行列是否重复
   if (plate[xx][i] == value || plate[i][yy] == value) return 0;
  }
  int tmpx = (xx/3)*3, tmpy = (yy/3)*3;
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      if(plate[tmpx + i][tmpy + j] == value)
        return 0;
    }
  }
    return 1;
}

void dfs()
{

    int  len= emptyList.size();
    int i = 0;
    int j = 0;
    //cout << "进入深度遍历" << endl;
    while(i < len)
    {   
        //cout << "当前空位号:" << i << '\t' << len << endl;
        EmptyType curr = emptyList[i];
        int flag = 0; //当前是否填成功
        for (j = 1; j <= 9; j ++)
        {
          //cout << "筛选备选值" << '\t' << j << endl;
          if (valid(curr, j))
          {
            //cout << "有效的值:" << j << endl;
            STValType STval;
            STval.order = i;
            STval.value = j;
            st.push(STval);
            //cout << "栈长度:" << st.size() << endl;
            flag = 1;
          }
        }
        //cout << "flag:" << flag << endl;
        if (flag == 1)
        {
          //cout << "填充当前空位" << endl;
          if (!st.empty())
          {
            STValType STval = st.top();
            int xx = emptyList[STval.order].x;
            int yy = emptyList[STval.order].y;
            plate[xx][yy] = STval.value;
            //cout << "填充值: " << xx << '\t' << yy <<'\t'
              //<< plate[xx][yy] << endl;
            st.pop();
            //cout << "有备选值" << endl;
            //printArray();
          }
          i++; 
        }
        //回滚
        else
        {
          //cout << "回滚:" << endl;
          if (!st.empty())
          {
            STValType STval = st.top();
            st.pop();
            int xx = emptyList[STval.order].x;
            int yy = emptyList[STval.order].y;
            //cout << "无备选值:" << xx << '\t' << yy << endl;
            //栈顶序号比当前序号低一位
            if (STval.order == i - 1)
            {
              plate[xx][yy] = STval.value;
              //cout << "重设当前值" << endl;
              //printArray();
            }
            else
            {
              //清空所有的空位值
              int p = i - 1;
              while (p > STval.order)
              {
                int nxx = emptyList[p].x;
                int nyy = emptyList[p].y;
                plate[nxx][nyy] = 0;
                p --;
              }
              i = p + 1;
              //修改之前的空位值
              plate[xx][yy] = STval.value;
              //cout << "清空所有当前值，修改之前值" << endl;
              //printArray();
            }

          }
        }
    }
}

void DFS1(int cur)
{
  //cout << "进入DFS1 " << cur << '\t' << num << endl;
  if (cur == num)
  {
    printArray();
    ok = 1;
    return ;
  }
  else
  {
    for (int i = 1; i <= 9; i++)
    {
      if (valid(emptyList[cur], i) && !ok)
      {
        plate[emptyList[cur].x][emptyList[cur].y] = i;
        DFS1(cur+1);
        plate[emptyList[cur].x][emptyList[cur].y] = 0;
      }
    }
  }
  return;
}

int main()
{
  char ch;
  int i = 0, j = 0;
  int f = 0;
  //freopen("1.txt", "r", stdin);
  //freopen("2.txt", "w", stdout);
  //while(scanf("%c", &ch) !=EOF)
  while(cin >> ch)
  {
    if (ch >= '1' && ch <= '9')
    {
        plate[i][j] = ch - '0';
        j++;
    } 
    else if (ch == '?')
    {
        plate[i][j] = 0;
        EmptyType empty;
        empty.x = i;
        empty.y = j;
        emptyList.push_back(empty);
        j ++;
    }
    if (j == 9) 
    {
      j = 0;
      i++;
    }
    if (i == 9)
    {
        if (f != 0)
        {
          cout << endl;
        }
        f = 1;
        //重置i,j
        i = 0, j = 0;
        //cout << "输出矩阵" << endl;
        //printArray();
        //cout << "输出空元素列表" << endl;
        //for(auto it = emptyList.begin(); it != emptyList.end(); it++)
          //cout << it -> x << '\t' << it -> y << endl;
        num = emptyList.size();

        //dfs();
        ok = 0;
        DFS1(0);
        //cout << "深度遍历完成" <<endl;
        printArray();
        //收尾
        emptyList.clear(); //清空列表
        while(!st.empty())  st.pop(); //清空栈
    }
  }
  return 0;
}
