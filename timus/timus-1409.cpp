// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0;
	while (cin >> a >> b)
	{

		cout << a + b - 1 - a << endl;
		cout << a + b - 1 - b << endl;
	}

	return 0;
}

