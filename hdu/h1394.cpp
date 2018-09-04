#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX 5003

int a[MAX], tree[MAX];
int n = 0;

int lsb (int x)
{
    return x & (-x);
}

void update (int i, int value)
{
    while (i <= n)
    {
        tree[i] += value;
        i += lsb(i);
    }

}

int sum (int i)
{
    int total = 0;
    while (i >= 1)
    {
        total += tree[i];
        i -= lsb(i);
    }
    return total;
}
int main()
{
    int num = 0;
    //scanf ("%d", &num);
    //while (num--)
    //{
    while (~scanf ("%d", &n))
    {
        memset (tree, 0, sizeof(tree));
        /*
        for (int i = 1; i <= n; i ++)
            cout << tree[i] << '\t';
        cout << endl;
        */
        /*
        for (int i = 1; i <= n; i ++)
            cout << tree[i] << endl;
        */
        int Inum = 0, cValue = 0;
        for (int i = 1; i <= n; i ++)
        {
            scanf ("%d", &a[i]);
            cValue = sum (a[i]);
            //cout << "sum: " << '\t' << a[i] << '\t' << cValue << endl;
            Inum += i - 1 - cValue;
            update(a[i] + 1, 1);
            //cout << "Inum: " << Inum << endl;
            //cout << " tree: " << '\t' << a[i] + 1 << '\t' << tree[a[i] + 1] << endl;
        }
        int min = Inum;
        for (int i = 1; i <= n - 1; i ++)
        {
           Inum += n - 1 - a[i];
           Inum -= a[i];
           //cout << " Inum: " << Inum << endl; 
           if (min > Inum)
              min = Inum;
           //cout << "min: " << min << endl; 
        }
        cout << min << endl;
    }
    return 0;
}

