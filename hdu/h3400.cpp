#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct
{
   double x;
   double y;
} POINT;

POINT A, B, C, D;
int P, Q, R;
double eps = 1e-9;
double dis(POINT s, POINT t)
{
        return sqrt (pow (t.y -s.y,2) + pow (t.x - s.x,2));
}

double calc1(POINT s, POINT m, POINT t)
{
        /*
        cout << "s m t: "
             << "s: " << s.x << '\t' << s.y << '\t'
             << "m: " << m.x << '\t' << m.y << '\t'
             << "t: " << t.x << '\t' << t.y << '\t'
             << endl;
             */
    return dis (s,m) / R + dis (m,t) / Q;
}

double calc(POINT E)
{
    POINT low,high,mid1,mid2;
    double d;
    double T1=1, T2=0;
    low.x = C.x; low.y = C.y;
    high.x = D.x; high.y = D.y;
    d = dis (low, high);
    //cout << "d: " << d << endl;
    //while (d >= eps)
    while (fabs(T1-T2) >= eps)
    {
        /*
        mid1.x = low.x + (high.x - low.x) / 3;
        mid1.y = low.y + (high.y - low.y) / 3;
        mid2.x = high.x - (high.x - low.x) / 3;
        mid2.y = high.y - (high.y - low.y) / 3;
        */
        mid1.x = (high.x + low.x) / 2;
        mid1.y = (high.y + low.y) / 2;
        mid2.x = (mid1.x + high.x) / 2;
        mid2.y = (mid1.y + high.y) / 2;
        /*
        cout << "=00= "
             <<"low: " << low.x << '\t' << low.y << "\t\t"
             << "mid1: " << mid1.x << '\t' << mid1.y << "\t\t"
             << "mid2: " << mid2.x << '\t' << mid2.y << "\t\t"
             << "high: " << high.x << '\t' << high.y << endl;
             */
        T1 = calc1(E, mid1, D);
        T2 = calc1(E, mid2, D); 
        /*
        cout << "T1T1: " << T1 << '\t' 
                 << "T2T2: " << T2 << endl;
                 */
        if (T1 < T2)
        {
                high.x = mid2.x;
                high.y = mid2.y;
        }
        else
        {
                low.x = mid1.x;
                low.y = mid1.y;
        }
        /*
        cout << "=11= "
             << "low: " << low.x << '\t' << low.y << "\t\t"
             << "mid1: " << mid1.x << '\t' << mid1.y << "\t\t"
             << "mid2: " << mid2.x << '\t' << mid2.y << "\t\t"
             << "high: " << high.x << '\t' << high.y << endl;
             */
        d = dis (low,high);
        /*
        cout << "low: " << low.x << '\t' << low.y
                << "high: " << high.x << '\t' << high.y << endl;
        cout << "d0: " << d << endl;*/
    }
    /*
    cout << "T1T1T1: " << T1 << endl;
    */
    //return T1;
    return T1>T2?T2:T1;
}
int main()
{
        int T;
        scanf("%d",&T);
        while(T--)
        {
            scanf ("%lf%lf%lf%lf%lf%lf%lf%lf",
                            &A.x, &A.y, &B.x, &B.y,
                            &C.x, &C.y, &D.x, &D.y);
            scanf ("%d%d%d",&P,&Q,&R);
            
            POINT low,high,mid1,mid2;
            double T1=0, T2=1, T1_23, T2_23;
            low.x = A.x; low.y = A.y;
            high.x = B.x; high.y = B.y;
            double d = dis (low, high);
            //cout << "d: " << d << endl;
            //while (d >= eps)
            while(fabs(T1-T2) >= eps)
            {
               /*
               mid1.x = low.x + (high.x - low.x) / 3;
               mid1.y = low.y + (high.y - low.y) / 3;
               mid2.x = high.x - (high.x - low.x) / 3;
               mid2.y = high.y - (high.y - low.y) / 3; 
               */
               mid1.x = (high.x + low.x) / 2;
               mid1.y = (high.y + low.y) / 2;
               mid2.x = (mid1.x + high.x) / 2;
               mid2.y = (mid1.y + high.y) / 2;
               /*
               cout << "=0= "
                    <<"low: " << low.x << '\t' << low.y << "\t\t"
                    << "mid1: " << mid1.x << '\t' << mid1.y << "\t\t"
                    << "mid2: " << mid2.x << '\t' << mid2.y << "\t\t"
                    << "high: " << high.x << '\t' << high.y << endl;
                    */
               T1_23 = calc (mid1);
               T1 = dis (A, mid1) / P + T1_23;
               /*
               cout << "-=- "
                    << "mid1: " << mid1.x << '\t' << mid1.y << '\t'
                    << dis (A,mid1) << '\t' << T1_23 << endl;
                */
               T2_23 = calc (mid2);
               T2 = dis (A, mid2) / P + T2_23;
               /*
               cout << "T1: " << T1 << '\t' 
                       << "T2: " << T2 << endl;
                       */
               if (T1 < T2)
               {
                       high.x = mid2.x;
                       high.y = mid2.y;
               }
               else
               {
                       low.x = mid1.x;
                       low.y = mid1.y;
               } 
               /*
               cout << "=1= "
                    << "low: " << low.x << '\t' << low.y << "\t\t"
                    << "mid1: " << mid1.x << '\t' << mid1.y << "\t\t"
                    << "mid2: " << mid2.x << '\t' << mid2.y << "\t\t"
                    << "high: " << high.x << '\t' << high.y << endl;
                    */
               d = dis (low, high);
            }
            cout << fixed << setprecision(2) << T1 << endl;
        }
        return 0;
}
