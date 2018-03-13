#include <iostream>

using namespace std;

double CalFactorSum (long long N)
{
        long long Sum = 0;
        long long  i = 0;
        //cout << "N:" << N << endl;
        for (i = 2; i * i <= N; i++)
        {
                if (N % i == 0)
                {
                        Sum += i;
                        if ((N / i) != i)
                                Sum += (N / i);
                }
                //cout << "Sum:" << Sum << endl;
        }
        return Sum; 
}
int main()
{
        long long I, J;
        long long N, currentN;
        double triviality = 0x3f3f3f3f * 1.0, currentTriviality = 0;
        long long k = 0;
        double factorSum = 0;

        cin >> I >> J;

        if (I == 1)
        {
                cout << 1 << endl;
                return 0;
        }
        for ( k = J; k >= I; k--)
        {
                currentN = k;
                //cout << "currentN:" << currentN << endl;
                factorSum = CalFactorSum (currentN);
                //cout << "factorSum:" <<  factorSum << endl;
                currentTriviality = (factorSum * 1.0) / currentN;
                if (factorSum / currentN < triviality)
                {
                        triviality = factorSum / currentN;
                        N = currentN;
                }
                if (triviality == 0) break;
        }
        cout << N << endl;
        return 0;
}