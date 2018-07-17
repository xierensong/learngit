#include <iostream>

using namespace std;

int main()
{
        int dp[56];
        int N = 0, i = 0;

        cin >> N;
        if (N == 1 || N == 2)
                cout << 1 << endl;
        else
        {
                dp[1] = 1;
                dp[2] = 1;
                dp[3] = 2;
                for (i = 4; i <= N; i ++)
                {
                        dp[i] = dp [i - 1] + dp [i - 3] + 1;
                } 
                cout << dp[N] << endl;
        }
        return 0;
}
