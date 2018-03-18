// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	long X,Y,C;
	long i;


	cin >> X >> Y >> C;
	if (X + Y < C)
		cout << "Impossible" << endl;
	else
	{
		for (i = 0; i <= X; i++)
		{
			if (C - i <= Y && C - i >= 0)
			{
				cout << i << ' ' << C - i << endl;
				break;
			}
		}
	}
	


    return 0;
}

