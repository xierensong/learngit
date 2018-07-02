#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int a[100001];

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int N;
    int K;
    int i = 0;
    string str = "";
    int order = 0;
 
    cin >> N;
    for (i = 1; i <= N; i ++)
    {
       cin >> a[i]; 
    }
    sort(a+1, a+N+1, cmp); 
    /*for ( i = 1; i <= N; i ++)
    {
        cout << a[i] << endl;
    }
    */
    cin >> str; 
    if ( str == "###" )
    {
        cin >> K;
        for (i = 1; i <= K; i ++)
        {
            cin >>  order;
            cout << a[order] << endl;
        } 
    }
    cin >> K;
    return 0;
}
