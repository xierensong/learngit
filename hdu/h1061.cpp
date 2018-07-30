#include <iostream>

using namespace std;

int modX (unsigned long long M, unsigned long long N)
{
    int S = 0;
    //cout << M << '\t' << N << endl;
    if (N == 1)
            return M % 10;
    S = modX (M, N / 2);
    if (N % 2 == 0) 
            return (S * S) % 10;
    else
            return (S * S * M) % 10;
}
int main()
{
        int T;

        cin >> T;
        while (T > 0)
        {
               unsigned long long N = 0;
               cin >> N;
               cout << modX (N, N) << endl;
               T--;
        }
        return 0;
}
