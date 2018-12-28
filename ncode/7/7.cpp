#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int toInt(string ip)
{
  long value = 0;
  int pos = 0;
  int start = 0;
  int i = 3;
  pos = ip.find_first_of('.');
  while(pos != -1)
  {
    string a1 = ip.substr(start, pos - start);
    int num = stoi(a1);
    value += num * (pow(2, 8 * i));
    i --;
    //cout << num << endl;
    start = pos + 1;
    //cout << "start:" << start << endl;
    pos = ip.find_first_of('.', start); 
  }
  //处理最后一个字符串
  int len = ip.size();
  string a2 = ip.substr(start, len - start);
  int num1 = stoi(a2);
  //cout << num1 << endl;
  value += num1;
  return value;

}

void toAddress(string ip)
{
    int value = 0;
    value = stoi(ip);
    int i = 3;
    while(i)
    {
        int tt = pow(2, i * 8);
        int num = value / tt;
        cout << num << '.';
        value = value % tt;
        i--;
    }
    cout << value << endl;

}

int main()
{
  string ip;
  while(cin >> ip)
  {
    int pos = ip.find_first_of('.');
    if (pos != -1)
    {
      int result = toInt(ip);
      cout << result << endl;
    }
    else
    {
      toAddress(ip);
    }
  }
  return 0;
}
