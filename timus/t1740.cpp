#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int l,k,h;
    float min_t = 0.0, max_t = 0.0;

    cin >> l >> k >> h;
    max_t = (l % k == 0) ? (l / k) : (l / k + 1);
    max_t = max_t * h;
    min_t = l / k * h;
    cout << setiosflags(ios::fixed) << setprecision (6)  
           << min_t << ' ' << max_t << endl;
    return 0;
}
