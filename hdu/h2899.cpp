#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

double calc(double x, double y)
{
        return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3) + 5 * pow(x,2) - y * x;
}

int main()
{
        int T;
        scanf("%d", &T);
        while(T--)
        {
                double X,Y;
                double low = 0, high = 100, mid1 = 0, mid2 = 0;
                scanf ("%lf", &Y);
                while ( high - low > 1e-10)
                {

                        mid1 = low + (high - low) / 3;
                        mid2 = high - (high - low) / 3;
                        /*cout << "low mid1 mid2 high0: " 
                                << low << '\t' 
                                << mid1 << '\t'
                                << mid2 << '\t'
                                << high << endl; 
                                */
                        if (calc(mid1, Y) > calc(mid2, Y))
                                low = mid1;
                        else
                                high = mid2;
                        /*
                        cout << "low mid1 mid2 high1: "
                                << low << '\t'
                                << mid1 << '\t'
                                << mid2 << '\t'
                                << high << endl;
                                */
                }
                //cout << "low: " << low << endl;
                cout << fixed << setprecision(4) << calc(low, Y) << endl;
                
        }
        return 0;
}
