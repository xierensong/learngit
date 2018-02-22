// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>

using namespace std;

int main()
{
	int a = 0, n = 0;
	int i = 0, b = 0, sum =0;
	while (cin >> a >> n)
	{
		sum = 0;
		if (n > 0)
		{
			for (i = 0; i < n; i++)
			{
				cin >> b;  //current added cars
				sum += b;  //current total cars
				if (a > sum)  //if total cars lower than permitted cars, then no cars
					sum = 0;  
				else   //else minus permitted cars will be the left cars.
					sum -= a;
			}
			cout << sum << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}

    return 0;
}

