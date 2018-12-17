#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

typedef struct POS
{
  int x;
  int y;
} POS;

int array[9][9];
/*
int array[9][9] = {{7,1,2,0,6,0,3,5,8},
                   {0,6,5,2,0,7,1,0,4},
                   {0,0,8,5,1,3,6,7,2},
                   {9,2,4,0,5,6,0,3,7},
                   {5,0,6,0,0,0,2,4,1},
                   {1,0,3,7,2,0,9,0,5},
                   {0,0,1,9,7,5,4,8,6},
                   {6,0,7,8,3,0,5,1,9},
                   {8,5,9,0,4,0,0,2,3}};
*/
vector<int> calc_num(int col)
{
  vector<int> numList;
  int i = 0;
  int a[10];
  //初始化a数组
  for(int i = 0; i < 9; i ++)
    a[i] = 0;
  //已有的数字设置为1
  for(int i = 0; i < 9; i ++)
  {
    int index = array[i][col];
    if (index != 0)
        a[index - 1] = 1;
  }
/*
  for (int i = 0; i < 9; i ++)
  {
    cout << i << '\t' << a[i] << endl;
  }
*/
  //未设置为1的下标是候选数字
  for(int i = 0; i < 9; i ++)
  {
    if (a[i] == 0)
        numList.push_back(i + 1);
  }
  //cout << "num list:" << endl;
  /*
  for(vector<int>::iterator it = numList.begin();
        it < numList.end(); it++)
    cout << (*it) << '\t';
  cout << endl;
  */
  return numList;
}

vector<POS>  calc_pos(int col)
{
  vector<POS> posList;
  POS pos_item;
  pos_item.x = 1;
  pos_item.y = 2;
  int i = 0;
  for (int i = 0; i < 9; i ++)
    if (array[i][col] == 0)
    {
        pos_item.x = i;
        pos_item.y = col;
        posList.push_back(pos_item);
    }
  //cout << "pos list:" << endl;
  /*
  for (vector<POS>::iterator it = posList.begin();
        it < posList.end(); it++)
    cout << it -> x << '\t' << it -> y << endl;
  */
  return posList;
}

void print()
{
  int i,j;
  for (i = 0; i < 9; i ++) 
  {   
     //cout << endl;
     for (j = 0; j < 9; j ++) 
     {   
        //cout << array[i][j] << ' ';
        printf("%d ", array[i][j]);
     }   
     //cout << endl;
     printf("\n");
  }
}

int check(int x, int y)
{
  int value = 0;
  int result = 0;
  value = array[x][y];
  //cout << "enter check" << endl;
  //cout << x << '\t' << y << '\t' << value << endl;
  //检查行是否有重复
  //cout << "== check row==" << endl;
  for(int j = 0; j < 9; j ++)
  {
    if (array[x][j] == value && j != y)
      return 0;
  }
  //检查局部是否有重复
  int tmpx = (x/3)*3, tmpy=(y/3)*3;
  for(int i = tmpx; (i < tmpx + 3) && (i != x); ++i)
  {
    for (int j = tmpy; j < (tmpy + 3) && (j != y); ++j)
    {
        if (array[i][j] == value)
          return 0;
    }
  }
  return 1;
}

int dfs()
{
  vector<POS> posList;
  vector<int> numList;
  int lenNum, lenPos;  
  //cout << "start dfs" << endl;
  //print();
  // 遍历每一列
  for(int i = 0; i < 9; i++)
  {
    //cout << "colomn number: " << i << endl;
    numList = calc_num(i);
    posList = calc_pos(i);  

    //lenNum = numList.size();
    //lenPos = posList.size();
    // 候选数字和候选位置数量不等，失败
    //if (lenNum != lenPos)
    //  return 0;
    // 候选数字和候选位置数量相等，都为0，成功
    //else if (lenNum == 0 && lenPos == 0)
    //  continue;
    // 候选数字和候选位置数量相等，不为0，遍历候选数字和位置
    for (vector<POS>::iterator it = posList.begin();
            it < posList.end(); it++)
    {
        int flag = 0;
        //cout << "current postion" << endl;
        int x = it -> x;
        int y = it -> y;
        //遍历候选数字
        for (vector<int>::iterator num_it = numList.begin();
               num_it < numList.end(); num_it++)
        {
            int num = (*num_it);
            /*
            cout << "x y array[x][y]" << '\t' << x
                << '\t' << y << '\t' << num << endl;
            */
            array[x][y] = num;
            // 如果dfs结果为1,说明当前候选数字可用
            if (check(x,y))
            {
                //cout << "check success!" << endl;
                //遍历后面的空位
                if (dfs())
                { 
                  //设置成功标志
                  flag = 1;
                  //不再遍历后面的数字
                  break;
                }
                else
                {
                  //cout << "left dfs fail,rollback!" << endl;
                  array[x][y] = 0;
                  //print(); 
                   
                }
            }
            //check结果不为1，说明候选数字不可用
            else
            {
                //cout << "check fail,rollback" << endl;
                //回滚设置的值
                array[x][y] = 0;
                //print();
            }
        }
        //如果没有填入正确值
        if (flag == 0)
        {
            //返回失败
            return 0;
        }
        //print();
    } 
  }
  //cout << "end dfs" << endl;
  return 1;
}

int main()
{
 
  while(1)
  {
    char c, d;
    int i = 0, j = 0;
    
    for (i = 0; i < 9; i ++)
    {
      for (j = 0; j < 9; j ++)
      {
        scanf("%c%c", &c, &d); 
        if (c <= '9' && c >= '1')
            array[i][j] = c - '0';
        else if (c == '?')
            array[i][j] = 0;
      }
    }
    

    if (dfs())
    {
      print();
      //cout << "成功" << endl;
    }
    /*
    else
    {
      cout << "失败" << endl;
    }
    */
  }
  return 0;
}
