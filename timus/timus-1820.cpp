// timus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <iostream>

using namespace std;

int main()
{
	int k = 0, n = 0;

	while (cin >> n >> k)
	{
		if (n > k)
			cout << ceil(n * 2 / (k * 1.0)) << endl;
		else
			cout << 2 << endl;
	}

    return 0;
}

