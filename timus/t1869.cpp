#include <iostream>
#include <cmath>

using namespace std;

int a[101][101];

int main()
{
        int n = 0;
        int i,j,k;
        int max = 0, cValue = 0, carNum = 0;

        cin >> n;
        for (i = 0; i < n; i ++)
                for (j = 0; j < n; j ++)
                {
                    cin >> a[i][j];
                }
        for (i = 0; i <= n - 2; i ++)
        {
                cValue = 0;
                for (j = 0; j <= i; j ++)
                {
                        for (k = i + 1; k <= n - 1; k ++)
                        { 
                                //cout << j << '\t' << k << '\t' << a[j][k] << endl;
                                    cValue += a[j][k];
                        }
                }
                //cout << i << '\t' << i + 1 << '\t' <<  "cValue: " << cValue << endl;
                if (cValue > max)
                        max = cValue;
        }
        
        for (i = 1; i <= n - 1; i ++)
        {
                cValue = 0;
                for (j = i; j <= n - 1; j ++)
                {
                        for (k = 0; k <= i - 1; k ++) 
                        {
                            //cout << j << '\t' << k << '\t' << a[j][k] << endl;
                            cValue += a[j][k];
                        }
                }
                //cout << i << '\t' << i - 1 << '\t' <<  "cValue: " << cValue << endl;
                if (cValue > max)
                        max = cValue;
        }
        
        carNum = (max % 36 == 0) ? (max / 36): (max / 36 + 1);
        cout << carNum << endl;
        return 0;
}
