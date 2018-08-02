#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define ll long long
ll lastValue = -1e13;

ll calc(ll i, ll j)
{
        //ll value = 0;
        //value = i * i + 100000 * i + j * j - 100000 * j + i * j;
        //cout << "i j value: " << i << '\t' << j << '\t' << value << endl;
        //return value;
        return i * i + 100000 * i + j * j - 100000 * j + i * j;
}
ll sum (int N, ll keyValue)
{
        ll num = 0;
        ll i,j,start,end,mid,flag = 0;
        ll value = 0;
        lastValue = -1e13;
        for (j = 1; j <= N; j++)
        {
                //for (j = 1; j <= N; j++)
                //{
                        start = 1;
                        end = N;
                        flag = 0;
                        while (start <= end)
                        {
                           mid = (start + end) / 2;
                           //cout <<"=start end 0:= " <<  start << '\t' << end << endl;
                           //cout << "mid, j: " << mid << '\t' << j << endl; 
                           value = calc(mid,j);
                           //cout << " value midValue : " << value << '\t' << keyValue << endl;
                            if (value == keyValue)
                            {
                                    flag = 1;
                                   break; 
                            }
                            else if(value > keyValue)
                                    end = mid - 1;
                            else
                                    start = mid + 1;
                            //cout << "flag: " << flag << endl;
                            //cout << "=start end 1:= " << start <<  '\t' << end << endl;
                        }
                        ll add = 0;
                        if (flag == 0)
                            add = end;
                        else
                            add = mid;
                        num += add;
                        //cout << "num: " << num << endl;
                        /*
                        ll cValue =0;
                        if ( add != 0)
                        {
                            cValue = calc (add,j);
                            if (cValue > lastValue)
                                lastValue = cValue;
                        }*/
                        //cout << "lastValue: " << lastValue << endl;
                //}
        } 
        return num;
}

int main()
{
        int num = 0;
        cin >> num;
        int i = 0;
        for (i = 0; i < num; i ++)
        {
                int N;
                ll M;
                //cin >> N >> M;
                scanf("%d%lld", &N,&M);
                ll MIN = -1e13;
                ll MAX = 1e13;
                ll midValue = 0;
                ll currentM = 0;
                ll count = 0;
                /*
                for (int i = 1; i <= N; i ++)
                {
                        cout << endl;
                        for (int j = 1; j <= N; j ++)
                                cout << calc(i,j) << '\t';
                }
                cout << endl;
               */ 
                while (MIN <= MAX)
                {
                    midValue = (MIN + MAX) / 2;
                    currentM = sum(N, midValue);
                    //cout <<"currentM M : " << currentM << '\t' << M << endl;
                    //if (currentM == M)
                    //        break;
                    if (currentM < M)
                            MIN = midValue + 1;
                    else
                            MAX = midValue - 1;
                } 
                cout << MIN << endl; 
        }
        return 0;
}
