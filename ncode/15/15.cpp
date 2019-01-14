#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

bool cmp(pair<char,int> p1, pair<char, int> p2)
{
  //数量不同
  if (p1.second != p2.second)
    return p1.second > p2.second;
  else
    return p1.first < p2.first;

}

int main()
{
  string line;
  map<char,int> charCount;
  vector<pair<char, int>> charVec;
  while(getline(cin, line))
  {
    charCount.clear();
    charVec.clear();
    int len = line.size();
    for (int i = 0; i < len; i ++)
    {
      char curChar = line[i];
      if ((curChar >= 'a' && curChar <= 'z') || (curChar >= 'A' && curChar <= 'Z')
          || (curChar >= '0' && curChar <= '9') || curChar == ' ')
      charCount[curChar]++;
    }
    for(auto it = charCount.begin(); it != charCount.end(); it++)
    {
      charVec.push_back(pair<char,int>(it->first, it->second));
    }
    sort(charVec.begin(), charVec.end(), cmp);
    for(auto it = charVec.begin(); it != charVec.end(); it++)
    {
      cout << it->first;
    }
    cout << endl;
  }
  return 0;
}
