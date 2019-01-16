#include<iostream>

using namespace std;

int array[105][105];

int main()
{
  int n = 0;
    while(cin >> n)
    {
      array[1][0] = 0;
      for (int j = 1; j <= n; j ++)
      {
        array[1][j] = array[1][j - 1] + j;
        cout << array[1][j] << ' ';
      }
      cout << endl;
      for (int i = 2; i <= n; i ++)
      {
        for(int j = 1; j <= n - i + 1; j ++)
        {
            array[i][j] = array[i - 1][j] + i - 1 + j - 1;
            cout << array[i][j] << ' ';
        }

        cout << endl;
      }
    }
}
