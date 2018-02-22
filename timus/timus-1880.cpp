// timus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>

using namespace std;

int main()
{
	int n = 0,i = 0,j = 0, k = 0;
	int a[3][4005] = { 0 };
	int count = 0;
	int iValue = 0, jValue = 0, kValue = 0;

	for (i = 0; i < 3; i++)
	{
		cin >> n;
		a[i][0] = n;
		for (j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}			
	}
/*	cout << endl;
	for (i = 1; i <= a[0][0]; i++)
	{
		cout << a[0][i] << '\t';
	}
	cout << endl;
	for (i = 1; i <= a[1][0]; i++)
	{
		cout << a[1][i] << '\t';
	}
	cout << endl;
	for (i = 1; i <= a[2][0]; i++)
	{
		cout << a[2][i] << '\t';
	}
	cout << endl;
*/
	i = 1;
	j = 1;
	k = 1;
	for (i = 1; i <= a[0][0]; i++)
	{
		iValue = a[0][i];
		cout << "the current i value:" << iValue << endl;
		while (a[1][j] < iValue && j < a[1][0])
		{
			j++;
		}
		if (a[1][j] == iValue)
		{
			j++;
			while (a[2][k] < iValue && k < a[2][0])
				k++;
			if (a[2][k] == iValue)
				count++;
		}
		cout << "the current j value: " << a[1][j] << endl;
		cout << "the current k value: " << a[2][j] << endl;
		cout << "the eigenvalue number: " << count << endl;

	}
	cout << count << endl;
    return 0;
}

