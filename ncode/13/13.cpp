#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<char,int> a1, pair<char,int> a2) 
{
  return a1.second < a2.second;
}

int main()
{
  string str;
  while(cin >> str)
  {
  map<char,int> charCount;
  vector<pair<char,int>> charVec;

  int len = str.size();
  for (int i = 0; i < len; i ++)
  {
    char a = str[i];
    charCount[a]++;
  }
  for (auto it = charCount.begin(); it != charCount.end(); it++)
  {
    charVec.push_back(pair<char,int>(it->first, it->second));
  }
  sort(charVec.begin(), charVec.end(), cmp);
  string destStr;
  destStr = str;
  int max = 0;
  for (auto it = charVec.begin(); it != charVec.end();it++)
  {
    //cout << it -> first << '\t' << it -> second << endl;
    //cout << "max:" << max << endl;
    if (max == 0)
      max = it -> second;
    if ((it -> second) > max)
      break;
    char del = it -> first;
    int pos = destStr.find_first_of(del);
    while(pos != -1)
    {
      destStr.erase(pos, 1);
      pos = destStr.find_first_of(del);
    }
    //cout << it -> first << '\t' << it -> second << endl;
  }
  cout << destStr << endl;
  }
  return 0;
}
