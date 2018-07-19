#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int l,h,w, tmp2;
    double g = 9.81;
    double dropT, leftT, quatNum, tmp, Pos, angPerT;

    cin >> l >> h >> w;
    if (l / 2 >= h)
    {
            cout << "butter" << endl;
            return 0;
    }
    dropT = sqrt (((2 * h - l) * 0.01) / g);
    //cout << "drop time: " << dropT << endl;

    angPerT = (60 * 1.0) / w;
    //cout << "per revolution's time: " << angPerT << endl;

    quatNum = floor (dropT / angPerT);
    //cout << "quater Num: " << quatNum << endl;
    Pos = dropT -  quatNum * angPerT;
    //cout << "pos: " << Pos << endl;
    tmp = Pos / angPerT ;
    //cout << "tmp: " << tmp << endl;
    if ((tmp < 0.25 && tmp >= 0) || (tmp > 0.75 && tmp < 1))
            cout << "butter" << endl;
    else
            cout << "bread" << endl;
    return 0;
}
