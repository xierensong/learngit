#include <iostream>
#include <iomanip>

using namespace std;

long double factor(int n, int m)
{
    int i;
    long double result = 1;
    for (i = n; i >= m; i --)
        result *= i;
    return result; 
}   

int main()
{
    int N; 
    int i;
    long double tmp, number = 0;

    cin >> N;
    for (i = 2; i <= N; i ++)
    {
        tmp = factor(N,N - i + 1);
        number += tmp;
        //cout << tmp << endl;
    }
    cout << setiosflags(ios::fixed) << setprecision(0) <<  number << endl;
    return 0;
}
