#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;

#define MAX 1e10;
typedef struct
{
        double x;
        double y;
} POINT;

POINT points1[100005],points2[100005];

int compX(POINT P1, POINT P2)
{
    //2
    /*
    if (P1.x > P2.x)
            return 0;
    else
            return 1;
            */
        return P1.x < P2.x;
}

int compY(POINT P1, POINT P2)
{
        //3
        /*
        if (P1.y > P2.y)
                return 0;
        else
                return 1;
                */
        return P1.y < P2.y;
}

double calc (int m, int n)
{
        double d = 0;
        int i, j, tail = 0;
        //cout << "m  n: " << m << '\t' << n << endl;
        if (m == n)
        {
                d = MAX;
                //cout << "d: " << d << endl;
                return d;
        }
        else
        {
            int mid = (m + n) / 2;
            //cout << "m mid n: " << m << '\t' << mid << '\t' << n << endl;
            d = min (calc (m, mid), calc (mid+1, n));
            //[mid-d, mid + d]中所有点
            for ( i = mid; i >= m && points1[mid].x - points1[i].x < d; i --)
            {
                    //cout << "1!" << endl;
                    points2[tail] = points1[i];
                    tail++;
            } 
            for (i = mid + 1; i <= n && points1[i].x - points1[mid].x < d; i ++)
            {
                    //cout << "2!" << endl;
                    points2[tail] = points1[i];
                    tail ++;
            }
            //cout << "tail: " << tail << endl;
            if (tail < 2)
                    return d;
            sort (points2, points2 + tail, compY);
            //for (i = 0; i < tail; i ++)
                    //cout << points2[i].x << '\t' 
                     //       << points2[i].y << endl;
            for (i = 0; i < tail; i ++)
                    for (j = i + 1; j < tail && points2[j].y - points2[i].y < d; j ++)
                    {
                            d = min (d, 
                                 sqrt(pow(points2[j].y - points2[i].y,2) +
                                     pow(points2[j].x - points2[i].x, 2)));
                      //      cout << "d: " << d << endl;
                    }
            return d;
        }
        
            
}
int main()
{
        int N = 0;
        while (cin >> N)
        {
            if (N == 0)
                    break;

            int i = 0;
            for (i = 0; i < N; i ++)
            {
                    //1
                    //cin >> points1[i].x >> points1[i].y;
                    scanf("%lf%lf", &points1[i].x, &points1[i].y);
            }
            sort(points1, points1 + N, compX);
            double d = 0;
            d = calc(0, N - 1);
            cout << fixed << setprecision(2) << d  / 2 << endl;
        }
        return 0;
}
