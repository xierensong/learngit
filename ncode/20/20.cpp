#include<iostream>

using namespace std;

int gcd(int m, int n)
{
    int tmp = 0;
    //不能整除
    while(m % n != 0)
    {
        tmp = m % n;
        //除数作为被除数
        m = n;
        //商作为除数
        n = tmp;
    }
    //返回商
    return n;
}

int main()
{
  int m,n;
  while(cin >> m >> n)
  {
    int tmp;
    tmp = gcd(n,m);
    cout << m * n / tmp << endl;
  }
  return 0;
}
