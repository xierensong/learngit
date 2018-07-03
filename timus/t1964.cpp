#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, a, minNum;
    int k;
    int i;

    cin >> n >> k;
    minNum = n;
    for (i = 0; i < k; i ++)
    {
       cin >> a;
       minNum = min (minNum + a - n, minNum); 
       if (minNum <= 0)
       {
         minNum = 0;
         break; 
       } 
       //cout << i << '\t' << minNum << endl;
    }    
    cout << minNum << endl; 
    return 0;
}
