#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
        int h,t,v,x;
        double min = 0, max = 0;

        cin >> h >> t >> v >> x;
        min = ((h - x * t) * 1.0) / (v - x);
        min = (min < 0) ? 0 : min;
        max = (h / t < x) ? (h * 1.0) / x : t * 1.0;
        cout << fixed << setprecision(6) << min << ' ' << max << endl;
        return 0;
}
