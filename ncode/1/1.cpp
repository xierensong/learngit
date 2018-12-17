#include <iostream>

using namespace std;

int main()
{
  int number;
  int outnumber = 0;
  int a[50];
  for(int i = 0; i < 50; i++)
    a[i] = 0;
  cin >> number;
  while (number != 0)
  {
    int value = number % 10;
    if (a[value] == 0)
    {
        outnumber = outnumber * 10 + value;
        a[value] ++;
    }
    number = number / 10;
  }
  cout << outnumber << endl;
  return 0;
}
