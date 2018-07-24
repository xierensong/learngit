#include <iostream>

using namespace std;

int gcd (int a, int b)
{
        if (b == 0)
                return a;
        return gcd (b, a % b);
}
int main()
{
        int a, b;
        while (cin >> a >> b)
        {
                int c = 0;
                c = gcd(a,b);
                //cout << c << endl;
                cout << a * b / c << endl;
        }
}
