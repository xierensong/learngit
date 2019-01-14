#include<iostream>
#include<string>

using namespace std;

int main()
{
  int number = 0;
  string cmdStr;
  int curser = 0, current_list[4];
  while(cin >> number >> cmdStr)
  {
    //初始化
    for(int i = 0; i < 4; i ++)
      current_list[i] = i + 1;
    curser = 1;

    if (number <= 4 && number >= 1)
    {
        for (int i = 0; i < cmdStr.size(); i ++)
        {
          //cout << cmdStr[i] << endl;
          if (cmdStr[i] == 'U' && curser == 1)
          {
            curser = number;
          }
          else if (cmdStr[i] == 'D' && curser == number)
          {
            curser = 1;
          }
          else
          {
            if (cmdStr[i] == 'U') curser--;
            if (cmdStr[i] == 'D') curser++;
          }
        /*       
        //cout << curser << endl;
        for (int i = 0; i < number - 1; i ++) 
          cout << current_list[i] << ' ';
        cout << current_list[number - 1] << endl;
        cout << curser << endl;
        */
        }
	   for (int i = 0; i < number - 1; i ++) 
          cout << current_list[i] << ' ';
        cout << current_list[number - 1] << endl;
        cout << curser << endl;
    }
    else if (number > 4)
    {
      for (int i = 0; i < cmdStr.size(); i ++)
      {
        //cout << cmdStr[i] << endl;
        if (cmdStr[i] == 'U' && curser == 1)
        {
          for (int j = number, k = 3; j > number - 4, k >= 0; j--, k--)
          {
            current_list[k] = j; 
          }
          curser = number;
        }
        else if (cmdStr[i] == 'D' && curser == number)
        {
            for (int j = 0; j < 4; j ++)
              current_list[j] = j + 1;
            curser = 1;
        }
        else if (cmdStr[i] == 'U' && curser == current_list[0])
        {
            curser--;
            for(int j = 0, k = curser; j < 4, k < curser + 4; j ++, k ++)
            {
              current_list[j] = k;
            }
        }
        else if (cmdStr[i] == 'D' && curser == current_list[3])
        {
            curser++;
            for(int j = 3, k = curser; j >= 0, k > curser - 4; j --, k --)
            {
              current_list[j] = k;
            } 
        }
        else  
        {
          if (cmdStr[i] == 'U')
          {
            curser--;
          }
          if (cmdStr[i] == 'D')
          {
            curser++;
          }
        }
        }       
        for (int i = 0; i < 3; i ++)
          cout << current_list[i] << ' ';
        cout << current_list[3] << endl;
        cout << curser << endl;
    }
  }
  return 0;
}
