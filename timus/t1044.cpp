#include <iostream>

using namespace std;

int main()
{
    int num = 0;
    long int a[4] = {10,670,55252,4816030};
    cin >> num;
    cout << a[num / 2 - 1] << endl;
    return 0;
}
