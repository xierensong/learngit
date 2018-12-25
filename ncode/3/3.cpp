#include<iostream>
#include<string>

using namespace std;

int main()
{
  int x, y;
  string tmpStr, subStr;
  x = 0;
  y = 0;
  while(getline(cin, subStr, ';')) 
  {
    //cout << subStr << endl;
    int sz = subStr.size();
    int step = 0;
    int flag = 0;
    if (sz == 2)
    {
      if (subStr[1] >= '0' && subStr[1] <= '9')
        step = subStr[1] - '0';
      else
        flag = 1;
    }
    else if (sz == 3)
    {
      if (subStr[1] >= '0' && subStr[1] <= '9' && subStr[2] >= '0' && subStr[2] <= '9')
        step = (subStr[1] - '0') * 10 + subStr[2] - '0';
      else
        flag = 1;
    }
    else
    {
      flag = 1;
    }

    if (flag == 0)
    {
        if (subStr[0] == 'A')
        {
          x -= step;
        }
        else if (subStr[0] == 'S')
        {
          y -= step;
        }
        else if (subStr[0] == 'W')
        {
          y += step;
        }
        else if (subStr[0] == 'D')
        {
          x += step;
        }
    }
    //cout << x << ' ' << y << endl;
  }
  cout << x << ',' << y << endl;
  return 0;
}
