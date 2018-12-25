#include<iostream>

using namespace std;

int main()
{
    int m = 0;
    while(cin >> m)
    {
      int a = 1, b = 0, c = 0;
    while(--m)
    {
        c = c + b;
        b = a;
        a = c;
        //cout << a << '\t' << b << '\t' << c << endl;
    }
    cout << a + b + c << endl;
    }
    return 0;
}
