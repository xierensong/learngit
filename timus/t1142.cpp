#include <iostream>

using namespace std;

int factor(int N)
{
    int result = 1;
    while (N)
    {
        result *= N;
        N--;
    }
    return result;
}

int main()
{
    int a[11][11];
    int N;
    int i, j;
    int number = 0;

    while (cin >> N)
    {
        if (N == -1)
            break;
        number = 0;
        for (i = 0; i <= N; i++)
            a[i][0] = 0;
        for (i = 0; i <= N; i++)
        {
           a[0][i] = 0; 
           //cout << a[0][i] << '\t';
        }    
        a[0][0] = 1;
        //cout << endl;
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                a[i][j] = a[i-1][j] * j + a[i-1][j-1];
                //cout << i << ' ' << j << ' ' << a[i-1][j] << ' ' << a[i-1][j-1] << ' ' << a[i][j] << '\t';
            }
            //cout << endl;
        }   
        for (i = 1; i <= N; i++)
        {
            number += a[N][i] * factor(i);           
        } 
        cout << number << endl;
    }

    return 0;
}
