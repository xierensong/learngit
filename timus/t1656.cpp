#include <iostream>
#include <algorithm>

using namespace std;
int compare(int a, int b)
{
        int result = (a > b) ? 1 : 0;
        return result;
}
int main()
{
        int n = 0;
        int soldiers[82], square[10][10];
        int i = 0, j = 0, center = 0, k, l;

        cin >> n;
        for (i = 0; i < n * n; i ++)
        {
                cin >> soldiers[i];
        }
        sort(soldiers, soldiers + n * n, compare);
/*        for (i = 0; i < n * n; i ++)
                cout << soldiers[i] << '\t';
*/ 
        center = n / 2;
        square[center][center] = soldiers[0];
        j = 1;
        for (i = 1; i < n; i ++)
        {
                //cout << endl;
            //右
            //square[center][center + i] = soldiers[j];
            for (k = center, l = center + i; k > center - i && l > center; k--,l--)
            {    
                    //cout << k << '\t' << l << endl;       
                    if ( k >= 0 && k < n && l >= 0 && l < n)
                    {
                        square[k][l] = soldiers[j];
                        j++;
                        //cout << j << '\t' << square[k][l]  << endl;
                    }
            }
            //上
            //square[center - i][center] = soldiers[j];
            //j++;
            for (k = center -i, l = center; k < center && l > center -i; k++,l--)
            {
                    //cout << k << '\t' << l << endl;
                    if ( k >= 0 && k < n && l >= 0 && l < n)
                    {
                           square[k][l] = soldiers[j];
                           j++;
                           //cout << j << '\t' << square[k][l] << endl;
                    }
            }
            //左
            //square[center][center - i] = soldiers[j];
            //j++;
            for (k = center, l = center -i; k < center +i && l < center; k++,l++)
            {
                    //cout << k << '\t' << l << endl;
               if ( k >= 0 && k < n && l >= 0 && l < n)
               {
                      square[k][l] = soldiers[j];
                      j++;
                      //cout << j << '\t' << square[k][l] << endl;
               }
            }
            //下
            //square[center + i][center] = soldiers[j];
            //j++;
            for (k = center + i, l = center; k > center && l < center + i; k--, l++)
            {
                    //cout << k << '\t' << l << endl;
                    if ( k >= 0 && k < n && l >= 0 && l < n)
                    {
                        square[k][l] = soldiers[j];
                        j++;
                        //cout << j << '\t' << square[k][l] << endl;
                    }
            }
            
            /*
            square[center + i][center - i] = soldiers[j];
            j++;
            square[center - i][center - i] = soldiers[j];
            j++;
            square[center - i][center + i] = soldiers[j];
            j++;
            square[center + i][center + i] = soldiers[j];
            j++;
            */
        }
        for (i = 0; i < n; i++)
        {
                for (j = 0; j < n; j++)
                        cout << square[i][j] << '\t';
                cout << endl;
        }
        return 0;
}
