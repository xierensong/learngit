#include <iostream>
#include <iomanip>

using namespace std;

int main()
{   
    double a1, a2, a3;
    double tmp1, tmp2;

    cin >> a1 >> a2 >> a3;
    tmp1 = 1000 * a1 * a2 * a3;   
    tmp2 = a1 * a2 + a2 * a3 + a3 * a1;
    cout <<fixed << setprecision(0) <<  tmp1 /tmp2 << endl; 
    
    return 0;
}
