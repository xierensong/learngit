#include <iostream>

using namespace std;

int main()
{
        double  potValue = 0, remainValue = 0, currentValue = 0;
        int chargePercentage = 0;
        int i = 0;

        cin >> potValue >> remainValue >> chargePercentage;
        currentValue = potValue;
        while (currentValue > remainValue)
        {
            i ++;
            currentValue = currentValue * (1 - chargePercentage * 0.01);
            //cout <<"i: " << i <<  "current value: " << currentValue << endl;
        }
        cout << i << endl;
        return 0;
}
