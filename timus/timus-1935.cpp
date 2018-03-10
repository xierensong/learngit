// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>


using namespace std;

int skins[101];

int main()
{
	int n;
	int i = 0;
	int sum = 0, max = 0;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> skins[i];
	}

	for (i = 1; i <= n; i++)
	{
		sum += skins[i];
		if (skins[i] > max)
		{
			max = skins[i];
		}
	}
	cout << sum + max << endl;
    return 0;
}

