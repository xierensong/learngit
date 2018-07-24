#include <iostream>
#include <cmath>
using namespace std;

int main()
{
        int N, A, B;
        int i,j,k,l,h;
        unsigned long long count = 0,tmp1 = 1,tmp2 = 1,tmp = 1;
        cin >> N >> A >> B;

        for (i = 1; i <= A; i ++)
        {
            tmp = tmp * (N - 1 +  i) / i;
            tmp1 += tmp;
            //cout << N+i-1 << '\t' << i << '\t' << "tmp1: " << tmp1 << endl;
        }
        tmp = 1;
        for (i = 1; i <= B; i ++)
        {
            tmp = tmp * (N - 1 + i) / i;
            tmp2 += tmp;
            //cout << N+i-1 << '\t' << '\t' << "tmp2: " << tmp2 << endl;
        }
        cout << tmp1 * tmp2 << endl;

        return 0;
}
