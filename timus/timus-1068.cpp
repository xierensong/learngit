// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
#include <algorithm>


using namespace std;


int main()
{
	int n = 0;
	int i = 0;
	int length = 0;

	cin >> n;
	if (n < 1)
	{
		length = 2 - n;
	}
	else if (n == 1)
	{
		length = 1;
	}
	else
	{
		length = n;
	}

	cout << (1 + n) * length / 2 << endl;

    return 0;
}

