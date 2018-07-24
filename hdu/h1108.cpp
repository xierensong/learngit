#include <iostream>

using namespace std;

int main()
{
        int a = 0, b = 0, a1 = 0, b1 = 0;
        while (cin >> a >> b)
        {
                int c = 0, tmp = 0;
                a1 = a;
                b1 = b;
                while (a % b != 0)
                {
                        tmp = a % b;
                        a = b;
                        b = tmp;
                }
                //cout << b << endl;
                cout << a1 * b1 / b << endl;

        }
        return 0;
}
