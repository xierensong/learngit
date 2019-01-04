#include<iostream>
#include<string>

using namespace std;

int main()
{
  string source = "",dest = "";
  while(cin >> source)
  {
    int len = source.size();
    for(int i = 0; i < len; i++)
    {
      char cur = source[i], curD;
      if (cur >= 'A' && cur <= 'Z')
      {
        curD = (cur < 'Z') ? (cur + 1 + 32) : 'a';
      }
      else if (cur >= '0' && cur <= '9')
      {
        curD = cur;
      }
      else if (cur >= 'a' && cur <= 'z')
      {
       if (cur >= 'a' && cur <= 'c')
        curD = '2';
       else if (cur >= 'd' && cur <= 'f')
        curD = '3';
       else if (cur >= 'g' && cur <= 'i')
        curD = '4';
       else if (cur >= 'j' && cur <= 'l')
        curD = '5';
       else if (cur >= 'm' && cur <= 'o')
        curD = '6';
       else if (cur >= 'p' && cur <= 's')
        curD = '7';
       else if (cur >= 't' && cur <= 'v')
        curD = '8';
       else if ( cur >= 'w' && cur <= 'z')
        curD = '9'; 
      }

      dest.push_back(curD);
    }
    cout << dest << endl;
  }
  return 0;
}
