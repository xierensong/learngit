#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(char ch1, char ch2)
{
  if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'A' && ch2 <= 'Z')
    ch2 = ch2 + 'a' - 'A';
  if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'a' && ch2 <= 'z')
    ch1 = ch1 + 'a' - 'A';
  return ch1 < ch2;
}
int main()
{
  string str;
  vector<char> destStr;
  while(getline(cin,str))
  {
    int len = str.size();
    //cout << str << endl;
    destStr.clear();
    for (int i = 0; i < len; i++)
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        destStr.push_back(str[i]);
    }
    stable_sort(destStr.begin(), destStr.end(), cmp);
    //for (auto it = destStr.begin(); it != destStr.end(); it++)
      //cout << *it;
    //cout << endl;
    auto it = destStr.begin();
    for(int i = 0; i < len; i++)
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
      {
        cout << *it;
        it++;
      }
      else
          cout << str[i]; 
    }  
    cout << endl;
  }
  return 0;
}
