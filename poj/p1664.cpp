#include <iostream>

using namespace std;
int count (int M, int N)
{
        int tmp = 0;
        if (M == 0)
        {
                //cout <<"1: " << M << '\t' << N << 1 << endl;
                return 1;
        }
        if (N == 1)
        {
                //cout <<"2: " <<M << '\t' << N << '\t' << N << endl;
                return N;
        }
        if (M < N)
        {
                tmp = count (M,M); 
                //cout <<"3: " <<  M << '\t' << tmp << endl;
                return tmp;
        }
        if (M >= N)
        {
                tmp = count (M, N - 1) + count (M - N, N);
                //cout <<"4: " <<  M << '\t' << N << '\t' << tmp << endl;
                return tmp;
        }
}
int main()
{
        int t = 0;
        cin >> t;
        while (t > 0)
        {
                int M, N, K;
                cin >> M >> N;
                K = count (M, N);
                cout << K << endl;
                t --;
        }
        return 0;
}
