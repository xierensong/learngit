#include<iostream>

using namespace std;

int main()
{
  int x = 0, f = 0, d = 0, p = 0;
  while(cin >> x >> f >> d >> p)
  {
    int money = f * p + d;
    int day = money / (x + p);
    if (day < f)
    {
      cout << d / x << endl;
    }
    else
    {
      cout << day << endl; 
    }
  }
  return 0;
}
