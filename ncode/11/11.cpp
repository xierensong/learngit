#include<iostream>

using namespace std;

int main()
{
  int n = 0;
  while(cin >> n)
  {
    if (n == 0)
      break;
    int bottle = 0;
    int cur_bottle = n, cur_left = 0;
    while(cur_bottle / 3 != 0)
    {
      cur_left = cur_bottle % 3;
       cur_bottle = cur_bottle / 3;
       bottle += cur_bottle;
       //cout << "loop:" << bottle << endl;
       cur_bottle += cur_left;       
       //cout << " cur bottle:" << cur_bottle << endl;
    }
    if (cur_bottle % 3 == 2)
      bottle++;
    cout << bottle << endl;
  }
  return 0;
}
