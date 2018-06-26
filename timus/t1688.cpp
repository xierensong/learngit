#include <iostream>

using namespace std;

int main()
{
    long long n = 0;
    int m = 0;
    long fee = 0;
    long long total = 0;
    int count = 0;
    int flag = 0;
 
    cin >> n >> m;
    
    if (m == 0)
    {
        cout << "Team.GOV!" << endl;
        return 0;
    }
    while (cin >> fee)    
    {
        total += fee;
        if (total <= n * 3)
            count ++;
        else
        {
            flag = 1;
            break;
        }         
    }
    if (flag == 1)
        cout << "Free after " << count + 1 << " times." << endl;
    else
        cout << "Team.GOV!" << endl;
    return 0;
}
