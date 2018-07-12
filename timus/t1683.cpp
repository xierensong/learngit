#include <iostream>
#include <cmath>

using namespace std;

int main()
{
        long long n;
        int count = 0;
        cin >> n;
        count = log(n) / log(2);
        if (pow(2, count) < n)
                count ++ ;
        cout << count << endl;
        long m;
        while (n / 2 != 0)
        {
            m = (n % 2  == 0) ? n / 2 : (n + 1) / 2; 
            cout << m << ' ';
            n = m;
        }
        cout << endl;
        return 0;
}
