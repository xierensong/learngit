#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
int comp(int a, int b)
{
        int result = 0;
        result = a < b ? 1: 0;
        return result;
}
int main()
{
        int C = 0;
        int i = 0;
        cin >> C;
        for (i = 0; i < C; i++)
        {
                int n,V,W;

                cin >> n >> V >> W;

                int p[105];
                int j = 0;
                for (j = 1; j <= n; j++)
                {
                        cin >> p[j];
                }
                sort(p + 1, p + n + 1, comp);
                //for (j = 1; j <= n; j++)
                //        cout << p[j] << '\t';
                //cout << endl;

                int k = 0;
                int pSum = 0;
                while (k < n)
                {
                        //cout << pSum + p[k+1] << endl;
                        //cout << W * (k+1) << endl;
                        if (pSum + p[k+1] <= W * (k+1))
                        {
                                k++;
                                pSum += p[k];
                        }
                        else
                                break;
                }
                cout << k * V << ' ';
                if (k == 0)
                        cout << fixed << setprecision(2) << k / 1.0 << endl;
                else
                        cout << fixed << setprecision(2) << (pSum * 0.01) / k << endl;
        }
        return 0;
}
