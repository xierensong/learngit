#include<iostream>
#include<string>

using namespace std;

int checkLen(string line)
{
  if (line.size() > 8)
    return 1;
  else
    return 0;
}

int checkType(string line)
{
  int num = 0, big = 0, small = 0, other = 0;
  int len = line.size();
  for (int i = 0; i < len; i ++)
  {
    if (line[i] >= '0' && line[i] <= '9')
    {
      num++;
    }
    else if (line[i] >= 'a' && line[i] <= 'z')
    {
      small++;
    }
    else if (line[i] >= 'A' && line[i] <= 'Z')
    {
      big++;
    }
    else
    {
      other++;
    }
  }
  //cout << num << '\t' << small << '\t' << big << '\t' << other << endl;
  if (num == 0 && small > 0 && big > 0 && other > 0) return 1;
  if (num > 0 && small == 0 && big > 0 && other > 0) return 1;
  if (num > 0 && small > 0 && big == 0 && other > 0) return 1;
  if (num > 0 && small > 0 && big > 0 && other == 0) return 1;
  if (num > 0 && small > 0 && big > 0 && other > 0) return 1;
  return 0;
}

int checkSub(string line)
{
  int len = line.size();
  int first = 0, last = first + 3;
  if (len <= 5)
    return 1;
  while(first + 2 < len)
  {
    last = first + 3;
    while(last + 2 < len)
    {
        string sub1 = line.substr(first, 3);
        string sub2 = line.substr(last, 3);
        //cout << sub1 << '\t' << sub2 << endl;
        if(sub1 == sub2)
          return 0;
        last++;
    }
    first++;
  }

  return 1;
}

int main()
{
  string line;
  while(cin >> line)
  {
    if(checkLen(line) && checkType(line) && checkSub(line))
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
