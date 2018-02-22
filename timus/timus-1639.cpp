// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>

using namespace std;

int main()
{
	int n = 0, m = 0;
	int i = 0;
	while (cin >> m >> n)
	{
		if (m * n % 2)
			cout << "[second]=:]" << endl;
		else
			cout << "[:=[first]" << endl;
	}

    return 0;
}

