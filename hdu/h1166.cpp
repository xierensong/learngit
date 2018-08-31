#include<iostream>
#include<cstdio>
#include <cstring>
using namespace std;

int array[50003];
int first[50003];
int N = 0;

//least significient bit
int lsb(int x)
{
    //if (x > 0)
        return x & (-x);
    //else
        //return 0;
}

void update(int i, int x)
{
    int ii = i;
    while (ii <= N)
    {
        first[ii] += x;
        ii += lsb(ii);
    }
}

int sum(int i)
{
   int total = 0;
   int ii = i;
   while (ii > 0)
   {
        total += first[ii];
        ii -= lsb(ii);
        //cout << "ii: " << ii << endl;
        //cout << "total: " << total << endl;
   }  

   return total;
}

int main()
{
    int T = 0;
    int No = 1;
    char queryStr[] = "Query";
    char endStr[] = "End";
    char addStr[] = "Add";
    char subStr[] = "Sub";

    scanf ("%d", &T);
    while (No <= T)
    {
        printf ("Case %d:\n", No); 
        No ++;
        scanf ("%d", &N);
        memset(first, 0, sizeof(first));

        for (int i = 1; i <= N; i ++)
        {
            scanf ("%d", &array[i]);
            update (i, array[i]);
            //cout << "first: " <<'\t' << i << '\t' << first[i] << endl;
        }
        char cmd[10] = "";
        while (1)
        {
        scanf ("%s", cmd);
        if (strcmp (cmd, queryStr) == 0)
        {
            int start = 0, end = 0;
            scanf ("%d%d", &start, &end);
            int sumStart = sum (start - 1);
            int sumEnd = sum (end);
            printf ("%d\n", sumEnd - sumStart);
        }
        else if (strcmp (cmd, addStr) == 0)
        {
            int pos = 0, value = 0;
            scanf ("%d%d", &pos, &value);
            update (pos, value);
        }
        else if (strcmp (cmd, subStr) == 0)
        {
            int pos = 0, value = 0;
            scanf ("%d%d", &pos, &value);
            update (pos, -1 * value);
        }
        else if (strcmp (cmd, endStr) == 0)
        {
            break;
        }
        }
        /*
        for (int i = 1; i <= N; i ++)
            cout << "first: " <<'\t' << i << '\t' << first[i] << endl;
        */
    }
    return 0;
}
