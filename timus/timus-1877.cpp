// timus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0;
	while (cin >> a >> b)
	{
		if (a % 2 == 0)
			cout << "yes" << endl;
		else if (b % 2 == 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}

    return 0;
}

